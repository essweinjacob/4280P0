#ifndef NODE_H
#define NODE_H
#include <string>
#include <set>
#include <vector>
using namespace std;

typedef struct Node{
    char letter;
    int asiccValue;
    struct Node *left, *right;
    set<string> words;
    int wordCount;
}Node;

#endif
