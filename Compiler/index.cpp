// Created by Crowdlless on 03.05.2024.
#include "Lexer.cpp"
#include <string>
#include <Windows.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string code =
        "sêîä ÐÀÂÍÎ 5 ÏËÞÑ 9 ÏËÞÑ ( 4 ÌÈÍÓÑ 6);\
         ÊÎÍÑÎËÜ êîä;\
         ïåðåìåííàÿ ÐÀÂÍÎ êîä ÏËÞÑ 3;\
         ÊÎÍÑÎËÜ ïåðåìåííàÿ ÏËÞÑ êîä ÌÈÍÓÑ 6;";

    Lexer* lexer = new Lexer(code);

    lexer->lexAnalysis();

    std::vector<Token*> tk = lexer->getTokenList();

    for(int i=0; i<tk.size(); ++i) {
        std::cout << i << " " << tk[i]->getText() << " " << tk[i]->getTokenType().getName() << std::endl;;
    }

    return 0;
}