#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1; 
    }

    
    long n = atol(argv[1]);

    while (n >= 1) {
        printf("%ld", n);
        
        if (n == 1) {
            break; 
        }
        
        printf(" "); 

        
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }

    printf("\n");
    return 0;
}