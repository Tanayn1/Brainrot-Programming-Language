#ifndef VARIABLE_DECLARATION_H
#define VARIABLE_DECLARATION_H
#include "ASTNode.hpp"
#include <iostream>
#include <vector>

enum VariableDeclarationType {};

class VariableDeclaration : Node
{
public:
    std::string kind;
    std::vector<Node> declarations;

    VariableDeclaration(std::string k, std::vector<Node> d) : kind(k), declarations(d) 
    {
        type = NodeType::VARIABLE_DECLARATION;
    }
};

#endif