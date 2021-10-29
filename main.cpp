#include <iostream>
#include <string>
#include <fstream>
#include "error.h"

using namespace std;

// class Node
// {
// public:
//     int identifier;
//     Node *parent;
//     Node *left;
//     Node *right;
// public:
//     Node() {
//         identifier = 0;
//         parent = nullptr;
//         left = nullptr;
//         right = nullptr;
//     }
//     Node(int identifier) {
//         this->identifier = identifier;
//         parent = nullptr;
//         left = nullptr;
//         right = nullptr;
//     }
//     int compare(Node* other) {
//         if (identifier < other->identifier) return -1;
//         else if (identifier > other->identifier) return 1;
//         else return 0;
//     }
// };

// class SplayTree
// {
// public:
//     Node *root;
//     int size;
// protected:
//     void insertRec(Node* &nodeRoot, int identifier, Node* &newNode);
//     bool containsRec(Node* nodeRoot, int identifier, Node* &newNode);
//     void printRec(Node* nodeRoot);
//     void clearRec(Node* &nodeRoot);
// public:
//     SplayTree() {
//         this->root = nullptr;
//         this->size = 0;
//     }
//     SplayTree(Node* other) {
//         this->root = other;
//         this->size = 1;
//     }
//     ~SplayTree() {
//         this->clear();
//     }
//     void rotatewithLeftChild(Node* &nodeRoot, Node* &par);
//     void rotatewithRightChild(Node* &nodeRoot, Node* &par);
//     void splay(Node* &nodeRoot, Node* &node);
//     void insert(int identifier);
//     void remove(int identifier);
//     bool contains(int identifier);
//     void clear();
//     void print();
// };

// void SplayTree::rotatewithLeftChild(Node* &nodeRoot, Node* &par)
// {
//     Node *child = par->left;
//     par->left = child->right;
//     if (child->right != nullptr) child->right->parent = par;
//     if (par != nodeRoot) {
//         if (par->compare(par->parent) < 0) par->parent->left = child;
//         else par->parent->right = child;
//     } else {
//         nodeRoot = child;
//     }
//     child->right = par;
//     child->parent = par->parent;
//     par->parent = child;
//     par = child;
// }

// void SplayTree::rotatewithRightChild(Node* &nodeRoot, Node* &par)
// {
//     Node *child = par->right;
//     par->right = child->left;
//     if (child->left != nullptr) child->left->parent = par;
//     if (par != nodeRoot) {
//         if (par->compare(par->parent) < 0) par->parent->left = child;
//         else par->parent->right = child;
//     } else {
//         nodeRoot = child;
//     }
//     child->left = par;
//     child->parent = par->parent;
//     par->parent = child;
//     par = child;
// }

// void SplayTree::splay(Node* &nodeRoot, Node* &node)
// {
//     if (node == nullptr || nodeRoot == nullptr || node->compare(nodeRoot) == 0) return;
//     Node* par = node->parent;
//     Node* grand = par->parent;
//     if (node->compare(par) < 0)
//     {
//         if (par == nodeRoot) {
//             rotatewithLeftChild(nodeRoot, par);
//         } else {
//             if (par->compare(grand) < 0)
//             {
//                 rotatewithLeftChild(nodeRoot, grand);
//                 rotatewithLeftChild(nodeRoot, par);
//             }
//             else 
//             {
//                 rotatewithLeftChild(nodeRoot, par);
//                 rotatewithRightChild(nodeRoot, grand);
//             }
//         }
//         splay(nodeRoot, node);
//     } else
//     {
//         if (par == nodeRoot) {
//             rotatewithRightChild(nodeRoot, par);
//         } else {
//             if (par->compare(grand) > 0)
//             {
//                 rotatewithRightChild(nodeRoot, grand);
//                 rotatewithRightChild(nodeRoot, par);
//             }
//             else 
//             {
//                 rotatewithRightChild(nodeRoot, par);
//                 rotatewithLeftChild(nodeRoot, grand);
//             }
//         }
//         splay(nodeRoot, node);      
//     }
// }

