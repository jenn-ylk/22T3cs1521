// a program that takes in 1+ command line args, a string to search for
// and the files to search in
// should print out all lines that contain the substring

#include <stdio.h>
#include <string.h>

#define MAX_LINE 65536

void search_stream(FILE *stream, char stream_name[], char search_for[]);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <prefix> <files>\n", argv[0]);
        return 1;
    } 
    
    if (argc == 2) {
        search_stream(stdin, "<stdin>", argv[1]);
    } else {

        for(int argument = 2; argument < argc; argument = argument + 1) {
            // use fopen to open the file, provide file pointer to search
            // also make checks that something did correctly open
            FILE *in = fopen(argv[argument], "r");
            if (in == NULL) {
                perror(argv[argument]);
            }
            search_stream(in, argv[argument], argv[1]);
            
            fclose(in);
        }

    }

    return 0;
}

void search_stream(FILE *stream, char stream_name[], char search_for[]) {
    char line[MAX_LINE];
    // TODO: search each line for the substring with fgets and strstr, 
    // print out the line if contained
    printf("Stream name = %s\n", stream_name);
    while (fgets(line, MAX_LINE, stream) != NULL) {
        if (strstr(line, search_for) != NULL) {
            printf("\t - %s", line);
        }
    }
}

