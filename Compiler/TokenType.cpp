// Created by Crowdlless on 03.05.2024.
#include "TokenType.h"
#include <map>
#include <string>


int main() {
    std::map<std::string, TokenType> TokenTypesList
    {
        {"NUMBER",  TokenType("NUMBER", "[0-9]*")},
        {"VARIABLE", TokenType("VARIABLE", "[а-я]*")},
        {"SEMICOLON", TokenType("SEMICOLON", ";")},
        {"SPACE", TokenType("SPACE", " \\n\\t\\r")},
        {"ASSIGN", TokenType("ASSIGN", "РАВНО")},
        {"LOG", TokenType("LOG", "ЛОГ")},
        {"PLUS", TokenType("PLUS", "ПЛЮС")},
        {"MINUS", TokenType("MINUS", "МИНУС")},
        {"LPAR", TokenType("LPAR", "\\(")},
        {"RPAR", TokenType("RPAR", "\\)")},
    };
}



