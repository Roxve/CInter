#pragma once;

#include <string>
#include <map>

enum TokenType {
    Integer,
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

const std::map<std::string, TokenType> KEYWORDS {
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