#ifndef PROGRAM_H
#define PROGRAM_H
#include <iostream>
#include "ASTNode.hpp"
#include <vector>
#include <memory>

class Program : public Node
{
public:

    std::vector<std::unique_ptr<Node>> body;

    Program(std::vector<std::unique_ptr<Node>> b) : body(std::move(b))
    {
        type = NodeType::PROGRAM;
    };

    void printBody() 
    {
        for (int i = 0; i < body.size(); i++)
        {
            std::cout << body[i]->print() << std::endl;
        }
        
    }


};


#endif