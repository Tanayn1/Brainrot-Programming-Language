#ifndef AST_NODE_H
#define AST_NODE_H
#include <iostream>

enum NodeType 
{
    PROGRAM,
    NUMERIC_LITERAL_NODE,
    BINARY_EXPRESSION,
    IDENTIFIER,
    VARIABLE_DECLARATION,
    STRING_LITERAL_NODE
};

class Node
{
public:
    NodeType type;

    virtual ~Node() {}

    std::string nodeTypeToString() const 
    {
        switch (type) {
            case PROGRAM: return "PROGRAM";
            case NUMERIC_LITERAL_NODE: return "NUMERIC_LITERAL_NODE";
            case BINARY_EXPRESSION: return "BINARY_EXPRESSION";
            case IDENTIFIER: return "IDENTIFIER";
            case VARIABLE_DECLARATION: return "VARIABLE_DECLARATION";
            case STRING_LITERAL_NODE: return "STRING_LITERAL_NODE";
            default: return "UNKNOWN";
        }
    }

    virtual std::string print() 
    {
        std::string printStatement = "Node Type: " + nodeTypeToString();

        return printStatement;
    }

};


#endif