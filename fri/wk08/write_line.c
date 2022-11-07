// code that reads in a file's firs tline, and prints it to the terminal

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // fopen returns a file pointer used to access file
    // open the file for write
    FILE *stream = fopen(argv[1], "w");
    if (stream == NULL) {
        fprintf(stderr, "Couldn't open file\n");
        perror(argv[1]);
        exit(1);
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
