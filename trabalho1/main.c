#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int *vetor;
    unsigned int elements = 0;
    void bubble(int *teste, int elements);
    void selection_sort(int *teste, int elements);
    void insertion_sort(int *teste, int elements);
    void merge_sort(int *teste, int inicio, int fim);


    printf("Digite a quantidade de elementos: ");
    scanf("%d", &elements);

    vetor = (int *)(malloc(elements * sizeof(int)));

    if(vetor == NULL) {
        printf("\nErro na alocação");
        system("pause");
        exit(1);
    }

    printf("Elementos de desordenados: \n");

    srand(time(NULL));
    for(int i = 0; i < elements; i++) {
        vetor[i] = rand() % 100;
        printf("%d, ", vetor[i]);
    }

    // bubble(vetor, elements);
    // selection_sort(vetor, elements);
    // insertion_sort(vetor, elements);
    merge_sort(vetor, 0, elements);

    printf("\nElementos ordenados usando o algoritimo da merge: \n");

    for(int i = 0; i < elements; i++) {
        printf("%d, ", vetor[i]);
    }

    return 0;
}

void bubble(int *teste, int elements) {
    int i, j, tempory;

    for(i = 0; i < elements; i++) {
        for(j = i + 1; j < elements; j++) {
            if(teste[i] > teste[j]) {
                tempory = teste[i];
                teste[i] = teste[j];
                teste[j] = tempory;
            }
        }
    }

    printf("\nElementos ordenados usando o algoritimo da bolha: \n");

    for(int i = 0; i < elements; i++) {
        printf("%d, ", teste[i]);
    }
}

void selection_sort(int *teste, int elements) {
    for(int i = 0; i < elements; i++) {
        int position = i;

        for(int j = i + 1; j < elements; j++) {
            if(teste[j] < teste[position]) {
                position = j;
            }
        }

        int tempory = teste[i];
        teste[i] = teste[position];
        teste[position] = tempory;
    }

    printf("\nElementos ordenados com o selection sort: \n");

    for(int i = 0; i < elements; i++) {
        printf("%d, ", teste[i]);
    }
}

void insertion_sort(int *teste, int elements) {
    int i, j, key;

    for(i = 1; i < elements; i++) {
        key = teste[i];
        j = i - 1;

        while(j >= 0 && key < teste[j]) {
            teste[j+1] = teste[j];
            j--;
        }

        teste[j+1] = key;
    }
    

    printf("\nElementos ordenados com o insertion sort: \n");

    for(int i = 0; i < elements; i++) {
        printf("%d, ", teste[i]);
    }
}

void merge_sort(int *teste, int inicio, int fim) {
    int meio;
    void intercala(int *teste, int inicio, int fim, int meio);

    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        merge_sort(teste, inicio, meio);
        merge_sort(teste, meio+1, fim);
        intercala(teste, inicio, fim, meio);
    }
}

void intercala(int *teste, int inicio, int fim, int meio) {
    int inicio_vetor_1, inicio_vetor_2, posicao_livre, i;
    int aux[fim];
    inicio_vetor_1 = inicio;
    inicio_vetor_2 = meio + 1;
    posicao_livre = inicio;

    while(inicio_vetor_1 <= meio && inicio_vetor_2 <= fim) {

        if(teste[inicio_vetor_1] <= teste[inicio_vetor_2]) {
            aux[posicao_livre] = teste[inicio_vetor_1];
            inicio_vetor_1++;
        } else {
            aux[posicao_livre] = teste[inicio_vetor_2];
            inicio_vetor_2++;
        }

        posicao_livre++;
    }

    for(i = inicio_vetor_1; i <= meio; i++) {
        aux[posicao_livre] = teste[i];
        posicao_livre++;
    }

    for(i = inicio_vetor_2; i <= fim; i++) {
        aux[posicao_livre] = teste[i];
        posicao_livre++;
    }

    for(i = inicio; i <= fim; i++) {
        teste[i] = aux[i];
    }
}