#include <stdio.h>
#include <stdint.h>

// a function that uses bitwise operations to 
// return the six middle bits of a 32 bit number, 
// shifted into the least significant 6 bits
uint32_t six_middle_bits(uint32_t u) {
    // e.g.: 0b 00000000 00001110 01010000 00001010 -> 
    //          00000000 00000000 00000000 00110010
    // Two methods
    // mask then shift:
    // 00000000 00000111 11100000 00000000
    // uint32_t mask = 0x7e000; // this mask is the same as 0x3f << 13
    // return (u & mask) >> 13;
    // shift then mask (easier/better):
    return (u >> 13) & 0x3f;
}

int main (void) {
    uint32_t num = 0x000e5005;
    uint32_t result = six_middle_bits(num);
    printf("The middle six bits of %d (%x) are %d (%x)\n", num, num, result, result);
}
