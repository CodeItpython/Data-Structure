#pragma once

typedef struct __int_node {
    int data;
    struct __int_node* next;
}int_node;

typedef struct __int_queue {
    int_node* front, * rear;
}int_queue;

void init(int_queue* queue);
void push(int_queue* queue, int data);
void pop(int_queue* queue);
int peek(int_queue* queue);
int isEmpty(int_queue* queue);
void free_node(int_node* node);
int_node* create_node(int data);