#include <stdio.h>

int main() {
    char c = 'A';
    short s = 42;
    int x = 42;
    long l = 42;

    char *hello = "Coucou";


    // char c'est character, c'est caractère, en vrai ça veut dire byte.

    //       %s veut dire : l'argument est une chaîne de caractères
    //      vv              donc l'argument est l'adresse d'un octet
    printf("%s\n", hello); // Tu donne à printf une adresse (un char*)
    printf("%c\n", *hello); // Tu donne a printf un char
    //      ^^
    //        L'argument est un byte.

    printf(hello);

    // Un char c'est un octet, c'est un byte.
    // Un char * c'est une adresse d'un byte.
}