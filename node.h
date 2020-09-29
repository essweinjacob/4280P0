#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;

typedef struct Node{
    char letter;
    int asiccValue;
    struct Node *left, *right;
    string words[99];
    int wordCount;
}Node;

#endif