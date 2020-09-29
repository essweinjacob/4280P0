#include <iostream>
#include <string>
#include <fstream>
#include "tree.h"
using namespace std;

Node *buildTree(string fileName){
    Node *root = NULL;
    fstream inputFile;
    inputFile.open(fileName);
    // Check if file exists
    if(inputFile){
        //cout << "File " << fileName << " exists" << endl;
        // Read through file
        string word;
        while(inputFile >> word){
            //cout << word << endl;
            root = insertWord(word, root);
        }
    }
    else{
        cout << "File does not exists" << endl;
        return NULL;
    }
    inputFile.close();
    return root;
}

Node *insertWord(string word, Node *node){
    // If no nodes in the in the tree yet
    if(node == NULL){
        return createNode(word);
    }
    // If this letter already exists in the BST
    else if(node->asiccValue == (int)word[0]){
        bool wordExistFlag = false;
        //  See if word already exists in the node
        for(int i = 0; i < node->wordCount; i++){
            if(word == node->words[i]){
                wordExistFlag = true;
            }
        }
        // If word already exists dont input word
        if(!wordExistFlag){
            node->words[node->wordCount] = word;
            node->wordCount++;
        }
        return node;
    }
    // If given first letter of word is greater then current node
    if(word[0] > node->letter){
        node->right = insertWord(word, node->right);
    }
    // If given first letter of word is less then current node
    else if(word[0] < node->letter){
        node->left = insertWord(word, node->left);
    }
    
    return node;
}

Node *createNode(string word){
    struct Node *temp = (Node*)malloc(sizeof(Node));
    temp->letter = word[0];
    temp->asiccValue = (int)word[0];
    temp->words[temp->wordCount] = word;
    temp->wordCount++;
    return temp;
}