// void SplayTree::insertRec(Node* &nodeRoot, int identifier, Node* &newNode)
// {
//     if (nodeRoot == nullptr) {
//         nodeRoot = new Node(identifier);
//         newNode = nodeRoot;
//     }
//     else {
//         if (nodeRoot->identifier > identifier) {
//             if (nodeRoot->left == nullptr) {
//                 nodeRoot->left = new Node(identifier);
//                 nodeRoot->left->parent = nodeRoot;
//                 newNode = nodeRoot->left;
//             } else {
//                 insertRec(nodeRoot->left, identifier, newNode);
//             }
//         } else {
//             if (nodeRoot->right == nullptr) {
//                 nodeRoot->right = new Node(identifier);
//                 nodeRoot->right->parent = nodeRoot;
//                 newNode = nodeRoot->right;
//             } else {
//                 insertRec(nodeRoot->right, identifier, newNode);
//             }
//         }
//     }
// }

// void SplayTree::insert(int identifier)
// {
//     Node *newNode = nullptr;
//     insertRec(this->root, identifier, newNode);
//     ++(this->size);
//     splay(this->root, newNode);
//     print();
// }

// void SplayTree::remove(int identifier)
// {
//     if (root == nullptr) return;
//     Node* node = nullptr;
//     if (!containsRec(this->root, identifier, node)) return;
//     splay(this->root, node);
//     if (root->left == nullptr && root->right == nullptr) {
//         delete this->root;
//         this->root = nullptr;
//     } else if (root->left == nullptr) {
//         Node* temp = root;
//         root = root->right;
//         root->parent = nullptr;
//         delete temp;
//         temp = nullptr;          
//     } else {
//         Node* current = root->left;
//         Node* par = root;
//         while (current->right != nullptr)
//         {
//             par = current;
//             current = current->right;
//         }
//         splay(root->left, current);
//         Node* temp = root;
//         root = root->left;
//         root->parent = nullptr;
//         root->right = temp->right;
//         if (temp->right != nullptr) temp->right->parent = root;
//         delete temp;
//     }
//     --(this->size);
//     print();
// }

// bool SplayTree::containsRec(Node* nodeRoot, int identifier, Node* &node)
// {
//     if (nodeRoot == nullptr) return false;
//     if (nodeRoot->identifier == identifier) {
//         node = nodeRoot;
//         return true;
//     } else if (nodeRoot->identifier > identifier) {
//         return containsRec(nodeRoot->left, identifier, node);
//     } else {
//         return containsRec(nodeRoot->right, identifier, node);
//     }
// }

// bool SplayTree::contains(int identifier)
// {
//     Node* node = nullptr;
//     if (!containsRec(this->root, identifier, node)) return false;
//     splay(this->root, node);
//     print();
//     return true;
// }

// void SplayTree::printRec(Node *nodeRoot)
// {
//     if (nodeRoot == nullptr) return;
//     static int count = 0;
//     ++count;
//     if (count < this->size) {
//         cout << nodeRoot->identifier << " ";
//     } else {
//         cout << nodeRoot->identifier;
//         count = 0;
//     }
//     printRec(nodeRoot->left);
//     printRec(nodeRoot->right);
// }

// void SplayTree::print()
// {
//     printRec(this->root);
//     cout << endl;
// }

// void SplayTree::clearRec(Node* &nodeRoot)
// {
//     if (nodeRoot == nullptr) return;
//     Node *temp = nodeRoot;
//     clearRec(nodeRoot->left);
//     clearRec(nodeRoot->right);
//     delete temp;
//     temp = nullptr;
// }

// void SplayTree::clear()
// {
//     clearRec(this->root);
// }

// bool validParam(string params)
// {
//     if (params == "()") return true;
//     size_t posComma = params.find(',');
//     while (posComma != string::npos) {
//         if (posComma <= 1 || posComma + 2 >= params.length()) return false;
//         string temp = params.substr(1, posComma - 1);
//         if (temp != "number" && temp != "string") return false;
//         params.erase(1, posComma);
//         posComma = params.find(',');
//     }
//     if (params == "(number)" || params == "(string)") return true;
//     return false;   
// }

