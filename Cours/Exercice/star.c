#include <stdlib.h>
#include <stdio.h>

size_t my_strlen(char *chaine) {
    // reçoit la chaîne dans RDI
    // reçoit 64 bits
    // reçoit juste une adresse
    size_t length = 0;

    while (*chaine != '\0') {
        length += 1;
        chaine++;
    }

    return length;
}

void print_hex_char(char caractere) {
    printf("%#04x\n", caractere);
}

int main(void) {

    //     chaine est de type adresse de caractère
    //     *chaine est de type caractère
    //   v
    char *chaine;

    chaine = "Hello world!";

    printf("%zu\n", my_strlen(chaine));
    print_hex_char(*chaine);
}