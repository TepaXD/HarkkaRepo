#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

  for (int i = 1; i <= argc-1; i++){
      char buffer[400]; //Reserving memory for the contents
      FILE *file;	
      file = fopen(argv[i], "r"); //Getting the filename from the commandline argument and opening file
      if (file == NULL) {	//Error handling incase the file doesn't work
	printf("File wasn't opened\n");
	exit(1);
      }
	
      while(fgets(buffer, 399, file) != NULL) {	//Print the contents of "buffer"
	printf("%s\n", buffer);
      }
      fclose(file);	//close file
    }
  return 0;
}
