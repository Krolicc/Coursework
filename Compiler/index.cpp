// Created by Crowdlless on 03.05.2024.
#include "Lexer.cpp"
#include <string>
#include <Windows.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string code =
        "s��� ����� 5 ���� 9 ���� ( 4 ����� 6);\
         ������� ���;\
         ���������� ����� ��� ���� 3;\
         ������� ���������� ���� ��� ����� 6;";

    Lexer* lexer = new Lexer(code);

    lexer->lexAnalysis();

    std::vector<Token*> tk = lexer->getTokenList();

    for(int i=0; i<tk.size(); ++i) {
        std::cout << i << " " << tk[i]->getText() << " " << tk[i]->getTokenType().getName() << std::endl;;
    }

    return 0;
}