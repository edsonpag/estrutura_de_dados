struct Tree {
    int data;
    struct Tree *left;
    struct Tree *rigth;
};

struct Tree * createNode(int data);
void insert(struct Tree **tree, int data);
void insertNode(struct Tree **tree, int data);
int search(struct Tree *tree, int data);
void total(struct Tree *tree, int *results);
void numberOfNodes(struct Tree *tree, int *nodes);