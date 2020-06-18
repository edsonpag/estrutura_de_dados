struct Tree * createNode(int data) {
    struct Tree *node;
    node = (struct Tree *) malloc(sizeof(struct Tree));

    node->data = data;
    node->left = NULL;
    node->rigth = NULL;

    return node;
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

        if((*tree)->rigth == NULL) {

            (*tree)->rigth = createNode(data);
        } else {
            insertNode(&(*tree)->rigth, data);
        }
        
    }

}


int search(struct Tree *tree, int data) {
    if(tree == NULL) {
        return -1;
    }

    if(tree->data == data) {
        printf("%i\n", tree->data);
        return tree->data;
    } else if(data < tree->data) {
        search(tree->left, data);
    } else {
        search(tree->rigth, data);
    }
    
}

void total(struct Tree *tree, int *totalAmount) {
    
    if(tree == NULL) {
        return;
    } else {

        *totalAmount += tree->data;

        total(tree->left, totalAmount);
        total(tree->rigth, totalAmount);
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