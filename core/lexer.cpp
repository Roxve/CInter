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