// string validType(string type, string &params)
// {
//     if (type == "number") return "number";
//     if (type == "string") return "str";
//     size_t posArrow = type.find("->");
//     if (posArrow < 2 || posArrow == string::npos || posArrow + 2 >= type.length()) return "error";
//     if (type[0] == '(' && type[posArrow - 1] == ')') 
//     {
//         string temp = type.substr(0, posArrow);
//         string typeFunc = type.substr(posArrow + 2);
//         cout << typeFunc << endl;
//         if (validParam(temp)) {
//             params = temp;
//             if (typeFunc == "number") return "funcNum";
//             if (typeFunc == "string") return "funcStr";
//         }         
//     }
//     return "error";
// }

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
    int containsNode(Node* nodeRoot, string identifier, int levelOfBlock, Node* &newNode);
    // int containsFunc(Node* nodeRoot, string identifier, string params, Node* &newNode);
    void printRec(Node* nodeRoot);
    void clearRec(Node* &nodeRoot);
public:
    SymbolTable() {
        this->currentLevel = 0;
        this->size = 0;
        this->removedList = "";
        this->root = nullptr;
    }
    ~SymbolTable() {}
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

bool validIdentifier(string identifier) 
{
    if (identifier == "true" || identifier == "false" || identifier == "number" || identifier == "string")
        return false;
    if (identifier[0] < 'a' || identifier[0] > 'z')
        return false;
    int length = identifier.length();
    for (int i = 1; i < length; ++i)
    {
        if (identifier[i] >= 'a' && identifier[i] <= 'z'); 
        else if (identifier[i] >= 'A' && identifier[i] <= 'Z');
        else if (identifier[i] >= '0' && identifier[i] <= '9');
        else if (identifier[i] == '_');
        else
            return false;
    }
    return true;
}

bool validParam(string params)
{
    if (params == "()") return true;
    size_t posComma = params.find(',');
    while (posComma != string::npos) {
        if (posComma <= 1 || posComma + 2 >= params.length()) return false;
        string temp = params.substr(1, posComma - 1);
        if (temp != "number" && temp != "string") return false;
        params.erase(1, posComma);
        posComma = params.find(',');
    }
    if (params == "(number)" || params == "(string)") return true;
    return false;   
}

Type checkType(string type, string &params)
{
    if (type == "number") return number;
    if (type == "string") return str;
    size_t posArrow = type.find("->");
    if (posArrow < 2 || posArrow == string::npos || posArrow + 2 >= type.length()) return error;
    if (type[0] == '(' && type[posArrow - 1] == ')') 
    {
        string temp = type.substr(0, posArrow);
        string typeFunc = type.substr(posArrow + 2);
        if (validParam(temp)) {
            params = temp;
            if (typeFunc == "number") return funcNum;
            if (typeFunc == "string") return funcStr;
        }         
    }
    return error;
}

Type typeValue(string value, string &nameFunc, string &params);

bool validValueParam(string params)
{
    if (params == "()") return true;
    size_t posComma = params.find(',');
    string trash, foo;
    while (posComma != string::npos) {
        if (posComma <= 1 || posComma + 2 >= params.length()) return false;
        string temp = params.substr(1, posComma - 1);
        if (typeValue(temp, trash, foo) == error) return false;
        params.erase(1, posComma);
        posComma = params.find(',');
    }
    if (typeValue(params.substr(1, params.length() - 2), trash, foo) != error) return true;
    return false; 
}

// string SymbolTable::equalTypeParam(string instruction, string params, int &num_comp, int &num_splay)
// {
//     if (params == "()") return params;
//     string res = "(";
//     size_t posComma = params.find(',');
//     string trash, foo;
//     int temp1 = 0, temp2 = 0;
//     Node* node1 = nullptr;         
//     Node* node2 = nullptr;
//     while (posComma != string::npos) {
//         string temp = params.substr(1, posComma - 1);
//         if (typeValue(temp, trash, foo) == number) 
//             res += "number,";
//         else if (typeValue(temp, trash, foo) == str)
//             res += "string,";
//         else {      //typeValue(temp, trash, foo) == nameIden
//             for (int i = currentLevel; i >= 0; --i) {
//                 temp1 = containsNode(this->root, temp, i, node1);
//                 if (node1 != nullptr) break;
//             }
//             if (node1 == nullptr) throw Undeclared(instruction);
//             if (node1->type == funcStr || node1->type == funcNum)
//                 throw TypeMismatch(instruction);
//             num_comp += temp1;
//             num_splay += splay(this->root, node1);
//             res += ((node1->type == number) ? "number," : "string,");
//         }
//         params.erase(1, posComma);
//         posComma = params.find(',');
//         node1 = nullptr;
//     }
//     string substr = params.substr(1, params.length() - 2);
//     if (typeValue(substr, trash, foo) == number) 
//         res += "number)";
//     else if (typeValue(substr, trash, foo) == str)
//         res += "string)";
//     else {      //typeValue(temp, trash, foo) == nameIden
//         for (int i = currentLevel; i >= 0; --i) {
//             temp2 = containsNode(this->root, substr, i, node2);
//             if (node2 != nullptr) break;
//         }
//         if (node2 == nullptr) throw Undeclared(instruction);
//         if (node2->type == funcStr || node2->type == funcNum)
//             throw TypeMismatch(instruction);
//         num_comp += temp2;
//         num_splay += splay(this->root, node2);
//         res += ((node2->type == number) ? "number)" : "string)");
//     }
//     node1 = nullptr;
//     node2 = nullptr;
//     return res;
// }

