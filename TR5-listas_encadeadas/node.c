struct Node {
    struct Node *prev;
    struct Node *next;

    int data;
};

struct Node *head;

void addData(int data) {
    struct Node *aux;
    aux = (struct Node *) malloc(sizeof(struct Node));

    if(head == NULL) {
        aux->next = NULL;
        aux->prev = NULL;
        aux->data = data;

        head = aux;
    } else {
        aux->data = data;
        aux->prev = NULL;
        aux->next = head;
        head = aux;
    }
}