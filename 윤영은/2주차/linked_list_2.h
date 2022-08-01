#pragma once

typedef struct __example_node {
    //단일 연결 리스트의 노드
    int data;
    struct __example_node* next;
}example_node;

typedef struct __example_list {
    example_node* head, * tail;
}example_list;  //head 와 tail 이 존재하는 단일 연결리스트

typedef struct __float_node {
    float value;
    struct __float_node* previous;
    struct __float_node* next;
}float_node;

typedef struct __float_double_linked_list {
    float_node* head, * tail;
}float_double_linked_list;

void init(float_double_linked_list* list);
float_node* peek(float_double_linked_list* list, const int index);
float_node* find(float_double_linked_list* list, const float target);
int insert(float_double_linked_list* list, const int index, const float value);
void push_back(float_double_linked_list* list, const float value);
void push_front(float_double_linked_list* list, const float value);
int delete(float_double_linked_list* list, const int index);


//단일 연결 리스트 관련 함수 예제
void init_example(example_list* list);
example_node* peek_example(example_list* list, const int at);
example_node* find_example(example_list* list, const int target);
int insert_example(example_list* list, const int at, const int value);
void push_back_example(example_list* list, const int value);
void push_front_example(example_list* list, const int value);
int delete_example(example_list* list, const int at);
example_node* create_example_node(int data);
