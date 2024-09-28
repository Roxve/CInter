#pragma once

#include <vector>
#include <memory>
#include <string>

enum class NodeType {
    Program,
    NumericLiteral,
    Identifier,
};

struct Statement {
    NodeType kind;

    virtual ~Statement() noexcept = default; 
};

struct Program : public Statement {
    std::vector<Statement*> body;

    Program() {
        kind = NodeType::Program; 
    }

    ~Program() noexcept override = default; 
};

struct Expression : public Statement {};

struct Identifier : public Expression {
    std::string symbol;

    Identifier() {
        kind = NodeType::Identifier;
    }
};

struct NumericLiteral : public Expression {
    int value;

    NumericLiteral() {
        kind = NodeType::NumericLiteral;
    }
};