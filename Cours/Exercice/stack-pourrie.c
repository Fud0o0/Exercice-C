#include <stdlib.h>
#include <stdio.h>

size_t my_strlen(char *chaine) {
    // reçoit la chaîne dans RDI
    // reçoit 64 bits
    // reçoit juste une adresse
    size_t length = 0;

    while (*chaine != '\0') {
        length += 1;
        chaine = chaine + 1;
    }

    return length;
}

void print_hex_char(char caractere) {
    printf("%#04x\n", caractere);
}

int une_fonction_qui_pourrit_la_stack() {
    char buffer[256] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
}

int pasmain(void) {
    char buffer[128];

    printf("%zu\n", my_strlen(buffer));
}


int main(void){
    une_fonction_qui_pourrit_la_stack();
    pasmain();
}