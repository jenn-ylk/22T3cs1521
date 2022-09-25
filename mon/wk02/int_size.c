// A simple program demonstrating how to represent a implementing an && in an
// if-statement in MIPS.
#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100 && x < 1000) {
        printf("medium\n");
    } else {
        printf("small/big\n");
    }

    /*
    // the less nice approach
    char *message = "small/big\n";
    if (x > 100 && x < 1000) {
        message = "medium";
    }
    */
}
