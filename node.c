#include <stdio.h>
#include <stdlib.h>

// Node object that will represent nodes in a BST
struct node{
    char key;   // character in each node
    int asiccValue;     // Asicc value of a character
    struct node *left, *right;  // Left and righ nodes
    int occurances;     // Number of times a node occurs
};

// This method creates new nodes given a character
struct node *newNode(char givenLetter){
    struct node *temp = (struct node*)malloc(sizeof(struct node));  // Create a 'temporary' node
    // Assign values
    temp->key = givenLetter;
    temp->asiccValue = (int)givenLetter;
    temp->occurances = 1;
    temp->left = temp->right = NULL;
    return temp;
}

// This method inserts ndoes into the tree
struct *node insertNode(struct node* node, char key){
    // If tree is already empty
    if(node == NULL){
        return newNode(key);
    }

    // Find place in tree
    // if node already in tree
    if(key == node->key){
        node->occurances++;
    }
    // If given node is less then current node go left
    else if((int)key < node->asiccValue){
        node->left = insertNode(node->left, key);
    }
    // If given node is more then current node go right
    else if((int)key > node->asiccValue){
        node->right = insertNode(node->right, key);
    } 

    // Return node
    return node;
}