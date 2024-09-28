// lexer.hpp

#pragma once;

#include <string>
#include <unordered_map>
#include <vector>
#include <cctype> 
#include <iostream>

enum TokenType {
    Number,
    Identifier,
    Let,
    Const,
    BinaryOperator,
    Equals,
    Comma,
    Colon,
    Semicolon,
    OpenParen,
    CloseParen,
    _EOF,
};

const std::unordered_map<std::string, TokenType> KEYWORDS {
    { "let", TokenType::Let },
    { "const", TokenType::Const }
};

struct Token {
    std::string value;
    TokenType type;
};

Token createToken(const std::string& value = "", TokenType type);
bool isAlpha(const std::string& src);
bool isSkippable(char ch);
bool isInt(char ch);
std::vector<Token> Tokenize(const std::string& sourceCode);