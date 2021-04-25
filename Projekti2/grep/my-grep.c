#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "my-grep: searchterm [file...]\n");
        exit(1);
    } else if(argc == 2) {
        //for some reason, passing exactly one cmdline argument will cause the program to do nothing
        char *buffer = NULL;
        size_t line_buffer = 0;
        buffer = (char *)malloc(line_buffer + 1);
        printf("give input to grep: ");
        getline(&buffer, &line_buffer, stdin);

        do {
            if(strstr(buffer, argv[1]) != NULL) {
                fprintf(stdout, "%s\n", buffer);
            }
        } while(getline(&buffer, &line_buffer, stdin) >= 0);
    } else {
        for(int i = 2; i < argc; i++) { //i = first argument that is a file in argv
            size_t line_buffer = 0; //dynamic buffer that scales
            char *buffer;
            FILE *file;
            file = fopen(argv[i], "r");

            if(file == NULL) {
                fprintf(stderr,"my-grep: cannot open file\n");
                exit(1);
            }

            buffer = (char *)malloc(line_buffer);

            if(buffer == NULL) {
                fprintf(stderr, "malloc failed\n");
                exit(1);
            }

            do {
                if(strstr(buffer, argv[1]) != NULL) {
                    fprintf(stdout, "%s\n", buffer);
                }

            } while(getline(&buffer, &line_buffer, file) >= 0);

            fclose(file);
        }
    }
    exit(0);
}