void SymbolTable::equalTypeParam(string instruction, string params, string typeParam, int &num_comp, int &num_splay)
{
    if (params == "()" || typeParam == "()") {
        if (params != typeParam) throw TypeMismatch(instruction);
        return;
    }
    size_t posEnd1 = params.find(',');
    posEnd1 = (posEnd1 != string::npos) ? posEnd1 : params.find(')');
    size_t posEnd2 = typeParam.find(',');
    posEnd2 = (posEnd2 != string::npos) ? posEnd2 : typeParam.find(')');
    string trash, foo;
    int temp = 0;
    Node* node = nullptr;         
    while (posEnd1 != string::npos && posEnd2 != string::npos) {
        string tempStr1 = params.substr(1, posEnd1 - 1);
        string tempStr2 = typeParam.substr(1, posEnd2 - 1);
        if (typeValue(tempStr1, trash, foo) == number) tempStr1 = "number";
        else if (typeValue(tempStr1, trash, foo) == str) tempStr1 = "string";
        else {      //typeValue(temp, trash, foo) == nameIden
            for (int i = currentLevel; i >= 0; --i) {
                temp = containsNode(this->root, tempStr1, i, node);
                if (node != nullptr) break;
            }
            if (node == nullptr) throw Undeclared(instruction);
            if (node->type == funcStr || node->type == funcNum)
                throw TypeMismatch(instruction);
            num_comp += temp;
            num_splay += splay(this->root, node);
            tempStr1 = ((node->type == number) ? "number" : "string");
        }
        if (tempStr1 != tempStr2) throw TypeMismatch(instruction);
        params.erase(1, posEnd1);
        posEnd1 = params.find(',');
        posEnd1 = (posEnd1 != string::npos) ? posEnd1 : params.find(')');
        typeParam.erase(1, posEnd2);
        posEnd2 = typeParam.find(',');
        posEnd2 = (posEnd2 != string::npos) ? posEnd2 : typeParam.find(')');
        node = nullptr;
    }
    if (posEnd1 == string::npos && posEnd2 == string::npos);
    else throw TypeMismatch(instruction);
    node = nullptr;
}

Type typeValue(string value, string &nameFunc, string &params)
{
    int length = value.length();
    if (value[0] == '\'' && value[length - 1] == '\'') {
        for (int i = 1; i < length - 1; ++i) {
            if (value[i] >= 'a' && value[i] <= 'z'); 
            else if (value[i] >= 'A' && value[i] <= 'Z');
            else if (value[i] >= '0' && value[i] <= '9');
            else if (value[i] == ' ');
            else
                return error;            
        }
        return str;
    } else if (value[length - 1] == ')') {
        size_t posParen = value.find('(');
        if (posParen == string::npos || posParen < 1) return error;
        string temp_1 = value.substr(0, posParen);
        if (!validIdentifier(temp_1)) return error;
        string temp_2 = value.substr(posParen);
        if (!validValueParam(temp_2)) return error;
        nameFunc = temp_1;
        params = temp_2;
        return funct;
    } else if (validIdentifier(value)) {
        return nameIden;
    } else {
        for (int i = 0; i < length; ++i) {
            if (value[i] >= '0' && value[i] <= '9');
            else
                return error;
        }
        return number;
    }
}

