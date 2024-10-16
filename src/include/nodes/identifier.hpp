#ifndef INDENTIFIER_HPP
#define INDENTIFIER_HPP
#include "ASTNode.hpp"
#include <iostream>

class Identifier : Node 
{
public: 
    std::string symbol;

    Identifier(std::string sym) : symbol(sym)
    {
        type = NodeType::IDENTIFIER;
    }
    
};

#endif