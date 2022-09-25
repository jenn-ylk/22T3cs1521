// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    int x = 24;
loop:
    if (x >= 42) goto end_loop;

    printf("%d\n", x);
    x += 3;
    goto loop;

end_loop:
    return 0;
    /*
    for (int x = 24; x < 42; x += 3) {
        printf("%d\n", x);
    }
    */
}