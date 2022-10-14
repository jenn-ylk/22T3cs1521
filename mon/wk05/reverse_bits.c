// Code containing a function that will reverse the bits of an unsigned int

#include <stdint.h>
#include <stdio.h>

#define WORD_BITS 32

typedef uint32_t Word;

void printBits(Word w) {
    for (int shift = WORD_BITS-1; shift >= 0; shift--) {
        printf("%d", (w >> shift) & 1);
    }
    printf("\n");
}

// a function that reverses the bit order of a word
Word reverseBits(Word w) {
    // TODO:
    Word new_word = 0;
    for (int shift = 0; shift < WORD_BITS; shift++) {
        // shift current reversed bits up by 1, put next bit after it
        new_word = (new_word << 1) | (w >> shift) & 1;
    }
    return new_word;
}

int main(void) {
    Word w = 0x01234567;
    printBits(w);
    printBits(reverseBits(w));
}