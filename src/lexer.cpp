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
      if (arr[i] == "{" || arr[i] == "}" || arr[i] == "," || arr[i] == "[" || arr[i] == "]") {
         tokens.push_back(Token(arr[i], TokenType::PUNCTUATION));
      } else if (arr[i] == "+" || arr[i] == "-" || arr[i] == "/" || arr[i] == "") {
         tokens.push_back(Token(arr[i], TokenType::BINARYOPERATOR));
      } else if (arr[i] == "") {
         tokens.push_back(Token(arr[i], TokenType::WHITESPACE));
      } else if (isAlpha(arr[i])) {

         std::string identifier = "";

         while (arr[i] != " ") {
            identifier += arr[i];
            i++;
         }
         Keywords keywordsHashmap = Keywords();

         if (keywordsHashmap.check(identifier)) {
            tokens.push_back(Token(identifier, TokenType::KEYWORD));
         } else {
            throw std::runtime_error(identifier + "Is an unknown identifier");
         }
      } else if (isInt(arr[i])) {
         tokens.push_back(Token(arr[i], TokenType::LITERALS));
      } else if (arr[i] == "\"" || arr[i] == "'") {
         std::string string = "";
         i += 1;
         while (arr[i] != "\"" || arr[i] != "'") {
            string += arr[i];
            i++;
         }
         tokens.push_back(Token(string, TokenType::LITERALS));
      } else if (arr[i] == ";") {
         tokens.push_back(Token(arr[i], TokenType::SEMICOLON));
      } else {
         throw std::runtime_error("Uknown char" +  arr[i]);
      }
    }

    return tokens;   
}



