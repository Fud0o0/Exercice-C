// unsigned char, char, signed char
// macros paramétrés
// typedef


// Selon la spec, char c'est soit signed soit unsigned.


// unsigned char c'est 8 bits
// signed char c'est 1 bit de signe, et 7 bits de valeur
//            (complément à deux, c'est de pas avoir 0 et -0)

// Si on avait pas le complément à deux :
// 00000000 qui vaut 0
// 10000000 qui vaut -0
// ^ bit de signe

//char c; // signé ou pas, c'est le compilo qui décide
// Les caractères c'est ASCII, donc de 0 à 127

// "signed" signifie "-" ou "+"
// signed ça signifie que la valeur peut être négative.
//signed char sc; // Sur nos architectures : [-128; 127]
//                 Selon la spec c'est au moins [-127; 127]
//                 (complément à deux)

//unsigned char uc; // [0; 255]

// -(8)
// 8 unsigned char, unsigned int, unsigned long
// 0x8 signed char, unsigned char, signed int, unsigned int, ...

// TL;DR : Si vous voulez stocker une chaîne, c'est char *
//         Si vous voulez stocker des bytes : unsigned char;
//         Si vous voulez stocker des valeurs entre [-127; 127], signed char c'est bien.

#include <stdio.h>

#define _RED "\033[31m"
#define _GREEN "\033[32m"
#define _RESET "\033[0m"

#define GREEN(str) _GREEN str _RESET
#define RED(str) _RED str _RESET

#define ADD(x, y) (x + y)

// static long my_add(long x, long y) {
//     return x + y;
// }

// Ça j'ai l'habitude d'écrire :
typedef struct point point; // J'alias "struct point" en "point"
struct point {
    int x;
    int y;
};


// Ça je trouve un peu dense :
typedef struct point {
    int x;
    int y;
} point;

point add_points(point self, point other) {
}

int main(void) {
    printf(RED("rouge") GREEN("vert"));

    printf("%d\n", ADD(2, 3) * 4);
    // 20 4
    // 24

}