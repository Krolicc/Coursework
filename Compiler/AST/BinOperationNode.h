//
// Created by Crowdlless on 05.05.2024.
//

#ifndef BINOPERATIONNODE_H
#define BINOPERATIONNODE_H
#include "../Token.cpp"
#include "ExpressionNode.cpp"
#include <string>

class BinOperationNode : public ExpressionNode{
    Token* Operator;
    ExpressionNode* leftNode;
    ExpressionNode* rightNode;

public:
    BinOperationNode(Token* Operator, ExpressionNode* leftNode, ExpressionNode* rightNode): Operator(Operator), leftNode(leftNode), rightNode(rightNode),
                                                                                            ExpressionNode("Bin") {}
};

#endif //BINOPERATIONNODE_H
