#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;

    int n = atoi(argv[1]);
    
    long long a = 1; 
    long long b = 1;
    long long result = 1;

    if (n == 0 || n == 1) {
        printf("1\n");
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        result = a + b;
        a = b;
        b = result;
    }

   
    printf("%lld\n", result);

    return 0;
}