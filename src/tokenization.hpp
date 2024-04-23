#pragma once

#include <string>
#include <vector>
#include <optional>

enum class TokenType {
    exit,       //return
    int_lit,    //int
    semi,       //;
    open_paren, //(
    close_paren,//)
    ident,      //variable
    let,        //declaration
    eq,         //=
    plus,       //+
    star,       //-
    minus,      //-
    fslash,     // /
    open_curly, // {
    close_curly,// }
    if_,        // if
    elif,       // elif
    else_,      // else
};

inline std::string to_string(const TokenType type)
{
    switch (type) {
        case TokenType::exit:
            return "`return`";
        case TokenType::int_lit:
            return "int literal";
        case TokenType::semi:
            return "`;`";
        case TokenType::open_paren:
            return "`(`";
        case TokenType::close_paren:
            return "`)`";
        case TokenType::ident:
            return "identifier";
        case TokenType::let:
            return "`let`";
        case TokenType::eq:
            return "`=`";
        case TokenType::plus:
            return "`+`";
        case TokenType::star:
            return "`*`";
        case TokenType::minus:
            return "`-`";
        case TokenType::fslash:
            return "`/`";
        case TokenType::open_curly:
            return "`{`";
        case TokenType::close_curly:
            return "`}`";
        case TokenType::if_:
            return "`if`";
        case TokenType::elif:
            return "`elif`";
        case TokenType::else_:
            return "`else`";
    }
    assert(false);      //throws error when an unidentified type is passed
}

inline std::optional<int> bin_prec(const TokenType type)        //operation precedence
{
    switch (type) {
        case TokenType::minus:
            return 0;
        case TokenType::plus:
            return 1;
        case TokenType::fslash:
            return 3;
        case TokenType::star:
            return 2;
        default:
            return {};          //NULL
    }
}

struct Token {
    TokenType type;     //int, if, elif,
    int line;           //error handling
    std::optional<std::string> value {};        //int = 'value'
};

class Tokenizer {
public:
    explicit Tokenizer(std::string src)     //constructor where src is code
            : m_src(std::move(src))         //m_src is a data member of Tokenizer, and we move code to m_src
    {
    }

    std::vector<Token> tokenize()           //list of tokens within the code
    {
        std::vector<Token> tokens;          //vector initialization
        std::string buf;                    //string to read multi-character token
        int line_count = 1;
        while (peek().has_value()) {        //until we reach the end of code
            if (std::isalpha(peek().value())) {         //if it is an alphabet: keyword or identifier
                buf.push_back(consume());               //move cursor forward by 1
                while (peek().has_value() && std::isalnum(peek().value())) {    //checks whether it is an alphabet or number
                    buf.push_back(consume());                                //if it encounters whitespace, exit the loop
                }
                if (buf == "return") {      //check for return keyword
                    tokens.push_back({ TokenType::exit, line_count });
                    buf.clear();
                }
                else if (buf == "let") {    //check for let keyword
                    tokens.push_back({ TokenType::let, line_count });
                    buf.clear();
                }
                else if (buf == "if") {     //check for if keyword
                    tokens.push_back({ TokenType::if_, line_count });
                    buf.clear();
                }
                else if (buf == "elif") {   //checks for elif
                    tokens.push_back({ TokenType::elif, line_count });
                    buf.clear();
                }
                else if (buf == "else") {   //check for else keyword
                    tokens.push_back({ TokenType::else_, line_count });
                    buf.clear();
                }
                else {                      //if none of above, then identifier
                    tokens.push_back({ TokenType::ident, line_count, buf });        //value because identifier has a name(value)
                    buf.clear();
                }
            }
            else if (std::isdigit(peek().value())) {
                buf.push_back(consume());
                while (peek().has_value() && std::isdigit(peek().value())) {        //checks if there are succeeding numbers
                    buf.push_back(consume());
                }
                tokens.push_back({ TokenType::int_lit, line_count, buf });          //value here is literally the integer value
                buf.clear();
            }
            else if (peek().value() == '/' && peek(1).has_value() && peek(1).value() == '/') {      //single line comment
                consume();      //returning something, not being stored, but no error
                consume();
                while (peek().has_value() && peek().value() != '\n') {
                    consume();
                }
            }
            else if (peek().value() == '/' && peek(1).has_value() && peek(1).value() == '*') {      //multi-line comment
                consume();
                consume();
                while (peek().has_value()) {
                    if (peek().value() == '*' && peek(1).has_value() && peek(1).value() == '/') {
                        break;
                    }
                    consume();
                }
                if (peek().has_value()) {
                    consume();
                }
                if (peek().has_value()) {
                    consume();
                }
            }
            else if (peek().value() == '(') {
                consume();
                tokens.push_back({ TokenType::open_paren, line_count });
            }
            else if (peek().value() == ')') {
                consume();
                tokens.push_back({ TokenType::close_paren, line_count });
            }
            else if (peek().value() == ';') {
                consume();
                tokens.push_back({ TokenType::semi, line_count });
            }
            else if (peek().value() == '=') {
                consume();
                tokens.push_back({ TokenType::eq, line_count });
            }
            else if (peek().value() == '+') {
                consume();
                tokens.push_back({ TokenType::plus, line_count });
            }
            else if (peek().value() == '*') {
                consume();
                tokens.push_back({ TokenType::star, line_count });
            }
            else if (peek().value() == '-') {
                consume();
                tokens.push_back({ TokenType::minus, line_count });
            }
            else if (peek().value() == '/') {
                consume();
                tokens.push_back({ TokenType::fslash, line_count });
            }
            else if (peek().value() == '{') {
                consume();
                tokens.push_back({ TokenType::open_curly, line_count });
            }
            else if (peek().value() == '}') {
                consume();
                tokens.push_back({ TokenType::close_curly, line_count });
            }
            else if (peek().value() == '\n') {
                consume();
                line_count++;
            }
            else if (std::isspace(peek().value())) {
                consume();
            }
            else {
                std::cerr << "Invalid token" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        m_index = 0;
        return tokens;
    }

private:
    [[nodiscard]] std::optional<char> peek(const size_t offset = 0) const       //reads character at cursor location, and the return value has to be used without fail
    {
        if (m_index + offset >= m_src.length()) {
            return {};
        }
        return m_src.at(m_index + offset);
    }

    char consume()          //return character at cursor and then move the cursor forward by 1
    {
        return m_src.at(m_index++);
    }

    const std::string m_src;
    size_t m_index = 0;
};