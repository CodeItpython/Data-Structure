#pragma once

typedef struct __int_node{
    int data;
    struct __int_node* next;
}int_node;

typedef struct __int_stack{
    int_node* top;
}int_stack;

void init(int_stack* stack);
void push(int_stack* stack, int data);
void pop(int_stack* stack);
int peek(int_stack* stack);
int isEmpty(int_stack* stack);
int_node* create_node(int data);
void free_node(int_node* node);