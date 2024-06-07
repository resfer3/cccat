#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

#define BUFFERSIZE 128

int isBlank (char *line);

int main(int argc, char *argv[]){

    //err handling
    if (argc != 2){
        printf("Usage: ./cccat file\n"); 
        return 1;
    }
   

    FILE *input;
    /*
    (if (argv[1] == "-"){
       input = popen("!!", "r");
       if (input == NULL){
            printf("stdin Not Found\n");
            return 1;
       } else {

            while(fgets(path, sizeof(path), input) != NULL){
                printf("%s", path);
            }
       }
    }
    else {
        input = fopen(argv[1], "r");
        if (input == NULL){
        //if file is null, read from standard in
            printf("Couldn't find file\n");
            return 1;
        }    
    }
    */
    // if argv[1] is file; declare file
    // else argv[1] is -; declare stdin
    if (argv[1] == "-"){
        
    }
    else{
        input = fopen(argv[1], "r");
    }


    //NOTE TO SELF: 07/06
    //MAKE THE BELOW CODE TO A FUNCTION TO WRITE TO STDOUT
    //SO IT WILL BE ABLE TO GET MORE DIVERSE OUTPUTS




    
    //write contents to stdout
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, input))!= -1){
    
        //printf("Success\n");
        printf("line of length %zu : \n", read);
        printf("%s", line);

    }
    fclose(input);
    return 0;    

}

/*
// not needed
// return nonzero if line is a string containing only whitespaces, -1 otherwise
int isBlank (char *line){
    char *tmp;
    int is_blank = -1;
    // Loop through each character
    for (tmp = line; *tmp != '\0'; ++tmp){
        if(!isspace(*tmp)){
        // Found a non-whitespace character
        is_blank = 0;
        break;
        }
    }

    return is_blank;
}
*/
























