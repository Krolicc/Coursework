//
// Created by Crowdlless on 05.05.2024.
//

#ifndef UNAROPERATIONNODE_H
#define UNAROPERATIONNODE_H
#include "../Token.cpp"
#include "ExpressionNode.cpp"
#include <string>

class UnarOperationNode : public ExpressionNode{
    Token* Operator;
    ExpressionNode* operand;

    public:
        UnarOperationNode(Token* Operator, ExpressionNode* operand): Operator(Operator), operand(operand), ExpressionNode("Unar") {}

}

#endif //UNAROPERATIONNODE_H
