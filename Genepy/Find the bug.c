#include <stdio.h>

int main(void) {
    printf("Gonna knock three times:\n");
    for (int i = 0; i < 3; i = i + 1) {
        printf("*knock*\n");
    }
    printf("- Who's there?\n");
    return 0;
}