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

void total(struct Tree *tree, int *results) {
    
    if(tree == NULL) {
        return;
    } else {

        *results += tree->data;

        total(tree->left, results);
        total(tree->rigth, results);
    }

}

void numberOfNodes(struct Tree *tree, int *nodes) {
    if(tree == NULL) {
        return;
    } else {
        *nodes += 1;
        numberOfNodes(tree->left, nodes);
        numberOfNodes(tree->rigth, nodes);
    }
}