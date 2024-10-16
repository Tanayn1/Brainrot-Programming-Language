#ifndef BINARY_EXPRESSION_H
#define BINARY_EXPRESSION_H
#include "ASTNode.hpp"
#include <iostream>

class BinaryExpression : Node 
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
    
};

#endif