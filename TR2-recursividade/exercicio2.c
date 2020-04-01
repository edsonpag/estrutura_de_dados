#include <stdio.h>
#include <stdlib.h>

int multiplicar(int x, int n) {
    if(n == 1) {
        return x;
    }

    return x + multiplicar(x, n - 1);
}

int main() {
    int x, n, resultado;
    x = 3;
    n = 7;

    resultado = multiplicar(x, n);
    printf("%i\n", resultado);
}