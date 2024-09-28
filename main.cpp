// main.cpp

#include <iostream>
#include "core/includes/lexer.hpp"

int main() {
    std::string sourceCode = "let x = (5 + 10);";

    std::vector<Token> tokens = Tokenize(sourceCode);

    for (const auto& token : tokens) 
        std::cout << "Token Type: " << token.type << ", Value: " << token.value << std::endl;
    

    std::cin.get();

    return 0;
}
