#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    //err handling
    if (argc != 2){
        printf("Usage: ./cccat file\n"); 
        return 1;
    }
   /* if (argv[1]){

        printf("%s\n", argv[1]);
    }*/


    //open file from command-line argument
    FILE *file = fopen(argv[1], "r"); 
    if (file == NULL){
    //if file is null, read from standard in
        printf("Couldn't find stdin\n");
        return 1;
    }

    //write contents to stdout
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file))!= -1){
    
        //printf("Success\n");
        printf("line of length %zu : \n", read);
        printf("%s", line);

    }
    free(file);
    

}
