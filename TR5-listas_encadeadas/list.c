struct Node {
    int data;
    struct Node *next;
};

struct Node createNode() {
    struct Node list;

    list.data = 0;
    list.next = NULL;

    return list;
}

void addElementToNode(struct Node head, int element) {


    askToUserIfHeWantsToContinue();
}


void start(struct Node list) {
    int element = 0;

    printf("Digite o valor para ser adicionado a lista: ");
    element = read_integer();


    addElementToNode(list, element);

}