struct Stack * new_stack();
bool isEmpty(struct Stack *stack);


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