void SymbolTable::run(string filename)
{
    ifstream ifs;
    ifs.open(filename);
    string line;
    while (getline(ifs, line))
    {
        size_t posSpace = line.find(' ');
        string instruction;
        if (posSpace == string::npos)   
            instruction = line;
        else
            instruction = line.substr(0, posSpace);
        if (instruction == "INSERT") {
            string identifier;
            size_t secondPosSpace = line.find(' ', posSpace + 1);
            if (secondPosSpace == string::npos || secondPosSpace <= posSpace + 1) 
                throw InvalidInstruction(line);
            identifier = line.substr(posSpace + 1, secondPosSpace - posSpace - 1);
            size_t thirdPosSpace = line.find(' ', secondPosSpace + 1);
            if (thirdPosSpace == string::npos || thirdPosSpace <= secondPosSpace + 1) 
                throw InvalidInstruction(line);
            string typeStr = line.substr(secondPosSpace + 1, thirdPosSpace - secondPosSpace - 1);
            string params;
            Type type = checkType(typeStr, params);
            if (!validIdentifier(identifier) || type == error) 
                throw InvalidInstruction(line);
            bool isStatic = false;
            string temp = line.substr(thirdPosSpace + 1);
            if (temp == "true") isStatic = true;
            else if (temp == "false") isStatic = false;
            else throw InvalidInstruction(line);
            insert(line, identifier, type, isStatic, params);
        } else if (instruction == "ASSIGN") {
            string identifier, value;
            size_t secondPosSpace = line.find(' ', posSpace + 1);
            if (secondPosSpace == string::npos || secondPosSpace <= posSpace + 1) {
                throw InvalidInstruction(line);
            }
            identifier = line.substr(posSpace + 1, secondPosSpace - posSpace - 1);
            value = line.substr(secondPosSpace + 1);
            string nameFunc, params;
            Type type = typeValue(value, nameFunc, params);
            if (!validIdentifier(identifier) || type == error) {
                throw InvalidInstruction(line);
            }
            assign(line, identifier, value, type, nameFunc, params);            
        } else if (instruction == "BEGIN" || instruction == "END") {
            block(instruction);
        } else if (instruction == "LOOKUP") {
            string identifier;
            identifier = line.substr(posSpace + 1);
            if (!validIdentifier(identifier)) {
                throw InvalidInstruction(line);
            }
            lookup(line, identifier);
        } else if (instruction == "PRINT") {
            print();
        } else {
            throw InvalidInstruction(line);
        }
    }
    if (this->currentLevel > 0) {
        throw UnclosedBlock(this->currentLevel);
    }
    this->clear();
    ifs.close();
}

void SymbolTable::rotatewithLeftChild(Node* &nodeRoot, Node* &par)
{
    Node *child = par->left;
    par->left = child->right;
    if (child->right != nullptr) child->right->parent = par;
    if (par != nodeRoot) {
        if (par->compare(par->parent) < 0) par->parent->left = child;
        else par->parent->right = child;
    } else {
        nodeRoot = child;
    }
    child->right = par;
    child->parent = par->parent;
    par->parent = child;
    par = child;
}

void SymbolTable::rotatewithRightChild(Node* &nodeRoot, Node* &par)
{
    Node *child = par->right;
    par->right = child->left;
    if (child->left != nullptr) child->left->parent = par;
    if (par != nodeRoot) {
        if (par->compare(par->parent) < 0) par->parent->left = child;
        else par->parent->right = child;
    } else {
        nodeRoot = child;
    }
    child->left = par;
    child->parent = par->parent;
    par->parent = child;
    par = child;
}

int SymbolTable::splay(Node* &nodeRoot, Node* &node)
{
    if (node == nullptr || nodeRoot == nullptr || node->compare(nodeRoot) == 0) return 0;
    Node* par = node->parent;
    Node* grand = par->parent;
    if (node->compare(par) < 0)
    {
        if (par == nodeRoot) {
            rotatewithLeftChild(nodeRoot, par);
        } else {
            if (par->compare(grand) < 0)
            {
                rotatewithLeftChild(nodeRoot, grand);
                rotatewithLeftChild(nodeRoot, par);
            }
            else 
            {
                rotatewithLeftChild(nodeRoot, par);
                rotatewithRightChild(nodeRoot, grand);
            }
        }
        splay(nodeRoot, node);
        return 1;
    } else
    {
        if (par == nodeRoot) {
            rotatewithRightChild(nodeRoot, par);
        } else {
            if (par->compare(grand) > 0)
            {
                rotatewithRightChild(nodeRoot, grand);
                rotatewithRightChild(nodeRoot, par);
            }
            else 
            {
                rotatewithRightChild(nodeRoot, par);
                rotatewithLeftChild(nodeRoot, grand);
            }
        }
        splay(nodeRoot, node);
        return 1;      
    }
}

