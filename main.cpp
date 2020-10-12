#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "tree.h"
#include "traversal.h"
using namespace std;

int main(int argc, char *argv[]){
    Node *root = NULL;
    string fileName;
    if(argc == 2){
        //cout << "File given: " << argv[1] << endl;
        fileName = argv[1];
        root = buildTree(fileName);
        if(root == NULL){
            cerr << "No binary search tree given. PROGRAM FAILED" << endl;
            return EXIT_FAILURE;
        }
    }
    else if(argc == 1){
        cout << "No file given" << endl;
        // Create a file to write to
        fileName = "out";
        ofstream tempFile;
        string userInput;
        tempFile.open(fileName);
        
        cout << "Enter strings and close file when done: " << endl;
        while(getline(cin, userInput)){
            tempFile << userInput << " ";
        }
        cout << endl << "Finished inputing strings/words" << endl;

        tempFile.close();
        root = buildTree(fileName);

    }
    else{
        cerr << "You gave more then one command line argument. PROGRAM FAILED" << endl;
    }

    ofstream traversalFile;
    int level = -1;
 
    traversalFile.open(fileName + ".inorder");
    printInorder(root, level, traversalFile);
    traversalFile.close();

    traversalFile.open(fileName + ".preorder");
    printPreorder(root, level, traversalFile);
    traversalFile.close();

    traversalFile.open(fileName + ".postorder");
    printPostorder(root, level, traversalFile);
    traversalFile.close();

    return 0;
}