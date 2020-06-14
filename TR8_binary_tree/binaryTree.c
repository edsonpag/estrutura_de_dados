#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"


struct Tree * createNode(int data) {
    struct Tree *temp;
    temp = (struct Tree *) malloc(sizeof(struct Tree));

    temp->data = data;
    temp->left = NULL;
    temp->rigth = NULL;

    return temp;
}

void insert(struct Tree **tree, int data) {
    if(*tree == NULL) {
        *tree = createNode(data);

    } else {
        insertNode(tree, data);
    }
}

void insertNode(struct Tree **tree, int data) {

    if(data < (*tree)->data) {

        if((*tree)->left == NULL) {
            (*tree)->left = createNode(data);
        } else {
            insertNode(&(*tree)->left, data);
        }

    } else {

        if((*tree)->rigth == NULL)  {

            (*tree)->rigth = createNode(data);
        } else {
            insertNode(&(*tree)->rigth, data);
        }
        
    }

}


int search(struct Tree **tree, int data) {
    if((*tree) == NULL) {
        printf("Não encontrado\n");
        return -1;
    }

    if((*tree)->data == data) {
        printf("%i\n", (*tree)->data);
        return (*tree)->data;
    } else if(data < (*tree)->data ) {
        search(&(*tree)->left, data);
    } else {
        search(&(*tree)->rigth, data);
    }
    
}

void total(struct Tree **tree, int *results) {
    
    if(*tree == NULL) {
        return;
    } else {

        *results += (*tree)->data;

        total(&(*tree)->left, results);
        total(&(*tree)->rigth, results);
    }

}

void numberOfNodes(struct Tree **tree, int *nodes) {
    if(*tree == NULL) {
        return;
    } else {
        *nodes += 1;
        numberOfNodes(&(*tree)->left, nodes);
        numberOfNodes(&(*tree)->rigth, nodes);
    }
}

int main() {
    struct Tree *tree;
    tree = NULL;

    int *results;
    results = (int *) malloc(sizeof(int));
    *results = 0;

    int *nodes;
    nodes = (int *) malloc(sizeof(int));
    *nodes = 0;
    

    insert(&tree, 10);
    insert(&tree, 5);
    insert(&tree, 3);
    insert(&tree, 15);
    insert(&tree, 30);
    insert(&tree, 25);
    insert(&tree, 2);




    /* 
    -------  PESQUISA ------

    int valor_encontrado = search(&tree, 15);

    */



    
    /*
    -------  SOMA TOTAL ------

    total(&tree, results);
    printf("%i\n", *results);
    */



    /*
    printf("%i\n", tree->data);
    printf("%i\n", tree->left->data);
    printf("%i\n", tree->left->left->data);
    printf("%i\n", tree->rigth->data);
    printf("%i\n", tree->rigth->rigth->data);
    printf("%i\n", tree->rigth->rigth->left->data);
    */



    /*
    -------  NUMERO DE NÓS ------

    numberOfNodes(&tree, nodes);
    printf("%i\n", *nodes);
    */

    return 0;
}