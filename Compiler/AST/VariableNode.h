//
// Created by Crowdlless on 05.05.2024.
//

#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include "../Token.cpp"
#include "ExpressionNode.cpp"
#include <string>

class VariableNode : public ExpressionNode {
    Token* variable;

    public:
        VariableNode(Token* variable): variable(variable), ExpressionNode("Variable") {}
}

#endif //VARIABLENODE_H
