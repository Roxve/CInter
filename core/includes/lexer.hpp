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