int SymbolTable::insertRec(Node* &nodeRoot, string identifier, int levelOfBlock, Node* &newNode)
{
    if (nodeRoot == nullptr) {
        nodeRoot = new Node(identifier, levelOfBlock);
        newNode = nodeRoot;
        return 0;
    }
    else {
        if (nodeRoot->compare(levelOfBlock, identifier) > 0) { 
            if (nodeRoot->left == nullptr) {
                nodeRoot->left = new Node(identifier, levelOfBlock);
                nodeRoot->left->parent = nodeRoot;
                newNode = nodeRoot->left;
                return 1;
            } else {
                return 1 + insertRec(nodeRoot->left, identifier, levelOfBlock, newNode);
            }
        } else {
            if (nodeRoot->right == nullptr) {
                nodeRoot->right = new Node(identifier, levelOfBlock);
                nodeRoot->right->parent = nodeRoot;
                newNode = nodeRoot->right;
                return 1;
            } else {
                return 1 + insertRec(nodeRoot->right, identifier, levelOfBlock, newNode);
            }
        }
    }
}

int SymbolTable::containsNode(Node* nodeRoot, string identifier, int levelOfBlock, Node* &node)
{
    if (nodeRoot == nullptr) return 0;
    if (nodeRoot->compare(levelOfBlock, identifier) == 0) {
        node = nodeRoot;
        return 1;
    } else if (nodeRoot->compare(levelOfBlock, identifier) > 0) {
        return 1 + containsNode(nodeRoot->left, identifier, levelOfBlock, node);
    } else {
        return 1 + containsNode(nodeRoot->right, identifier, levelOfBlock, node);
    }
}

// int SymbolTable::containsFunc(Node* nodeRoot, string identifier, string params, Node* &node)
// {
//     if (nodeRoot == nullptr) return 0;
//     if (nodeRoot->compare(0, identifier) == 0 && nodeRoot->params == params) {
//         node = nodeRoot;
//         return 1;
//     } else if (nodeRoot->compare(0, identifier) > 0) {
//         return 1 + containsFunc(nodeRoot->left, identifier, params, node);
//     } else {
//         return 1 + containsFunc(nodeRoot->right, identifier, params, node);
//     }
// }

void SymbolTable::insert(string instruction, string identifier, Type type, bool isStatic, string params)
{
    int scope = (isStatic) ? 0 : this->currentLevel;
    if ((type == funcNum || type == funcStr) && scope > 0)
        throw InvalidDeclaration(instruction);
    Node* node = nullptr;
    containsNode(this->root, identifier, scope, node);
    if (node != nullptr) throw Redeclared(instruction);
    Node *newNode = nullptr;
    cout << insertRec(this->root, identifier, scope, newNode) << " " << splay(this->root, newNode) << endl;
    newNode->type = type; 
    if (newNode->type == funcNum || newNode->type == funcStr) newNode->params = params;
    newNode = nullptr;
    if (scope > 0) {
        string temp = identifier + "//" + to_string(scope) + " ";
        removedList += temp;
    }
    ++(this->size);
    // print();
}

