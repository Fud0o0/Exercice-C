#include <string.h>
#include <stdio.h>

int main(void) {
    
    const char *whetting_your_appetite = (
        "Ada Lovelace's notes were labelled alphabetically from A to G. "
        "In Note G, she describes an algorithm for the Analytical Engine "
        "to compute Bernoulli numbers. "
        "It is considered to be the first published algorithm ever "
        "specifically tailored for implementation on a computer, and "
        "Ada Lovelace has often been cited as the first computer programmer "
        "for this reason."
    );

    
    printf("%zu\n", strlen(whetting_your_appetite));

    return 0;
}