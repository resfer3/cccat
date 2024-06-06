#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>

int main(int argc, char *argv[]){

    //err handling
    if (argc != 2){
        printf("Usage: ./cccat file\n"); 
        return 1;
    }

    //open file from command-line argument
    FILE *file = fopen(argv[1], "r"); 
    if (file == NULL){
        printf("Couldn't find file\n");
        return 1;
    }

    //write contents to stdout
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, file))!= -1){
    
        //printf("Success\n");
        printf("%s", line);

    }
    

}
