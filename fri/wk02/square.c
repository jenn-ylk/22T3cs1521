// Prints the square of a number

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    // y = x * x;

    // printf("%d\n", y);

    if (x <= SQUARE_MAX) goto calc;
        printf("square too big for 32 bits\n");
        goto finish;
calc:
        y = x * x;
        printf("%d\n", y);
finish:

    return 0;
}