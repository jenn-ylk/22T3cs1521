#include <stdio.h>
#include <stdint.h>

// a function that uses bitwise operations to 
// return the six middle bits of a 32 bit number, 
// shifted into the least significant 6 bits
uint32_t six_middle_bits(uint32_t u) {
    // make this return the middle six bits of a number
    // e.g.: 0b 00000000 00001110 01010000 00001010 -> 
    //          00000000 00000000 00000000 00110010
    // mask then shift:
    // 0b00000000000001111110000000000000
    // return (u & 0x0007e000) >> 13;
    // shift then mask (easier):
    return (u >> 13) & 0x3F; // 0b111111
    // same idea to get the exponent bits of a float: (u >> 23) & 0xFF
}

int main (void) {
    uint32_t num = 0x000e5005;
    uint32_t result = six_middle_bits(num);
    printf("The middle six bits of %d (%x) are %d (%x)\n", num, num, result, result);
}
