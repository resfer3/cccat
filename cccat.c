#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUFFERSIZE 128


int printFile(char *filename, FILE** read_file);

int main(int argc, char *argv[]){

    //err handling
    if (argc > 3){
        printf("Usage: ./cccat file\n"); 
        return 1;
    }
   
    FILE *input;
    FILE *input2;
    char data[argc + 1][100];
    // loop into string
    for (int i = 1; i < argc; i++){
        strcpy(data[i], argv[i]);
    }
    

    //NOTE TO SELF: 07/06
    //MAKE THE BELOW CODE TO A FUNCTION TO WRITE TO STDOUT
    //SO IT WILL BE ABLE TO GET MORE DIVERSE OUTPUTS
    
    char *std = NULL;
    size_t len2 = 0;
    ssize_t read;
    

    if (strcmp(data[1], "-") == 0){

        while ((read = getline(&std, &len2, stdin)) != -1){
            printf("%s", std);
        }
        return 0;
    }
    else if (data[1] != NULL || data[2] != NULL){

        printFile(data[1], &input);
        printFile(data[2], &input2);
    
    }
    


    //free(data); 
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
    return 0;
}

















