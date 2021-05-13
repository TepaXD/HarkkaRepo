#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

int main(int argc, char *argv[])
{
    //check for input files
    if (argc < 2)
    {
        printf("my-zip: file1 [file2...]\n");
        exit(1);
    }

    for (int i = 1; i < argc; i++)
    {
        int character;
        int previous_character;
        int amount = 0;
        FILE *file;
        file = fopen(argv[i], "r");

        //error handling
        if (file == NULL)
        {
            printf("error: cannot open file '%s'\n", argv[i]);
            exit(1);
        }

        //read characters in the file
        while (TRUE)
        {
            character = fgetc(file);
            //write previous character to file if end-of-file is reached
            if (feof(file))
            {
                fwrite(&amount, sizeof(amount), 1, stdout);
                fwrite(&previous_character, 1, 1, stdout);
                break;
            }
            //if the current character is same as previous, add 1 to counter (amount)
            else if (character == previous_character)
            {
                previous_character = character;
                amount++;
                continue;
            }
            //if current character is different write the previous character to file
            else if (amount != 0)
            {
                fwrite(&amount, sizeof(amount), 1, stdout);
                fwrite(&previous_character, 1, 1, stdout);
            }
            amount = 1;
            previous_character = character;
        }
        fclose(file);
    }
    exit(0);
}