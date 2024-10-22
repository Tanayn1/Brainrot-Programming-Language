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
#include <memory>

class Parser 
{

private:
    std::vector<Token> tokenArray;

    std::unique_ptr<Program> program = std::make_unique<Program>(std::vector<std::unique_ptr<Node>>());
        
    Token eat() 
    {
        Token token = tokenArray[0];
        tokenArray.erase(tokenArray.begin());

        return token;
    }

    std::unique_ptr<Node> parsePrimaryExpr() 
    {
        std::cout << "Parsing" << " " << tokenArray[0].value << std::endl;  
        switch (tokenArray[0].type)
        {
        case TokenType::NUMERIC_LITERAL:
        std::cout << "Parsing Numeric Literal" << " " << tokenArray[0].value << std::endl;  
        return std::make_unique<NumericLiteral>(atoi(eat().value.c_str()));
        case TokenType::STRING_LITERAL:
            std::cout << "Parsing String Literal" << " " << tokenArray[0].value << std::endl;  
            return std::make_unique<StringLiteral>(eat().value);
        case TokenType::BOOLEAN_LITERAL:
            std::cout << "Parsing Boolean Literal" << " " << tokenArray[0].value << std::endl;  
            return std::make_unique<Node>();
        default:
            throw std::runtime_error("Unrecongnised token " +  tokenArray[0].value);
        }
    }

    std::unique_ptr<Node> parseAdditaveExpr() 
    {
        std::unique_ptr<Node> left = parsePrimaryExpr();

        while (tokenArray[0].value == "+" || tokenArray[0].value == "-") 
        {
            std::cout << "Parsing Additave Expression" << " " << tokenArray[0].value << std::endl;  
            std::string op = eat().value;
            std::unique_ptr<Node> right = parsePrimaryExpr();
            
            left = std::make_unique<BinaryExpression>(std::move(left), std::move(right), op);
        
        }

        return left;
    }

    std::unique_ptr<Node> parseMultiplativeExpr() 
    {
        std::unique_ptr<Node> left = parseAdditaveExpr();

        while (tokenArray[0].value == "*" || tokenArray[0].value == "/") 
        {
            std::string op = eat().value;
            std::unique_ptr<Node> right = parseAdditaveExpr();

            left = std::make_unique<BinaryExpression>(std::move(left), std::move(right), op);

        }

        return left;
    }

public:

    Parser(std::vector<Token> arr) : tokenArray(arr) {}

    std::unique_ptr<Program> parse() 
    {
        while (!tokenArray.empty()) 
        {
            std::unique_ptr<Node> node = parseMultiplativeExpr();

            program->body.push_back(std::move(node));
        }

        return std::move(program);
    };


};

#endif