// void SymbolTable::assign(string instruction, string identifier, string value, Type type, string nameFunc, string params)
// {
//     Node* nodeValue = nullptr;
//     int num_comp = 0, num_splay = 0;
//     if (type == funct)
//     {
//         for (int i = currentLevel; i >= 0; --i) {
//             num_comp = containsNode(this->root, nameFunc, i, nodeValue);
//             if (nodeValue != nullptr) break;
//         }
//         if (nodeValue != nullptr) {
//             if (nodeValue->type != funcNum && nodeValue->type != funcStr)
//                 throw TypeMismatch(instruction);
//             num_splay += splay(this->root, nodeValue);
//             params = equalTypeParam(instruction, params, num_comp, num_splay);
//             if (params != nodeValue->params) 
//                 throw TypeMismatch(instruction);
//         } else {
//             throw Undeclared(instruction);
//         }
//     } else if (type == nameIden) 
//     {
//         for (int i = currentLevel; i >= 0; --i) {
//             num_comp = containsNode(this->root, value, i, nodeValue);
//             if (nodeValue != nullptr) break;
//         }
//         if (nodeValue == nullptr) throw Undeclared(instruction);
//         if (nodeValue->type != number && nodeValue->type != str)
//             throw TypeMismatch(instruction);
//         num_splay += splay(this->root, nodeValue);
//     }
//     int temp_comp = 0;
//     Node* node = nullptr;
//     for (int i = currentLevel; i >= 0; --i) {
//         temp_comp = containsNode(this->root, identifier, i, node);
//         if (node != nullptr) break;
//     }
//     if (node == nullptr) throw Undeclared(instruction);
//     if (node->type == funcNum || node->type == funcStr)
//         throw TypeMismatch(instruction);
//     if (type == number || type == str) {
//         if (type != node->type) throw TypeMismatch(instruction);
//     } else if (type == nameIden) {
//         if (node->type != nodeValue->type) throw TypeMismatch(instruction);
//     } else if (type == funct) {
//         if (node->type == number && nodeValue->type == funcNum);
//         else if (node->type == str && nodeValue->type == funcStr);
//         else throw TypeMismatch(instruction);
//     }
//     num_comp += temp_comp;
//     num_splay += splay(this->root, node);
//     nodeValue = nullptr;
//     node = nullptr;
//     cout << num_comp << " " << num_splay << endl;
// }

void SymbolTable::assign(string instruction, string identifier, string value, Type type, string nameFunc, string params)
{
    Node* nodeValue = nullptr;
    int num_comp = 0, num_splay = 0;
    if (type == funct)
    {
        for (int i = currentLevel; i >= 0; --i) {
            num_comp = containsNode(this->root, nameFunc, i, nodeValue);
            if (nodeValue != nullptr) break;
        }
        if (nodeValue != nullptr) {
            if (nodeValue->type != funcNum && nodeValue->type != funcStr)
                throw TypeMismatch(instruction);
            num_splay += splay(this->root, nodeValue);
            equalTypeParam(instruction, params, nodeValue->params, num_comp, num_splay);
        } else {
            throw Undeclared(instruction);
        }
    } else if (type == nameIden) 
    {
        for (int i = currentLevel; i >= 0; --i) {
            num_comp = containsNode(this->root, value, i, nodeValue);
            if (nodeValue != nullptr) break;
        }
        if (nodeValue == nullptr) throw Undeclared(instruction);
        if (nodeValue->type != number && nodeValue->type != str)
            throw TypeMismatch(instruction);
        num_splay += splay(this->root, nodeValue);
    }
    int temp_comp = 0;
    Node* node = nullptr;
    for (int i = currentLevel; i >= 0; --i) {
        temp_comp = containsNode(this->root, identifier, i, node);
        if (node != nullptr) break;
    }
    if (node == nullptr) throw Undeclared(instruction);
    if (node->type == funcNum || node->type == funcStr)
        throw TypeMismatch(instruction);
    if (type == number || type == str) {
        if (type != node->type) throw TypeMismatch(instruction);
    } else if (type == nameIden) {
        if (node->type != nodeValue->type) throw TypeMismatch(instruction);
    } else if (type == funct) {
        if (node->type == number && nodeValue->type == funcNum);
        else if (node->type == str && nodeValue->type == funcStr);
        else throw TypeMismatch(instruction);
    }
    num_comp += temp_comp;
    num_splay += splay(this->root, node);
    nodeValue = nullptr;
    node = nullptr;
    cout << num_comp << " " << num_splay << endl;
}

void SymbolTable::remove(string identifier, int levelOfBlock)
{
    if (root == nullptr) return;
    Node* node = nullptr;
    containsNode(this->root, identifier, levelOfBlock, node);
    if (node == nullptr) {
        return;
    }
    splay(this->root, node);
    if (root->left == nullptr && root->right == nullptr) {
        this->root = nullptr;
        delete node;
        node = nullptr;
    } else if (root->left == nullptr) {
        root = root->right;
        root->parent = nullptr;
        delete node;
        node = nullptr;  
    } else if (root->right == nullptr) {
        root = root->left;
        root->parent = nullptr;
        delete node;
        node = nullptr;      
    } else {
        Node* current = root->left;
        while (current->right != nullptr)
        {
            current = current->right;
        }
        splay(root->left, current);
        root = root->left;
        root->parent = nullptr;
        root->right = node->right;
        if (node->right != nullptr) node->right->parent = root;
        delete node;
        node = nullptr;
    }
    --(this->size);
    // print();
}

