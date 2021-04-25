#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {

  for (int i = 1; i <= argc-1; i++){
      char buffer[400];
      FILE *file;
      file = fopen(argv[i], "r");
      if (file == NULL) {
	printf("File wasn't opened\n");
	exit(1);
      }

      while(fgets(buffer, 399, file) != NULL) {
	printf("%s\n", buffer);
      }
      fclose(file);
    }
  return 0;
}
