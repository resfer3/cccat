#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFERSIZE 128


int printFile(char *filename, FILE** read_file);

int main(int argc, char *argv[]){

    //err handling
    if (argc != 2){
        printf("Usage: ./cccat file\n"); 
        return 1;
    }
   
    FILE *input;

    //NOTE TO SELF: 07/06
    //MAKE THE BELOW CODE TO A FUNCTION TO WRITE TO STDOUT
    //SO IT WILL BE ABLE TO GET MORE DIVERSE OUTPUTS
    
    char *std = NULL;
    size_t len2 = 0;
    ssize_t read;
    
    printFile(argv[1], &input);

    while ((read = getline(&std, &len2, stdin)) != -1){
        printf("%s", std);
    }
    


    
    //write contents to stdout
    return 0;    

}

int printFile(char *filename, FILE **read_file){
    //read from command line
    //print file
    
    //declare
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    *read_file = fopen(filename, "r");
    if(*read_file == NULL){
        return 1;
    }
    while ((read = getline(&line, &len, *read_file)) != -1){
        printf("%s", line);
    }
    if (*read_file != NULL){
        fclose(*read_file);
    }
    exit(0);
    return 0;
}

















