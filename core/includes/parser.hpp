#pragma once

#include "lexer.hpp"
#include "ast.hpp"

class Parser {
    private:
        std::vector<Token> tokens = {};

        bool not_EOF() const;
        Token at() const;
        Token eat();
        Token expect(TokenType type, std::string& err);

    public:
        Program produceAST(std::string& sourceCode);
        
};