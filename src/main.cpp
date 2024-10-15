#include <iostream>
#include <fstream>
#include <sstream>
#include "./include/lexer.hpp"
#include "./include/token.hpp"

int main() {
    std::ifstream file("test.skibidi"); // Open the file

    if (!file) { 
        std::cerr << "Error: could not open the file." << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf(); 


    std::vector<Token> tokens = tokenise(buffer.str());

    for (int i = 0; i < tokens.size(); i++)
    {
       std::cout << tokens[i].type << " " << tokens[i].value << std::endl;
    }
    

    file.close(); 

    return 0;
}