#include <stdio.h>

int main(void) {
    int c;

    // getchar returns the character as an int or EOF
    while ((c = getchar()) != EOF) {
        putchar(c);
    }

    return 0;
}