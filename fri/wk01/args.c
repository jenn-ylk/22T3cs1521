// a simple program that makes use of command line arguments

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    // argc - counts how many arguments are on the terminal
    // argv - array of strings, containing each argument

    // > ./args 5 6
    // argc = 3
    // argv = {"./args", "5", "6"}

    printf("Program name: %s\n", argv[0]);
    printf("There are %d command line arguments\n", argc);

    int sum = 0;
    // check each command line argument
    for (int i = 1; i < argc; i++) {
        sum += atoi(argv[i]);
    }
    printf("Sum of arguments is %d\n", sum);
}




