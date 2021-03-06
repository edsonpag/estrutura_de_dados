#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu_start();

#include "structs.h"
#include "list.h"

int main() {
    menu_start();

    return 0;
}

void menu_start() {
    int option = 0;

    printf("------------------------MENU DO SISTEMA DE ALUNOS------------------------\n\n");
    printf("Digite 1 para encontrar um aluno pelo ID\n");
    printf("Digite 2 para listar de ordem decrescente\n");
    printf("Digite 3 para listar de ordem crescente\n");
    printf("Digite -1 para sair do sistema\n");

    scanf("%i", &option);

    switch(option) {
        case 1:
            findById();
            break;

        case 2:
            printInDescendingOrder();
            break;

        case 3:
            printInAscendingOrder();
            break;

        default:
            printf("Saindo...\n");
            break;
    }
}