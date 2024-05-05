// Created by Crowdlless on 03.05.2024.

#ifndef TOKENTYPE_H
#include <map>
#include <string>
#define TOKENTYPE_H




class TokenType {
    public:
        TokenType(std::string name, std::string regex): name(name), regex(regex) {}

        [[nodiscard]] std::string getRegex() const {return regex;}
        [[nodiscard]] std::string getName() const {return name;}

    private:
        std::string name;
        std::string regex;

};

inline std::vector<TokenType> tokenTypeValues =
{
    TokenType("NUMBER", "[0-9]+"),
    TokenType("VARIABLE", "[�-�]+"),
    TokenType("SEMICOLON", ";"),
    TokenType("SPACE", R"([ \n\t\r])"),
    TokenType("ASSIGN", "�����"),
    TokenType("LOG", "�������"),
    TokenType("PLUS", "����"),
    TokenType("MINUS", "�����"),
    TokenType("LPAR", "\\("),
    TokenType("RPAR", "\\)"),
 };

#endif //TOKENTYPE_H
