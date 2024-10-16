#ifndef AST_NODE_H
#define AST_NODE_H
#include <iostream>

enum NodeType 
{
    PROGRAM,
    NUMERIC_LITERAL,
    BINARY_EXPRESSION,
    IDENTIFIER,
    VARIABLE_DECLARATION,
    STRING_LITERAL
};

class Node
{
public:
    NodeType type;

};


#endif