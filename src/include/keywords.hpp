#include <iostream>
#include <unordered_map>
#ifndef KEYWORDS_H
#define KEYWORDS_H

enum KeywordType {
    RIZZ,
    FR,
    CAP,
    TIKTOKRIZZPARTY,
    SIGMA,
    BETA,
    OHIO,

};

class Keywords 
{
private:
    std::unordered_map<std::string, KeywordType> KeywordHashmap;

public:
    Keywords() 
    {
        KeywordHashmap = {
            {"rizz", KeywordType::RIZZ},  
            {"fr", KeywordType::FR},
            {"cap", KeywordType::CAP},
            {"tiktokrizzparty", KeywordType::TIKTOKRIZZPARTY},
            {"sigma", KeywordType::SIGMA},
            {"beta", KeywordType::BETA},
            {"ohio", KeywordType::OHIO},
        };
    }

    bool check(std::string string) 
    {
        return KeywordHashmap.find(string) != KeywordHashmap.end();
    }
};

#endif
