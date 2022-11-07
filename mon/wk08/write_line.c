// code that reads in a file's firs tline, and prints it to the terminal

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // fopen returns a file pointer used to access file
    FILE *stream = fopen(argv[1], "w");
    if (stream == NULL) {
        // couldn't open the file, print an error message
        // to standard error
        fprintf(stderr, "%s: ", argv[0]);
        perror(argv[1]);
        return 1;
    }

    // read characters in for a line, printing it into the named file
    int next_char = getchar();
    // while ((next_char = getchar()) != '\n' && next_char != EOF) {
    while (next_char != '\n' && next_char != EOF) {
        fputc(next_char, stream);
        next_char = getchar();
    }
    fputc('\n', stream);

    // close the file, as the program is about to exit
    // this isn't necessary here but is good practice
    fclose(stream);
    return 0;
}
