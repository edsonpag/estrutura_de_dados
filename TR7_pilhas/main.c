#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_structs.h"
#include "stack_methods.h"


int main() {

    struct Stack *stack;
    stack = new_stack();

    stack->data = 5;

    printf("%i\n", stack->data);



    return 0;
}