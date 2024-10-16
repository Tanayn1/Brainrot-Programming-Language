#ifndef STRING_LITERAL_H
#define STRING_LITERAL_H
#include "ASTNode.hpp"
#include <iostream>

class StringLiteral : Node 
{
public:
    std::string string;

    StringLiteral(std::string str) : string(str)
    {
        type = NodeType::STRING_LITERAL;
    }
};

#endif