// Created by Crowdlless on 03.05.2024.

#ifndef PARSER_H
#define PARSER_H
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include "Token.h"
#include "TokenType.cpp"
#include "AST\StatementsNode.cpp"
#include "AST\NumberNode.h"
#include "AST\VariableNode.h"
#include "AST\BinOperationNode.h"
#include "AST\UnarOperationNode.h"



class Parser {
 std::vector<Token*> tokens;
 int pos = 0;
 std::map<std::string,std::string> scope = {};

 public:
  Parser(std::vector<Token*> tokens): tokens(tokens){}

  Token* match(std::vector<TokenType> expected) {
      if(this->pos < this->tokens.size()) {
          Token* currentToken = this->tokens[this->pos];
          if(std::find(expected.begin(), expected.end(), currentToken->getTokenType().getName()) != expected.end()) {
              this->pos += 1;
              return currentToken;
          }
      }
      return nullptr;
  }

  Token* require(std::vector<TokenType> expected) {
        Token* token = this->match(expected);
        try {
            if(!token) {
                throw this->pos;
            }
        } catch (int a) {
            std::cout << "Позиция" << a << std::endl;
        }
        return token;
  }

  ExpressionNode* parseVariableOrNumber() {
    try {
        Token* number = this->match(std::vector<TokenType>{TokenType("VARIABLE", "[0-9]+")});
        if(number != nullptr) {
            return new NumberNode(number);
        }
        Token* variable = this->match(std::vector<TokenType>{TokenType("VARIABLE", "[а-я]+")});
        if(variable != nullptr) {
            return new VariableNode(variable);
        }
        throw this->pos;
    } catch(int a) {
        std::cout << "Position: " << a << std::endl;
        return nullptr;
    }
  }

  ExpressionNode* parseParentheses() {
      if(this->match(std::vector<TokenType>{TokenType("LPAR", "\\(")}) != nullptr) {
          ExpressionNode* node = this->parseFormula();
          this->require(std::vector<TokenType>{TokenType("LPAR", "\\)")});
          return node;
      } else {
          return this->parseVariableOrNumber();
      }
  }

  ExpressionNode* parseFormula() {
      ExpressionNode* leftNode = this->parseParentheses();
      Token* Operator = this->match(std::vector<TokenType>{ TokenType("PLUS", "ПЛЮС"),
                                                            TokenType("MINUS", "МИНУС")});
      while(Operator != nullptr) {
          ExpressionNode* rightNode = this->parseParentheses();
          leftNode = new BinOperationNode(Operator, leftNode, rightNode);
          Operator = this->match(std::vector<TokenType>{ TokenType("PLUS", "ПЛЮС"),
                                                         TokenType("MINUS", "МИНУС")});
      }

      return leftNode;
  }

  ExpressionNode* parsePrint() {
      try{
          Token* operatorLog = this->match(std::vector<TokenType>{TokenType("LOG", "КОНСОЛЬ")});
          if(operatorLog != nullptr) {
              return new UnarOperationNode(operatorLog, this->parseFormula());
          }
          throw this->pos;
      } catch(int a) {
          std::cout << "Position: " << a << std::endl;
          return nullptr;
      }
  }

  ExpressionNode* parseExpression() {
      try {
          if(this->match(std::vector<TokenType>{TokenType("VARIABLE", "[а-я]+")}) == nullptr) {
              ExpressionNode* printNode = this->parsePrint();
              return printNode;
          }
          this->pos -= 1;
          ExpressionNode* variableNode = parseVariableOrNumber();
          Token* assignOperator = this->match(std::vector<TokenType>{TokenType("ASSIGN", "РАВНО")});
          if(assignOperator != nullptr) {
              ExpressionNode* rightFormulaNode = this->parseFormula();
              ExpressionNode* binaryNode = new BinOperationNode(assignOperator, variableNode, rightFormulaNode);
              return binaryNode;
          }
          throw this->pos;
      } catch (int a) {
          std::cout << "Позиция: " << a << std::endl;
          return nullptr;
      }
  }

  ExpressionNode* parseCode() {
      StatementsNode* root = new StatementsNode();
      while(this->pos < this->tokens.size()) {
          ExpressionNode* codeStringNode = this->parseExpression();
          this->require(std::vector<TokenType>{TokenType("SEMICOLON", ";")});
          root->addNode(codeStringNode);
      }
      return root;
  }

  auto run(ExpressionNode* node) {
      if(node->getType() == "Number") {
          return atoi(node::NumberNode);
      }
  }

};



#endif //PARSER_H
