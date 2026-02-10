#include <stdio.h>

int main(void) {
    // On utilise des suffixes .0 pour forcer le calcul en nombres flottants
    printf("%.15f\n", 8958937768937.0 / 2851718461558.0);
    return 0;
}