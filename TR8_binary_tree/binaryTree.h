struct Tree {
    int data;
    struct Tree *left;
    struct Tree *rigth;
};

struct Tree * createNode(int data);
void insert(struct Tree **tree, int data);
void insertNode(struct Tree **tree, int data);


struct Tree *teste = NULL;