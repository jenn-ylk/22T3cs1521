#include <stdio.h>

void print_array(int nums[], int index, int len) {
    if (index == len) return;
    
    printf("%d\n", nums[index]);
    print_array(nums, index + 1, len);
    /*
    for (int i = 0; i < len; i++) {
        printf("%d\n", nums[i]);
    }
    */

    /*
    int i = 0;
    while (i < len) {
        printf("%d\n", nums[i]);

        i++;
    }
    */
}

int main(void)
{
    int nums[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    print_array(nums, 0, 10);

    return 0;
}