//
// Created by Crowdlless on 05.05.2024.
//

#ifndef NUMBERNODE_H
#define NUMBERNODE_H
#include "../Token.cpp"
#include "ExpressionNode.cpp"
#include <string>

class NumberNode : public ExpressionNode{
    Token* number;

    public:
        NumberNode(Token* number): number(number), ExpressionNode("Number") {}
}

#endif //NUMBERNODE_H
