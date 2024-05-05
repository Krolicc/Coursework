//
// Created by Crowdlless on 05.05.2024.
//

#ifndef STATEMENTSNODE_H
#define STATEMENTSNODE_H
#include <string>
#include <vector>
#include "ExpressionNode.cpp"



class StatementsNode : public ExpressionNode{
    std::vector<ExpressionNode*> codeStrings = {};

    public:
        void addNode(ExpressionNode* node) {
            this->codeStrings.push_back(node);
        }
};



#endif //STATEMENTSNODE_H
