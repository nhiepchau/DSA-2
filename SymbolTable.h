#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include "main.h"

class Node;
enum Type {nil, error, str, number, funct, funcNum, funcStr, nameIden};

class SymbolTable
{
private:
    int currentLevel;
    int size;
    string removedList;
    Node *root;
protected:
    void equalTypeParam(string instruction, string params, string typeParam, int &num_comp, int &num_splay);
    int insertRec(Node* &nodeRoot, string identifier, int levelOfBlock, Node* &newNode);
    int containsNode(Node* nodeRoot, string identifier, int levelOfBlock, Node* &node);
    void printRec(Node* nodeRoot);
    void clearRec(Node* &nodeRoot);
public:
    SymbolTable() {
        this->currentLevel = 0;
        this->size = 0;
        this->removedList = "";
        this->root = nullptr;
    }
    ~SymbolTable() {
        this->clear();
    }
    void run(string filename);
    void rotatewithLeftChild(Node* &nodeRoot, Node* &par);
    void rotatewithRightChild(Node* &nodeRoot, Node* &par);
    int splay(Node* &nodeRoot, Node* &node);
    void insert(string instruction, string identifier, Type type, bool isStatic, string params);
    void assign(string instruction, string identifier, string value, Type type, string nameFunc, string params);
    void remove(string identifier, int levelOfBlock);
    void block(string instruction);
    void lookup(string instruction, string identifier);
    void print();
    void clear();
};

class Node
{
private:
    string identifier;
    string params;
    int levelOfBlock;
    Type type;
    Node *left;
    Node *right;
    Node *parent;
public:
    friend class SymbolTable;
    Node() {
        this->identifier = "";
        this->params = "";
        this->levelOfBlock = 0;
        this->type = nil;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
    Node(string identifier, int levelOfBlock) {
        this->identifier = identifier;
        this->params = "";
        this->levelOfBlock = levelOfBlock;
        this->type = nil;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
    int compare(Node* other) {
        if (this->levelOfBlock < other->levelOfBlock) return -1;
        else if (this->levelOfBlock > other->levelOfBlock) return 1;
        else 
            return (this->identifier).compare(other->identifier);
    }
    int compare(int levelOfBlock, string identifier) {
        if (this->levelOfBlock < levelOfBlock) return -1;
        else if (this->levelOfBlock > levelOfBlock) return 1;
        else 
            return (this->identifier).compare(identifier);        
    }
};
#endif