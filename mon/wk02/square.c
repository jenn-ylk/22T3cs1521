// Prints the square of a number

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > SQUARE_MAX) goto too_big;
    
    not_big:
    y = x * x;
    printf("%d\n", y);
    goto finish;

    too_big:
    printf("square too big for 32 bits\n");


    finish:

    return 0;
}