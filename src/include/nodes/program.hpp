#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include "ASTNode.hpp"
#include <vector>

class Program : public Node
{
public:

    std::vector<Node> body;

    Program(std::vector<Node> b) : body(b)
    {
        type = NodeType::PROGRAM;
    };

    void printBody() 
    {
        for (int i = 0; i < body.size(); i++)
        {
            std::cout << body[i].print() << std::endl;
        }
        
    }


};


#endif