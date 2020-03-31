#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    void mostraElementosOrdenados(int *vetor, int elements, char *algoritimo);
    void bubble(int *vetor, int elements);
    void selection_sort(int *vetor, int elements);
    void insertion_sort(int *vetor, int elements);
    void chama_merge_sort(int *vetor, int elements);
    void chama_quick_sort(int *vetor, int elements);


    int *vetor_1;
    int *vetor_2;
    int *vetor_3;
    int *vetor_4;
    int *vetor_5;
    unsigned int elements = 0;
    
    printf("Digite a quantidade de elementos: ");
    scanf("%d", &elements);

    vetor_1 = (int *)(malloc(elements * sizeof(int)));
    vetor_2 = (int *)(malloc(elements * sizeof(int)));
    vetor_3 = (int *)(malloc(elements * sizeof(int)));
    vetor_4 = (int *)(malloc(elements * sizeof(int)));
    vetor_5 = (int *)(malloc(elements * sizeof(int)));

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
    vetor_5 = vetor_1;
        
    bubble(vetor_1, elements);
    selection_sort(vetor_2, elements);
    insertion_sort(vetor_3, elements);
    chama_merge_sort(vetor_4, elements);
    chama_quick_sort(vetor_5, elements);

    return 0;
}

long int iniciaContagem() {
    clock_t inicio;
    return inicio = clock();
}

long int calculaDuracao(long int inicio) {
    clock_t fim, duracao;

    fim = clock();
    return duracao = (fim - inicio) / CLOCKS_PER_SEC;
}

void mostraTempoDeExecucao(long int duracao, char *algoritimo) {
    printf("O TEMPO DE EXECUÇÃO DO ALGORITIMO %s FOI: %ld SEGUNDOS\n", algoritimo, duracao);
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
    clock_t duracao;

    j = 0;
    troca = 1;

    duracao = iniciaContagem();
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
    duracao = calculaDuracao(duracao);
    mostraElementosOrdenados(vetor, elements, "BUBBLE");
    mostraTempoDeExecucao(duracao, "BUBBLE");
}

void selection_sort(int *vetor, int elements) {
    int position, i, j, aux;
    clock_t duracao;

    duracao = iniciaContagem();
    for(i = 0; i < elements; i++) {
        position = i;

        for(j = i + 1; j < elements; j++) {
            if(vetor[j] < vetor[position]) {
                position = j;
            }
        }

        aux = vetor[i];
        vetor[i] = vetor[position];
        vetor[position] = aux;
    }
    duracao = calculaDuracao(duracao);
    mostraElementosOrdenados(vetor, elements, "SELECTION SORT");
    mostraTempoDeExecucao(duracao, "SELECTION SORT");
}

void insertion_sort(int *vetor, int elements) {
    int i, j, key;
    clock_t duracao;

    duracao = iniciaContagem();
    for(i = 1; i < elements; i++) {
        key = vetor[i];
        j = i - 1;

        while(j >= 0 && key < vetor[j]) {
            vetor[j+1] = vetor[j];
            j--;
        }

        vetor[j+1] = key;
    }
    duracao = calculaDuracao(duracao);
    mostraElementosOrdenados(vetor, elements, "INSERTION SORT");
    mostraTempoDeExecucao(duracao, "INSERTION SORT");
}

void chama_merge_sort(int *vetor, int elements) {
    void merge_sort(int *vetor, int inicio, int fim);

    clock_t duracao;
    duracao = iniciaContagem();
    merge_sort(vetor, 0, elements - 1);
    duracao = calculaDuracao(duracao);
    mostraElementosOrdenados(vetor, elements, "MERGE SORT");
    mostraTempoDeExecucao(duracao, "MERGE SORT");
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

void chama_quick_sort(int *vetor, int elements) {
    void quick_sort(int *vetor, int inicio, int fim);

    clock_t duracao;

    duracao = iniciaContagem();
    quick_sort(vetor, 0, elements - 1);
    duracao = calculaDuracao(duracao);
    mostraElementosOrdenados(vetor, elements, "QUICK SORT");
    mostraTempoDeExecucao(duracao, "QUICK SORT");
}

void quick_sort(int *vetor, int inicio, int fim) {
    int particao(int *vetor, int inicio, int fim);
    int meio;

    if(inicio < fim) {
        meio = particao(vetor, inicio, fim);
        quick_sort(vetor, inicio, meio);
        quick_sort(vetor, meio+1, fim);
    }
}

int particao(int *vetor, int inicio, int fim) {
    int pivo, i, j, aux;
    pivo = vetor[(inicio + fim) / 2];

    i = inicio - 1;
    j = fim + 1;

    while(i < j) {
        do {
            j = j - 1;
        }
        while(vetor[j] > pivo);
        
        do {
            i = i + 1;
        } while(vetor[i] < pivo);
        if(i < j) {
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }

    return j;
}