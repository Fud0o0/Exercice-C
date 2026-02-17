#include <stdlib.h>
#include <stdio.h>

#define EOF -1

int getchar(void) {
    char c;
    try:
        read(0, &c, 1);
        return c;  // c peut valoir toutes les valeurs d'octets possibles [0; 255]
    except EndOfFileError:
        return EOF;
}

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
    // Reçoit un octet dans RAX
    printf("%#04x\n", caractere);
    // % c'est le premier symbole de placeholder de valeur dans printf:
    // %s c'est pour indiquer une chaîne:
    // printf("%s, %s, %s", "coucou", "hello", "youpi");
    // %d c'est pour un nombre entier
    // printf("%s: %d\n", "Distance terre-lune", 384400);
    // %x c'est pour afficher un nombre entier sous forme hexadecimale, genre ff
    // %#x c'est la forme alternative (c'est a dire avec 0x devant, genre 0xff)
    // %2x c'est un nombre hexa sur 2 caractères, donc 3 ça fait ' 3'
    // %02x c'est sur 2 caractères préfixés par des zéros donc 3 ça fait '03'
    // %#04x c'est sur 4 caractères, en notation alternative donc avec 0x devant, et préfixé de zéros, donc 3 ça fait 0x03
    // %#4x si on lui donne 3 est-ce que ça fait '0x 3' ou ' 0x3' ??? ^^ Faut tester ^^

    // C'est l'équivalent en Python d'une f-string :
    // >>> f"{3:#04x}"
    // '0x03'
    // >>> f"{3:04x}"
    // '0003'
    // >>> f"{3:02x}"
    // '03'
    // >>> f"{3:2x}"
    // ' 3'
    // >>> f"{3:#2x}"
    // '0x3'
    // >>> f"{3:#4x}"
    // ' 0x3'
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