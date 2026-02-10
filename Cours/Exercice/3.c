#include <stdio.h>

int main() {
    //                 vvvv
    size_t something = 18446744073709551517lu;

    printf("%d\n", (int)something);
}