void SymbolTable::block(string instruction)
{
    if (instruction == "BEGIN") ++currentLevel;
    else {
        if (currentLevel - 1 < 0)
            throw UnknownBlock();
        if (removedList.empty()) {
            --currentLevel;
        } else {
            string levelStr = ("//" + to_string(currentLevel));
            size_t posLevel = removedList.find(levelStr);
            while (!removedList.empty() && posLevel != string::npos)
            {
                size_t posFirst = removedList.rfind(" ", posLevel);
                if (posFirst == string::npos) posFirst = 0;
                else posFirst = posFirst + 1;
                string name = removedList.substr(posFirst, posLevel - posFirst);
                remove(name, currentLevel);
                removedList.erase(posLevel, levelStr.length() + 1);
                removedList.erase(posFirst, posLevel - posFirst);
                posLevel = removedList.find(levelStr);
            }
            --currentLevel;
        }
    }
}

void SymbolTable::lookup(string instruction, string identifier)
{
    Node* node = nullptr;
    for (int i = currentLevel; i >= 0; --i)
    {
        containsNode(this->root, identifier, i, node);
        if (node != nullptr)
        {
            cout << i << endl;
            break;
        }
    }
    if (node == nullptr) throw Undeclared(instruction);
    splay(this->root, node);
    node = nullptr;
}

void SymbolTable::printRec(Node *nodeRoot)
{
    if (nodeRoot == nullptr) return;
    static int count = 0;
    ++count;
    if (count < this->size) {
        cout << nodeRoot->identifier << "//" << nodeRoot->levelOfBlock << " ";
    } else {
        cout << nodeRoot->identifier << "//" << nodeRoot->levelOfBlock << endl;
        count = 0;
    }
    printRec(nodeRoot->left);
    printRec(nodeRoot->right);
}

void SymbolTable::print()
{
    printRec(this->root);
}

void SymbolTable::clearRec(Node* &nodeRoot)
{
    if (nodeRoot == nullptr) return;
    clearRec(nodeRoot->left);
    clearRec(nodeRoot->right);
    delete nodeRoot;
    nodeRoot = nullptr;
}

void SymbolTable::clear()
{
    clearRec(this->root);
}

int foo(string params)
{
    if (params == "()") return 0;
    int count = 1;
    size_t posComma = params.find(',');
    while (posComma != string::npos) {
        if (posComma <= 1 || posComma + 2 >= params.length()) return -1;
        string temp = params.substr(1, posComma - 1);
        if (temp != "number" && temp != "string") return -1;
        ++count;
        params.erase(1, posComma);
        posComma = params.find(',');
    }
    if (params == "(number)" || params == "(string)") return count;
    return -1;   
}

int main()
{
    // SplayTree tree;
    // tree.insert(70); tree.insert(87); tree.insert(94); 
    // tree.insert(76); tree.insert(37); tree.insert(90);
    // tree.insert(39); tree.insert(4); tree.insert(15);
    // tree.insert(20); tree.insert(11); tree.insert(89);
    // tree.insert(57); tree.insert(63); tree.insert(6);
    // tree.insert(92); tree.insert(50);
    // cout << tree.contains(70) << endl;
    // cout << tree.contains(15) << endl;
    // cout << tree.contains(15) << endl;
    // cout << tree.contains(63) << endl;
    // tree.remove(63);
    // tree.remove(87);
    // string value = "sum(12,'abc')";
    // string nameFunc, params;
    // Type type = typeValue(value, nameFunc, params);
    // if (type == number) cout << "number" << endl;
    // else if (type == str) cout << "string" << endl;
    // else if (type == funct) cout << "function" << endl;
    // else if (type == error) cout << "error" << endl;
    // else cout << "nil" << endl;
    // if (!nameFunc.empty()) cout << nameFunc << endl;
    // if (!params.empty()) cout << params << endl;
    // SymbolTable table;
    // table.run("testcase.txt");
    string params = "(number,string,number,number,)";
    cout << foo(params) << endl;
    cout << "I'm here with GitHub. Who is the author here?" << endl;
    return 0;
}
