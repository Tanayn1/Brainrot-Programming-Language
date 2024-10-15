#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

enum TokenType 
{
    LITERALS,
    PUNCTUATION,
    KEYWORD,
    BINARYOPERATOR,
    WHITESPACE,
    SEMICOLON
};

class Token 
{
public: 
    std::string value;
    TokenType type;

    Token(std::string val, TokenType t) : value(val), type(t) {};
};
#endif



