#pragma once

#include <vector>
#include <memory>
#include <string>

enum class NodeType {
    Program,
    NumericLiteral,
    Identifier,
    VariableDeclaration,
    BinaryExpression,
    AssignmentExpression,
    Property,
    ObjectLiteral
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

struct VariableDeclaration : public Statement {
    bool constant;
    std::string identifier;
    Expression value;

    VariableDeclaration() {
        kind = NodeType::VariableDeclaration;
    }
};

struct AssignmentExpression : public Expression {
    Expression assignee;
    Expression value;

    AssignmentExpression() {
        kind = NodeType::AssignmentExpression;
    }
};

struct BinaryExpression : public Expression {
    Expression left;
    Expression right;

    std::string _operator;

    BinaryExpression() {
        kind = NodeType::BinaryExpression;
    }
};

struct Property : public Expression {
    std::string key;
    Expression value;

    Property() {
        kind = NodeType::Property;
    }
};

struct ObjectLiteral : public Expression {
    std::vector<Property> properties;

    ObjectLiteral() {
        kind = NodeType::ObjectLiteral;
    }
};