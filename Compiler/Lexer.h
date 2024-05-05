// Created by Crowdlless on 03.05.2024.

#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <iostream>
#include <vector>
#include <regex>
#include "Token.h"



class Lexer {
    std::string code;
    int pos = 0;
    std::vector<Token*> tokenList = {};

    public:

        std::vector<Token*> getTokenList() {
            return tokenList;
        }

        explicit Lexer(std::string& code): code(code) {};

        std::vector<Token*> lexAnalysis() {
            while (this->nextToken()) {
                //std::cout << "Token" << std::endl;
            }
            int i = 0;
            auto ptr = tokenList.begin();
            while(ptr != tokenList.end()) {
                if(this->tokenList[i]->getTokenType().getName() == "SPACE") {
                    this->tokenList.erase(ptr);
                } else {
                    ++ptr;
                    ++i;
                }
            }

            return this->tokenList;
        }

        bool nextToken() {
            if(this->pos >= this->code.length()) {
                return false;
            }

            try {
                for(const auto& tokenType : tokenTypeValues)
                {
                    std::regex regular('^' + tokenType.getRegex());

                    //std::cout << this->code.substr(this->pos).c_str() << std::endl;

                    std::cmatch re;
                    bool bl = std::regex_search(this->code.substr(this->pos).c_str(), re, regular);

                    //std::cout<<bl<<" "<<re[0].length()<<std::endl;


                    if(re[0].length() != 0 && !re.empty()) {
                        Token* token = new Token(tokenType, re[0], pos);
                        this->pos += re[0].length();
                        this->tokenList.push_back(token);
                        return true;
                    }
                }

                throw this->pos;
            } catch (const int ex) {
                std::cout << "Позиция: " << ex << std::endl;
                return false;
            }
        }
};



#endif //LEXER_H
