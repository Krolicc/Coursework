// Created by Crowdlless on 03.05.2024.

#ifndef TOKEN_H
#define TOKEN_H
#include "TokenType.h"



class Token
{
    public:
        Token():  type("", ""), text(""), pos(0) {}
        Token(TokenType type, std::string text, int p):  type(type), text(text), pos(p) {}
        std::string getText() {return text;}
        TokenType getTokenType() {return type;}

    private:
        TokenType type;
        std::string text;
        int pos;

};



#endif //TOKEN_H
