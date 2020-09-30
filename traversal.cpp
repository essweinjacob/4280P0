#include <iostream>
#include <string>
#include <fstream>
#include "traversal.h"
#include "node.h"
using namespace std;

// Prints BST in Inorder
void printInorder(Node *root, int level, ofstream &traversalFile){
    level++;
    if(root != NULL){
        printInorder(root->left, level, traversalFile);
        traversalFile << string(2*level, ' ') << root->letter << ": ";
        //cout << root->letter << ": ";
        for(int i = 0; i < root->wordCount; i++){
            traversalFile << root->words[i] << " ";
        }
        traversalFile << endl;
        printInorder(root->right, level, traversalFile);
    }
}

// Prints BST in Postorder
void printPostorder(Node *root, int level, ofstream &traversalFile){
    level++;
    if(root != NULL){
        printPostorder(root->left, level, traversalFile);
        printPostorder(root->right, level, traversalFile);
        traversalFile << string(2*level, ' ') << root->letter << ": ";
        //cout << root->letter << ": ";
        for(int i = 0; i < root->wordCount; i++){
            traversalFile << root->words[i] << " ";
        }
        traversalFile << endl;
    }
}

// Prints BST in preorder
void printPreorder(Node *root, int level, ofstream &traversalFile){
    level++;
    if(root != NULL){

        traversalFile << string(2*level, ' ') << root->letter << ": ";
        //cout << root->letter << ": ";
        for(int i = 0; i < root->wordCount; i++){
            traversalFile << root->words[i] << " ";
        }
        traversalFile << endl;
        printPreorder(root->left, level, traversalFile);
        printPreorder(root->right, level, traversalFile);
    }
}
