// Simple code that accesses the HOME environment variable to open and read
// $HOME/.diary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 128
#define MAX_LINE_LEN 512

int main(void) {
    // get the required environment variables
    char *user = getenv("USER");
    printf("Printing %s's diary\n", user);
    // get the value of the HOME path, and concatenate it with ./diary
    char *home_path = getenv("HOME");

    char path[MAX_PATH_LEN] = {0};
    // TODO: construct the diary path name (concatenate with ./diary)
    snprintf(path, MAX_PATH_LEN, "%s/.diary", home_path);
    // TODO: Open the diary in read mode, print an error if not doable
    FILE *diary = fopen(path, "r");
    if (diary == NULL) {
        perror(path);
        return 1;    
    }
    
    // read the diary line by line and print
    char line[MAX_LINE_LEN] = {0};
    while (fgets(line, MAX_LINE_LEN, diary) != NULL) {
        fputs(line, stdout);
    }

    // close the diary
    fclose(diary);
    
    return 0;
}

