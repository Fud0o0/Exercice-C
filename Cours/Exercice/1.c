#include <stdio.h>  // C'est pas DU TOUT comme import en Python
// les .h contiennent ce genre de lignes :
int write(int, char *, int); // Ceci est un prototype.
// Pour que le compilateur sache quels registres utiliser.  les .h ne
// contiennent **pas** de code. Que des prototypes.  Ça ne sert au
// compilateur qu'a savoir quels registres utiliser pour les
// paramètres
// (cf. https://en.wikipedia.org/wiki/X86_calling_conventions#System_V_AMD64_ABI)

int main() {
    char c = 'A'; // C'est un octet, c'est \x41.
    short s = 42; // C'est un petit int. \x2a\x00
    int x = 42;   // C'est un int.  \x2a\x00\x00\x00
    long l = 42;  // C'est un gros int. \x2a\x00\x00\x00\x00\x00\x00\x00

    char *hello = "Coucou\n";
    write(1, hello, 7); // hello est une adresse, donc tout roule.
    printf("%c\n", *hello);
    //             ^ l'étoile veut dire « va chercher la valeur à l'adresse ..... »

    // La spec de C indique que char < short < int < long
    //                             1       2     4      8

    //       vvvvvvv c'est un nombre entier, 64 bits, c'est adresse !
    write(1, "Hello\n", 6);
    //       ^^^^^^^ c'est l'adresse du premier octet de Hello, quelque part dans la RAM.
}


void coucou() {// Une fonction qui ne renvoie rien.

}

int youpi() { // Une fonction qui renvoie un int via RAX
    return 0; // 0 ça veut souvent dire que tout va bien.