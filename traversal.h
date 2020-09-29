#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include "node.h"
#include <fstream>

void printInorder(Node *root ,int level, ofstream &traversalFile);
void printPostorder(Node *root, int level, ofstream &traversalFile);
void printPreorder(Node *root, int level, ofstream &traversalFile);

#endif