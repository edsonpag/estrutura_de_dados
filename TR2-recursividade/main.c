#include <stdio.h>
#include <stdlib.h>

long int fatorial(int num) {
    
    if(num == 0) {
        return 1;
    } else {
        return num * fatorial(num-1);
    }

}

int main() {
    int num = 10;
    int num2 = 15;
    long int resultado;

    resultado = fatorial(num);
    printf("O fatorial de %i eh %li\n", num, resultado);

    resultado = fatorial(num2);
    printf("O fatorial de %i eh %li\n", num2, resultado);

}