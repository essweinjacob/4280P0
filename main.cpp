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
            return 0;
        }
    }
    else if(argc == 1){
        cout << "No file given" << endl;
        // Create a file to write to
        fileName = "out";
        ofstream tempFile;
        string userInput;
        tempFile.open(fileName.c_str());
        
        cout << "Enter strings and close file when done: " << endl;
        while(getline(cin, userInput)){
            tempFile << userInput << " ";
        }
        cout << endl << "Finished inputing strings/words" << endl;

        tempFile.close();
	cout << "1\n";
        root = buildTree(fileName);
	cout << "2\n";

    }
    else{
        cerr << "You gave more then one command line argument. PROGRAM FAILED" << endl;
	return 0;
    }

    ofstream traversalFile;
    int level = -1;


    string inorderFile = fileName + ".inorder";
    traversalFile.open(inorderFile.c_str());
    printInorder(root, level, traversalFile);
    traversalFile.close();

    string preorderFile = fileName + ".preorder";
    traversalFile.open(preorderFile.c_str());
    printPreorder(root, level, traversalFile);
    traversalFile.close();

    string postorderFile = fileName + ".postorder";
    traversalFile.open(postorderFile.c_str());
    printPostorder(root, level, traversalFile);
    traversalFile.close();

    return 0;
}
