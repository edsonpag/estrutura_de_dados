#include <stdio.h>
#include <stdlib.h>
#include "utils.c"
#include "binaryTree.h"
#include "binaryTree.c"

void menu(struct Tree *tree) {
    int option;
    int data;
    int searchFor;
    int valueFound;

    int *totalAmount;
    totalAmount = (int *) malloc(sizeof(int));
    *totalAmount = 0;

    int *nodes;
    nodes = (int *) malloc(sizeof(int));
    *nodes = 0;

    
    printf("\n---- Software de Árvores Binárias\n\n");
    printf("---- 1: Inserir um novo elemento na árvore\n");
    printf("---- 2: Pesquisar um elemento na árvore\n");
    printf("---- 3: Exibir o valor da soma de todos os elementos da árvore\n");
    printf("---- 4: Exibir o número de nós da árvore\n");
    printf("---- 0: Sair\n");



    option = read_integer();

    switch(option) {

        case 0:
            return;

        case 1:
            system("clear");
            printf("Digite o valor a ser inserido: \n");
            data = read_integer();
            insert(&tree, data);
            system("clear");
            printf("---- Valor %i inserido com sucesso\n", data);
            menu(tree);
            break;

        case 2:
            system("clear");
            printf("Digite o valor a ser procurado: \n");
            searchFor = read_integer();
            valueFound = search(tree, searchFor);
            system("clear");
            valueFound == -1 ? printf("---- Valor não foi encontrado\n") : printf("---- Valor %i foi encontrado\n", valueFound);
            menu(tree);
            break;

        case 3:
            system("clear");
            total(tree, totalAmount);
            printf("%i\n", *totalAmount);
            free(totalAmount);
            menu(tree);
            break;

        case 4:
            system("clear");
            numberOfNodes(tree, nodes);
            printf("A árvore tem %i nós\n", *nodes);
            free(nodes);
            menu(tree);
            break;

        default:
            printf("Digite um valor entre 1-4\n");
            menu(tree);
            break;
    }
}

int main() {

    struct Tree *tree;
    tree = NULL;

    menu(tree);

    return 0;
}

