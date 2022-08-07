#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


void init(int_stack* stack) {
    stack->top = NULL;
}

void push(int_stack* stack, int data) {
    int_node* new_top = create_node(data);
    new_top->next = stack->top;
    stack->top = new_top;
}

void pop(int_stack* stack) {
    if (isEmpty(stack) == 0) {
        int_node* del_node;
        del_node = stack->top;
        stack->top = stack->top->next;
        free_node(del_node);
    }
}

int peek(int_stack* stack) {
    if (isEmpty(stack) == 0) {
        return stack->top->data;
    }
    else {
        exit(1);
    }
}

int isEmpty(int_stack* stack) {
    if (stack->top == NULL)
        return 1;
    else
        return 0;
}

int_node* create_node(int data) {
    int_node* ret = (int_node*)malloc(sizeof(int_node));
    ret->data = data;
    ret->next = NULL;
    return ret;
}

void free_node(int_node* node) {
    free(node);
}