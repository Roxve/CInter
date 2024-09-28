#pragma once

#include <vector>
#include <memory>
#include <string>
#include <string_view>

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
    std::vector<std::unique_ptr<Statement>> body;

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
    std::unique_ptr<Expression> value;

    VariableDeclaration() {
        kind = NodeType::VariableDeclaration;
    }
};

struct AssignmentExpression : public Expression {
    std::unique_ptr<Expression> assignee;
    std::unique_ptr<Expression> value;

    AssignmentExpression() {
        kind = NodeType::AssignmentExpression;
    }
};

struct BinaryExpression : public Expression {
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    std::string _operator;

    BinaryExpression() {
        kind = NodeType::BinaryExpression;
    }
};

struct Property : public Expression {
    std::string key;
    std::unique_ptr<Expression> value;

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
