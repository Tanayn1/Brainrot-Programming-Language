#ifndef NUMERIC_LITERAL_H
#define NUMERIC_LITERAL_H
#include "ASTNode.hpp"

class NumericLiteral : Node 
{
public:
    int number;

    NumericLiteral(int num) : number(num)
    {
        type = NodeType::NUMERIC_LITERAL;
    }
};

#endif