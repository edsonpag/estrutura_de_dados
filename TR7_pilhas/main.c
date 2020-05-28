#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_structs.h"
#include "stack_methods.h"


int main() {

    struct Stack *stack;
    stack = new_stack();

    push(stack, 52);
    push(stack, 8);
    push(stack, 12);

    printf("%i: %i: %i\n", stack->data, stack->next->data, stack->next->next->data);

    return 0;
}