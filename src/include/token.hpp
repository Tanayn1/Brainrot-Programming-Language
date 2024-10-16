#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

enum TokenType 
{
    STRING_LITERAL,
    BOOLEAN_LITERAL,
    NUMERIC_LITERAL,
    PUNCTUATION,
    KEYWORD,
    IDENTIFIERS,
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



