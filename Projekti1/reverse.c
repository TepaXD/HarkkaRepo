#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//linked list node
typedef struct NODE
{
    char *data;
    struct NODE *next;
} Node;

void readUserInput();
void printFromFile(char *argv[]);
void reverseList(Node **head);
void reverseToFile(char *argv[]);
void reverse(char *begin, char *end);
void reverseWords(char *s);

//main function
int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        fprintf(stderr, "usage: reverse <input> <output>\n");
        exit(1);
    }

    if (argc == 1)
    {
        readUserInput();
    }
    else if (argc == 2)
    {
        printFromFile(argv);
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], argv[2]) == 0)
        {
            fprintf(stderr, "input and output file must differ\n");
            exit(1);
        }
        reverseToFile(argv);
    }
    exit(0);
}

//method that reads user input
void readUserInput()
{
    char *buffer = NULL;
    size_t line_buffer = 0;

    buffer = (char *)malloc(line_buffer + 1);
    printf("give input to reverse: ");
    getline(&buffer, &line_buffer, stdin);

    reverseWords(buffer);
    fprintf(stdout, "%s\n", buffer);
}

//tutorial for these two methods below was found in https://www.geeksforgeeks.org/reverse-words-in-a-given-string/
//their point is to mirror users input
void reverse(char *begin, char *end)
{
    char temporary;
    while (begin < end)
    {
        temporary = *begin;
        *begin++ = *end;
        *end-- = temporary;
    }
}

// Function to reverse words*/
void reverseWords(char *input)
{
    char *word_begin = input;

    char *temporary = input;

    while (*temporary)
    {
        temporary++;
        if (*temporary == '\0')
        {
            reverse(word_begin, temporary - 2);
        }
        else if (*temporary == ' ')
        {
            reverse(word_begin, temporary - 1);
            word_begin = temporary + 1;
        }
    }

    reverse(input, temporary - 1);
}

//method to read from a file thats content length is unknown and prints it to stdout
//reads each method to linked list that is then passed to method for flipping the list around
void printFromFile(char *argv[])
{
    char *buffer = NULL;
    size_t line_buffer = 0;
    FILE *file;
    ssize_t line_size;
    Node *current, *head;

    head = current = NULL;

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    line_size = getline(&buffer, &line_buffer, file);

    do
    {
        Node *node = malloc(sizeof(Node));
        if (node == NULL)
        {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        node->data = strdup(buffer);
        node->next = NULL;

        if (head == NULL)
        {
            current = head = node;
        }
        else
        {
            current = current->next = node;
        }

        line_size = getline(&buffer, &line_buffer, file);
    } while (line_size >= 0);

    free(buffer);
    buffer = NULL;
    fclose(file);

    printf("\n");
    reverseList(&head);
    for (current = head; current; current = current->next)
    {
        fprintf(stdout, "%s", current->data);
    }
}

//method to reverse a linked list
void reverseList(Node **head)
{
    Node *previous = NULL;
    Node *current = *head;
    Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;

    Node *temp = *head;
}

//saves content from file like earlier, but saves it to an output file
void reverseToFile(char *argv[])
{
    char *buffer = NULL;
    size_t line_buffer = 0;
    FILE *inputfile;
    FILE *outputfile;
    ssize_t line_size;
    Node *current, *head;

    head = current = NULL;

    inputfile = fopen(argv[1], "r");

    if (inputfile == NULL)
    {
        fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    line_size = getline(&buffer, &line_buffer, inputfile);

    do
    {
        Node *node = malloc(sizeof(Node));
        if (node == NULL)
        {
            fprintf(stderr, "malloc failed\n");
            exit(1);
        }
        node->data = strdup(buffer);
        node->next = NULL;

        if (head == NULL)
        {
            current = head = node;
        }
        else
        {
            current = current->next = node;
        }

        line_size = getline(&buffer, &line_buffer, inputfile);
    } while (line_size >= 0);
    free(buffer);
    buffer = NULL;
    fclose(inputfile);

    outputfile = fopen(argv[2], "w");
    if (outputfile == NULL)
    {
        fprintf(stderr, "error: cannot open file '%s'\n", argv[2]);
        exit(1);
    }
    reverseList(&head);
    for (current = head; current; current = current->next)
    {
        fprintf(outputfile, "%s", current->data);
    }
}