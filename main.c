#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
    // See if too many command line arguments given
    if(argv > 2){
        printf("Too many command line arguments given.\n");
        return EXIT_FAILURE;
    }
    // If file given
    if(argv == 2){
        char filename[12] = argv[1];
        // Check if extension given or not
        if(strchr(filename, '.')){
            printf("File given with extension");
        }
        // No file name given
        else{
            printf("File given without extension");
        }
    }
    // If not file given, get keyboard input
    else{
        printf("No file given please enter string to parse through: ");
    }
}