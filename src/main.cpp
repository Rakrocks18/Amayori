#include <fstream>      //file operation
#include <iostream>     //standard input output
#include <optional>     //We have options: mentioned option or NULL
#include <sstream>      //stringstream for string operration
#include <vector>       //stl vector

#include "generation.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2) {    // amayori <file.aym>, if file.aym has been passed
        std::cerr << "Incorrect usage. Correct usage is..." << std::endl;
        std::cerr << "amayori <file_name.aym>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string contents;
    {
        std::stringstream contents_stream;
        std::fstream input(argv[1], std::ios::in);
        contents_stream << input.rdbuf();
        contents = contents_stream.str();
    }

    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();

    Parser parser(std::move(tokens));
    std::optional<NodeProg> prog = parser.parse_prog();

    if (!prog.has_value()) {
        std::cerr << "Invalid program" << std::endl;
        exit(EXIT_FAILURE);
    }

    {
        Generator generator(prog.value());
        std::fstream file("out.asm", std::ios::out);
        file << generator.gen_prog();
    }

    system("nasm -felf64 out.asm");
    system("ld -o out out.o");

    return EXIT_SUCCESS;
}