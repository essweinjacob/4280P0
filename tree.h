#ifndef TREE_H
#define TREE_H
#include "node.h"
#include <string>
using namespace std;

Node *buildTree(string fileName);
Node *insertWord(string word, Node *node);
Node *createNode(string word);

#endif