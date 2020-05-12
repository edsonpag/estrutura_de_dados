void addData(int data);
void show();

struct Node {
    struct Node *prev;
    struct Node *next;

    int data;
};

struct Node *head;

void show() {
    struct Node *aux, *temp;
    //aux = (struct Node *) malloc(sizeof(struct Node));
    int i = 0;
    
    for(temp = head; temp != NULL; temp = temp->next) {
        printf("Valor indice %i = %i\n", i, temp->data);
        i++;
    }
}

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