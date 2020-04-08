#include <stdio.h>
#include "ordenar.c"

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

void algoritimo_binario(int numero, int *vetor) {

    int tamanho_array = 50;
    int resultado;

    if(numero < vetor[0]) {
        printf("Não existe");
        exit(0);
    }
    if(numero > vetor[tamanho_array-1]){
        printf("Não existe");
        exit(0);
    }

    resultado = binario(vetor, 0, tamanho_array-1, numero);

    if(resultado == -1) {
        printf("O valor não foi encontrado\n");
    } else {
        printf("O valor %i resultado foi encontrado na posicao %i\n", numero, resultado);
    }
}

int main() {

    int vetor[50];
    int numero;
    

    srand(time(NULL));
    for(int i = 0; i < 50; i++) {
        vetor[i] = rand() % 1000;
    }

    chama_quick_sort(vetor, 50);

    printf("Digite o número da pesquisa: ");
    scanf("%i", &numero);

    algoritimo_binario(numero, vetor);

    return 0;
}