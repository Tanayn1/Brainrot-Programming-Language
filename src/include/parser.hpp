#ifndef PARSER_H
#define PARSER_H
#include "./nodes/ASTNode.hpp"
#include <iostream>
#include <string>
#include "token.hpp"
#include <vector>
#include "./nodes/program.hpp"
#include "./nodes/variableDeclarator.hpp"
#include "./nodes/stringLiteral.hpp"
#include "./nodes/numericLiteral.hpp"
#include <stdlib.h>
#include "./nodes/binaryExpression.hpp"

class Parser 
{

private:
    std::vector<Token> tokenArray;

    Program program = Program({});

    Token eat() 
    {
        Token token = tokenArray[0];
        tokenArray.erase(tokenArray.begin());

        return token;
    }

    Node parsePrimaryExpr() 
    {
        std::cout << "Parsing" << " " << tokenArray[0].value << std::endl;  
        switch (tokenArray[0].type)
        {
        case TokenType::NUMERIC_LITERAL:
        std::cout << "Parsing Numeric Literal" << " " << tokenArray[0].value << std::endl;  
        return NumericLiteral(atoi(eat().value.c_str()));
        case TokenType::STRING_LITERAL:
            std::cout << "Parsing String Literal" << " " << tokenArray[0].value << std::endl;  
            return StringLiteral(eat().value);
        case TokenType::BOOLEAN_LITERAL:
            std::cout << "Parsing Boolean Literal" << " " << tokenArray[0].value << std::endl;  
            return Node();
        default:
            throw std::runtime_error("Unrecongnised token " +  tokenArray[0].value);
        }
    }

    Node parseAdditaveExpr() 
    {
        Node left = parsePrimaryExpr();

        while (tokenArray[0].value == "+" || tokenArray[0].value == "-") 
        {
            std::cout << "Parsing Additave Expression" << " " << tokenArray[0].value << std::endl;  
            std::string op = eat().value;
            Node right = parsePrimaryExpr();
            
            left = BinaryExpression(left, right, op);
        
        }

        return left;
    }

    Node parseMultiplativeExpr() 
    {
        Node left = parsePrimaryExpr();

        while (tokenArray[0].value == "*" || tokenArray[0].value == "/") 
        {

        }
    }

public:

    Parser(std::vector<Token> arr) : tokenArray(arr) {}

    Program parse() 
    {
        while (tokenArray.size() > 0) 
        {
            Node body = parseAdditaveExpr();

            program.body.push_back(body);
        }

        return program;
    };


};

#endif