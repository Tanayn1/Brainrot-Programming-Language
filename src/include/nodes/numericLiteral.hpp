#ifndef NUMERIC_LITERAL_H
#define NUMERIC_LITERAL_H
#include "ASTNode.hpp"

class NumericLiteral : public Node 
{
public:
    int number;

    NumericLiteral(int num) : number(num)
    {
        type = NodeType::NUMERIC_LITERAL_NODE;
    }

    std::string print() override 
    {
        std::string printStatement = "Number: " + std::to_string(number);

        return printStatement;
    }
};

#endif