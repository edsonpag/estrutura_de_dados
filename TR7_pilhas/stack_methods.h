struct Stack * new_stack();
bool isEmpty(struct Stack *stack);
void push(struct Stack *stack, int data);

struct Stack * new_stack() {
    struct Stack *stack;
    stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->length = 0;


    return stack; // retornando o endereço de memoria "&stack"
}

bool isEmpty(struct Stack *stack) {
    if(stack->length == 0) {
        return true;
    }

    return false;
}

void push(struct Stack *stack, int data) {
    struct Stack *aux, *temp;
    int i = 0;
    aux = (struct Stack *) malloc(sizeof(struct Stack));
    temp = (struct Stack *) malloc(sizeof(struct Stack));

    if(isEmpty(stack)) {
        stack->data = data;
    } else {
        // logica do push
    }
}