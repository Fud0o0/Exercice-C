#include <stdio.h>
#include <ctype.h>

int main(void) {
    int c;
    long lines = 0, words = 0, bytes = 0;
    int in_word = 0; // Boolean flag to track if we are inside a word

    while ((c = getchar()) != EOF) {
        bytes++;

        if (c == '\n') {
            lines++;
        }

        // Check for whitespace to determine word boundaries
        if (isspace(c)) {
            in_word = 0;
        } else if (in_word == 0) {
            in_word = 1;
            words++;
        }
    }

    // Output matches the format: lines words bytes
    printf("%ld %ld %ld\n", lines, words, bytes);

    return 0;
}