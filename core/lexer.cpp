// lexer.cpp

#include "lexer.hpp"

Token createToken(const std::string &value, TokenType type)
{
    return { value, type };
}

bool isAlpha(const std::string& src) {
    for (char ch : src) {
        if (!std::isalpha(static_cast<unsigned char>(ch))) 
            return false;
    }
    return true;
}

bool isSkippable(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
}

bool isInt(char ch) {
    return std::isdigit(static_cast<unsigned char>(ch)); 
}

std::vector<Token> Tokenize(const std::string& sourceCode) {
    std::vector<Token> tokens;
    std::vector<char> src(sourceCode.begin(), sourceCode.end());

    while (!src.empty()) {
        if (src[0] == '(') {
            tokens.push_back(createToken(std::string(1, src[0]), TokenType::OpenParen));
            src.erase(src.begin());
        }
        else if (src[0] == ')') {
            tokens.push_back(createToken(std::string(1, src[0]), TokenType::CloseParen));
            src.erase(src.begin());
        }
        else if (src[0] == '+' || src[0] == '-' || src[0] == '*' || src[0] == '/' || src[0] == '%') {
            tokens.push_back(createToken(std::string(1, src[0]), TokenType::BinaryOperator));
            src.erase(src.begin());
        }
        else if (src[0] == '=') {
            tokens.push_back(createToken(std::string(1, src[0]), TokenType::Equals));
            src.erase(src.begin());
        }
        else if (src[0] == ';') {
            tokens.push_back(createToken(std::string(1, src[0]), TokenType::Semicolon));
            src.erase(src.begin());
        }
        else if (src[0] == ':') {
            tokens.push_back(createToken(std::string(1, src[0]), TokenType::Colon));
            src.erase(src.begin());
        }
        else if (src[0] == ',') {
            tokens.push_back(createToken(std::string(1, src[0]), TokenType::Comma));
            src.erase(src.begin());
        }
        else {
            if (isInt(src[0])) {
                std::string num;
                while (!src.empty() && isInt(src[0])) {
                    num += src[0];
                    src.erase(src.begin());
                }
                tokens.push_back(createToken(num, TokenType::Number));
            }
            else if (isalpha(src[0])) {
                std::string ident;
                while (!src.empty() && isalpha(src[0])) {
                    ident += src[0];
                    src.erase(src.begin());
                }

                if (KEYWORDS.find(ident) != KEYWORDS.end()) {
                    tokens.push_back(createToken(ident, KEYWORDS.at(ident))); 
                } 
                else {
                    tokens.push_back(createToken(ident, TokenType::Identifier));
                }
            }
            else if (isSkippable(src[0])) {
                src.erase(src.begin());
            }
            else {
                std::cerr << "Unrecognized character found in source: " << static_cast<int>(src[0]) << " (" << src[0] << ")" << std::endl;
                exit(1);  
            }
        }
    }

    tokens.push_back({ "EndOfFile", TokenType::_EOF });

    return tokens;
}