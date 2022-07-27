#pragma once

typedef struct __float_node{
    float data;
    struct __float_node* previous, *next;
}float_node;

typedef struct __float_double_linked_list{
    float_node* head,*tail;
}float_double_linked_list;

void init(float_double_linked_list* list);    
float_node* peek(float_double_linked_list* list, const int at);
float_node* find(float_double_linked_list* list, const float target);
int insert(float_double_linked_list* list, const int at, const float value);
void push_back(float_double_linked_list* list, const float value);
void push_front(float_double_linked_list* list, const float value);
int delete(float_double_linked_list* list, const int at);
float_node* create_node(const float value);
void free_node(float_node* node);


