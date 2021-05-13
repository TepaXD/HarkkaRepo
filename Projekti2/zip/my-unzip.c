#include <stdlib.h>
#include <stdio.h>
#define TRUE 1

int main(int argc, char *argv[])
{
    FILE *file;

    if (argc < 2)
    {
        printf("my-unzip: file1 [file2...]\n");
        exit(1);
    }

    for(int i = 1; i<argc; i++){
        file = fopen(argv[i], "r");

        if(file == NULL) {
        printf("error: cannot open file '%s'\n", argv[i]);
        exit(1);
        }

        while(TRUE){
        int amount;
        if(fread(&amount, sizeof amount, 1, file) != 1) {
            break;
            }
        char character;
        if(fread(&character, sizeof character, 1, file) != 1) {
            break;
            }
        for(int i = 0; i < amount; i++){
            printf("%c", character);
            }
        }
        fclose(file); 
    }
    printf("\n");
exit(0);
}