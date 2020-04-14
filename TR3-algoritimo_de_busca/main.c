#include <stdio.h>
#include "ordenar.c"

/*
int binario(int *vetor, int inicio, int fim, int numero) {
    int meio;

    while(inicio<=fim){
        meio= (inicio+fim)/2;

        if(numero == vetor[meio]){
            return meio;
        }else if(numero > vetor[meio]){
                inicio = meio+1;
        }else{
            fim = meio-1;
        }
    }

    return -1;
}
*/

int binario(int *vetor, int inicio, int fim, int numero) {
    int meio = (inicio + fim) / 2;

    if(numero == vetor[meio]) {
        return meio;
    } else if(numero > vetor[meio]) {
        inicio = meio + 1;
        binario(vetor, inicio, fim, numero);
    } else if(numero < vetor[meio]) {
        fim = meio - 1;
        binario(vetor, inicio, fim, numero);
    }
    else {
        return - 1;
    }
}


void algoritimo_binario(int numero, int *vetor, int length) {

    int resultado;

    if(numero < vetor[0]) {
        printf("O número não foi encontrado no array\n");
        exit(0);
    }
    if(numero > vetor[length-1]){
        printf("O número não foi encontrado no array\n");
        exit(0);
    }

    resultado = binario(vetor, 0, length-1, numero);

    if(resultado == -1) {
        printf("O número não foi encontrado no array\n");
    } else {
        printf("O valor %i resultado foi encontrado na posicao %i\n", numero, resultado);
    }
}

int main() {

    int vetor[50];
    int numero;
    int length;

    length = sizeof(vetor) / sizeof(int);

    srand(time(NULL));
    for(int i = 0; i < length; i++) {
        vetor[i] = rand() % 100;
    }

    chama_quick_sort(vetor, length);

    printf("Digite o número da pesquisa: ");
    scanf("%i", &numero);

    algoritimo_binario(numero, vetor, length);

    return 0;
}