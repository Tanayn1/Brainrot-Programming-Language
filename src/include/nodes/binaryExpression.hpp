#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H
#include "ASTNode.hpp"
#include <iostream>

class BinaryExpression : public Node 
{

public:

    Node left;
    Node right;
    std::string binaryOperator;

    BinaryExpression(Node l, Node r, std::string op) : 
    left(l), 
    right(r), 
    binaryOperator(op) 
    {
        type = NodeType::BINARY_EXPRESSION;
    }

    std::string print() override 
    {
        std::string printStatement = "Operator: " + binaryOperator;
                                      
        return printStatement;
    }
    
};

#endif