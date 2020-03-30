#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    void mostraElementosOrdenados(int *vetor, int elements, char *algoritimo);
    void bubble(int *vetor, int elements);
    void selection_sort(int *vetor, int elements);
    void insertion_sort(int *vetor, int elements);
    void chama_merge_sort(int *vetor, int elements);  

    int *vetor_1;
    int *vetor_2;
    int *vetor_3;
    int *vetor_4;
    unsigned int elements = 0;
    
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &elements);

    vetor_1 = (int *)(malloc(elements * sizeof(int)));
    vetor_2 = (int *)(malloc(elements * sizeof(int)));
    vetor_3 = (int *)(malloc(elements * sizeof(int)));
    vetor_4 = (int *)(malloc(elements * sizeof(int)));

    printf("ELEMENTOS DESORDENADOS: \n");

    srand(time(NULL));
    for(int i = 0; i < elements; i++) {
        vetor_1[i] = rand() % 100;
        printf("%d  ", vetor_1[i]);
    }

    printf("\n");

    if(vetor_1 == NULL) {
        printf("ERRO NA ALOCAÇÃO");
        system("pause");
        exit(1);
    }

    vetor_2 = vetor_1;
    vetor_3 = vetor_1;
    vetor_4 = vetor_1;
        
    bubble(vetor_1, elements);
    selection_sort(vetor_2, elements);
    insertion_sort(vetor_3, elements);
    chama_merge_sort(vetor_4, elements);

    return 0;
}

void mostraElementosOrdenados(int *vetor, int elements, char *algoritimo) {
    
    printf("ELEMENTOS ORDENADOS USANDO %s: \n", algoritimo);

    for(int i = 0; i < elements; i++) {
        printf("%d  ", vetor[i]);
    }
    
    printf("\n");
}

void bubble(int *vetor, int elements) {
    int j, i, aux, troca;

    j = 0;
    troca = 1;

    while(j < elements && troca == 1) {
        troca = 0;
        for(int i = 0; i <= elements-2; i++) {
            if(vetor[i] > vetor[i+1]) {
                troca = 1;
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
            }
        }
        j++;
    }
    
    mostraElementosOrdenados(vetor, elements, "BUBBLE");
}

void selection_sort(int *vetor, int elements) {
    for(int i = 0; i < elements; i++) {
        int position = i;

        for(int j = i + 1; j < elements; j++) {
            if(vetor[j] < vetor[position]) {
                position = j;
            }
        }

        int aux = vetor[i];
        vetor[i] = vetor[position];
        vetor[position] = aux;
    }

    mostraElementosOrdenados(vetor, elements, "SELECTION SORT");
}

void insertion_sort(int *vetor, int elements) {
    int i, j, key;

    for(i = 1; i < elements; i++) {
        key = vetor[i];
        j = i - 1;

        while(j >= 0 && key < vetor[j]) {
            vetor[j+1] = vetor[j];
            j--;
        }

        vetor[j+1] = key;
    }
    
    mostraElementosOrdenados(vetor, elements, "INSERTION SORT");
}

void chama_merge_sort(int *vetor, int elements) {
    void merge_sort(int *vetor, int inicio, int fim);

    merge_sort(vetor, 0, elements - 1);
    mostraElementosOrdenados(vetor, elements, "MERGE SORT");
}

void merge_sort(int *vetor, int inicio, int fim) {
    void intercala(int *vetor, int inicio, int fim, int meio);
    int meio;

    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio+1, fim);
        intercala(vetor, inicio, fim, meio);
    }
}

void intercala(int *vetor, int inicio, int fim, int meio) {
    int inicio_vetor_1, inicio_vetor_2, posicao_livre, i;
    int aux[fim];
    inicio_vetor_1 = inicio;
    inicio_vetor_2 = meio + 1;
    posicao_livre = inicio;

    while(inicio_vetor_1 <= meio && inicio_vetor_2 <= fim) {

        if(vetor[inicio_vetor_1] <= vetor[inicio_vetor_2]) {
            aux[posicao_livre] = vetor[inicio_vetor_1];
            inicio_vetor_1++;
        } else {
            aux[posicao_livre] = vetor[inicio_vetor_2];
            inicio_vetor_2++;
        }

        posicao_livre++;
    }

    for(i = inicio_vetor_1; i <= meio; i++) {
        aux[posicao_livre] = vetor[i];
        posicao_livre++;
    }

    for(i = inicio_vetor_2; i <= fim; i++) {
        aux[posicao_livre] = vetor[i];
        posicao_livre++;
    }

    for(i = inicio; i <= fim; i++) {
        vetor[i] = aux[i];
    }
}