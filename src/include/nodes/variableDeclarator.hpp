#ifndef VARIABLE_DECLARATOR_H
#define VARIABLE_DECLARATOR_H
#include "identifier.hpp"

class VariableDeclarator : Node
{
public:
    Identifier id;
    Node init;

    VariableDeclarator(Identifier i, Node initalize) : id(i), init(initalize)
    {
        type = NodeType::VARIABLE_DECLARATION;
    }
};

#endif