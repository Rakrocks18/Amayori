#include <fstream>      //file operation
#include <iostream>     //standard input output
#include <optional>     //We have options: mentioned option or NULL
#include <sstream>      //stringstream for string operation. Interface between file and string
#include <vector>       //stl vector

#include "generation.hpp"

int main(int argc, char* argv[])        //if file is passed, argc = 2 and argv[1] contains the address of the file to be compiled
{
    if (argc != 2) {    // amayori <file.aym>, if file.aym has been passed and the number of command line invocation parameter is 2
        std::cerr << "Incorrect usage. Correct usage is..." << std::endl;
        std::cerr << "amayori <file_name.aym>" << std::endl;        //returns subsequent error
        return EXIT_FAILURE;
    }

    std::string contents;       //string for contents within file
    {                           //cannot directly extract from a file to string. Need to use stringstream
        std::stringstream contents_stream;          //file extraction stringstream. file content[code] -> stringstream -> string
        std::fstream input(argv[1], std::ios::in);      //fstream input, open file in input. in: file -> stringstream. out: stringstream -> file
        contents_stream << input.rdbuf();       //inbuilt function for reading entire file
        contents = contents_stream.str();       //stringstream to string
    }

    Tokenizer tokenizer(std::move(contents));
    std::vector<Token> tokens = tokenizer.tokenize();       //creates tokens

    Parser parser(std::move(tokens));                       //parser
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