#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <vector>
#include <stdexcept> 
#include "token.hpp"
#include "keywords.hpp"

std::vector<std::string> split(std::string &str) 
{
    std::vector<std::string> result;

    for (char c : str) {
        result.push_back(std::string(1, c));
    }

    return result;
}

bool isAlpha(std::string &str) 
{
   for (char c : str) 
   {
      if (!std::isalpha(c)) {  // Check each character instead of the whole string
         return false;
      }   
   }

   return true;
}

bool isInt(std::string &str) 
{
   for (char c : str) {
      if (!std::isdigit(c)) {
         return false;
      }
   }
   return true;
}


std::vector<Token> tokenise(std::string code) 
{
    std::vector<Token> tokens;

    std::vector<std::string> arr = split(code);

    for (int i = 0; i < arr.size(); i++)
    {

      std::cout << arr[i] << std::endl;

      if (arr[i] == "{" || arr[i] == "}" || arr[i] == "," || arr[i] == "[" || arr[i] == "]") {
         tokens.push_back(Token(arr[i], TokenType::PUNCTUATION));
      } else if (arr[i] == "+" || arr[i] == "-" || arr[i] == "/" || arr[i] == "" || arr[i] == "=") {
         tokens.push_back(Token(arr[i], TokenType::BINARYOPERATOR));
      } else if (arr[i] == " " || arr[i] == "\n" || arr[i] == "\t") {
         tokens.push_back(Token(arr[i], TokenType::WHITESPACE));
      } else if (isAlpha(arr[i])) {

         std::string identifier = "";

         while (arr[i] != " " && arr[i] != ";" && i < arr.size()) {
            identifier += arr[i];
            i++;
         }
         Keywords keywordsHashmap = Keywords();
         std::cout << "identifier:" << " " << identifier << std::endl;
         if (keywordsHashmap.check(identifier)) {
            if (identifier == "fr" || identifier == "cap") {
               tokens.push_back(Token(identifier, TokenType::BOOLEAN_LITERAL));
            } else {
               tokens.push_back(Token(identifier, TokenType::KEYWORD));
            }
         } else {
            tokens.push_back(Token(identifier, TokenType::IDENTIFIERS));
         }
      } else if (isInt(arr[i])) {
         tokens.push_back(Token(arr[i], TokenType::NUMERIC_LITERAL));
      } else if (arr[i] == "\"" || arr[i] == "'") {
         std::string string = "";
         std::string quote = arr[i];  // Store the opening quote
         i += 1;
         while (arr[i] != quote) {
            string += arr[i];
            i++;
         }
         tokens.push_back(Token(string, TokenType::STRING_LITERAL));
      } else if (arr[i] == ";") {
         tokens.push_back(Token(arr[i], TokenType::SEMICOLON));
      } else {
         throw std::runtime_error("Uknown char " + arr[i]);
      }
    }

    return tokens;   
}



#endif