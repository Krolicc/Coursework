//
// Created by Crowdlless on 05.05.2024.
//

#ifndef EXPRESSIONNODE_H
#define EXPRESSIONNODE_H
#include <string>

class ExpressionNode {
    public:
        std::string type = "";
        ExpressionNode(std::string type = ""): type(type) {}
        std::string getType() {return type;}
};



#endif //EXPRESSIONNODE_H
