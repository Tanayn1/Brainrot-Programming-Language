#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H
#include "ASTNode.hpp"
#include <iostream>

class BinaryExpression : public Node 
{

public:

    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
    std::string binaryOperator;

    BinaryExpression(std::unique_ptr<Node> l, std::unique_ptr<Node> r, std::string op) : 
    left(std::move(l)), 
    right(std::move(r)), 
    binaryOperator(op) 
    {
        type = NodeType::BINARY_EXPRESSION;
    }

    std::string print() override 
    {
        std::string printStatement = "Operator: " + binaryOperator + ", left: " + left->print() + ", right: " + right->print();                             
        return printStatement;
    }
    
};

#endif