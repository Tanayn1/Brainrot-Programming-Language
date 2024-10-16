#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include "ASTNode.hpp"

class Program : public Node
{
public:
    Program() 
    {
        type = NodeType::PROGRAM;
    };


};


#endif