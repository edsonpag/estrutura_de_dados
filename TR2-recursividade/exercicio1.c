#include <stdio.h>
#include <stdlib.h>

int calculaPotencia(int x, int n) {
    if(n == 1) {
        return x;
    } else {
        return x * calculaPotencia(x, n-1);
    }
    
}
int main() {
    int x, n, resultado;
    x = 9;
    n = 4;

    resultado = calculaPotencia(x, n);
    printf("%d\n", resultado);
}