//
// Created by Crowdlless on 04.05.2024.
//

#include <iostream>
#include <regex>
#include <string>


class Ex {
public:
    std::string type = "";
    Ex(std::string a = "1"): type(a) {}
    [[nodiscard]] std::string getType() const {return type;}
};

class ajk : public Ex {
    public:
        ajk():Ex("123"){}
};


int main() {

    ajk a;

    std::cout << a.getType();
}