#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "tree.h"
using namespace std;

// This function will build a tree
Node *buildTree(string fileName){
    Node *root = NULL;  // Create a base root node
    // Open given file
    fstream inputFile;
    inputFile.open(fileName.c_str());
    // Check if file exists
    if(inputFile){
        //cout << "File " << fileName << " exists" << endl;
        // Read through file
        string word;
        // While words in file, input words into tree/nodes
        while(inputFile >> word){
            //cout << word << endl;
            root = insertWord(word, root);
        }
    }
    // If the file exists return NULL
    else{
        cout << "File does not exists" << endl;
        return NULL;
    }
    inputFile.close();
    return root;
}

// This function inputs words into nodes or creates nodes if a node doesnt already exist for the first letter of the word
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

// This function creates new nodes as needed
Node *createNode(string word){
    // Assigns values
    struct Node *temp = (Node*)malloc(sizeof(Node));
	cout << "1\n";
    temp->letter = word[0];
cout << "2\n";
    temp->asiccValue = (int)word[0];
cout << "3\n";
    temp->words[temp->wordCount] = word;
cout << "4\n";
    temp->wordCount++;
    return temp;
}
