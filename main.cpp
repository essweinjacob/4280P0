#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "tree.h"
#include "traversal.h"
using namespace std;

int main(int argc, char *argv[]){
    Node *root = NULL;  // Initialize tree
    string fileName;    // String for name of value
    if(argc == 2){
        //cout << "File given: " << argv[1] << endl;
        fileName = argv[1];     // If file name given assign it to fileName variabled
        root = buildTree(fileName); // Build tree
        // If no tree is generated send error message and exit program
        if(root == NULL){
            cerr << "No binary search tree given. PROGRAM FAILED" << endl;
            return EXIT_FAILURE;
        }
    }
    // If not file name given
    else if(argc == 1){
        //cout << "No file given" << endl;
        // Create a file to write to
        fileName = "out";   // Change file name to temporary file
        ofstream tempFile;  // Create a file to write to
        string userInput;   // Get user input
        tempFile.open(fileName);   
        
        // Write to file while user is not done inputing
        cout << "Enter strings and close file when done: " << endl;
        while(getline(cin, userInput)){
            tempFile << userInput;
        }
        cout << endl << "Finished inputing strings/words" << endl;

        tempFile.close();   // Close file
        root = buildTree(fileName); // Build tree

    }
    // If invalid number of arguments given
    else{
        cerr << "You gave more then one command line argument. PROGRAM FAILED" << endl;
        return EXIT_FAILURE;
    }
    
    ofstream traversalFile; // Create files for inorder, preorder and post order traversal.
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