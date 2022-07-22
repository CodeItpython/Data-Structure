#include "linked_list_2.h"
#include <stdio.h>

void init(float_double_linked_list* list) {
    list->head = list->tail = NULL;
}

float_node* peek(float_double_linked_list* list, const int index) {
    float_node* peeked_node = list->head;
    for (int i = 0; i < index && peeked_node != NULL; ++i, peeked_node = peeked_node->next);
    return peeked_node;
}

float_node* find(float_double_linked_list* list, const float target) {
    for (float_node* now_node = list->head; now_node != NULL; now_node = now_node->next) {
        if (now_node->value == target) {
            return now_node;
        }
    }
    return NULL;
}

int insert(float_double_linked_list* list, const int index, const float value) {
    float_node* target_node;
    int i;
    for (target_node = list->head, i = 0; i < index && target_node != NULL; ++i, target_node = target_node->next);
    if (target_node == NULL) {
        return 0;
    }
    else {
        float_node* insert_node = (float_node*)malloc(sizeof(float_node));
        insert_node->value = value;
        // insert_node->next = NULL;
        insert_node->previous = NULL;

        if (index == 0) {
            insert_node->next = list->head;
            list->head->previous = insert_node;
            list->head = insert_node;
        }
        else {
            target_node->previous->next = insert_node;
            insert_node->previous = target_node->previous;
            insert_node->next = target_node;
            target_node->previous = insert_node;
        }
        return 1;
    }
}

void push_back(float_double_linked_list* list, const float value) {
    float_node* node = (float_node*)malloc(sizeof(float_node));
    node->value = value;
    node->next = NULL;

    node->previous = list->tail;
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        list->tail->next = node;
    }

    list->tail = node;
}

void push_front(float_double_linked_list* list, const float value) {
    float_node* node = (float_node*)malloc(sizeof(float_node));
    node->value = value;
    node->previous = NULL;

    node->next = list->head;
    if (list->head == NULL)
    {
        list->tail = node;
    }
    else
    {
        list->head->previous = node;
    }

    list->head = node;
}

int delete(float_double_linked_list* list, const int index) {
    float_node* delete_node;
    int i;
    for (delete_node = list->head, i = 0; i < index && delete_node != NULL; ++i, delete_node = delete_node->next);
    if (delete_node == NULL) {
        return 0;
    }
    else {
        if (index == 0) {
            list->head = list->head->next;
            list->head->previous = NULL;
        }
        else if (delete_node == list->tail) {
            list->tail = delete_node->previous;
            list->tail->next = NULL;
        }
        else {
            delete_node->previous->next = delete_node->next;
            delete_node->next->previous = delete_node->previous;
        }
        free(delete_node);
        return 1;
    }
}


void init_example(example_list* list) {
    list->head = list->tail = NULL;
}

example_node* peek_example(example_list* list, const int at) {
    example_node* peeked_node = list->head;
    for (int i = 0; i < at && peeked_node != NULL; ++i, peeked_node = peeked_node->next);
    return peeked_node; //peeked_node 는 반드시 NULL 이거나 특정 노드의 위치를 가지고 있음
}
example_node* find_example(example_list* list, const int target) {
    for (example_node* now_node = list->head; now_node != NULL; now_node = now_node->next) {
        if (now_node->data == target) {
            return now_node;
        }
    }
    return NULL;
}
int insert_example(example_list* list, const int at, const int value) {
    example_node* target_node, * previous_node;
    int i;
    previous_node = NULL;
    for (target_node = list->head, i = 0; i < at && target_node != NULL; ++i, target_node = target_node->next) {
        previous_node = target_node;
    }
    if (target_node == NULL) {
        //at 번째 노드는 존재하지 않음
        return 0;
    }
    else {
        example_node* insert_node = create_example_node(value);
        if (at == 0) {   //at==0 는 delete_node==list->head 와 동치;
            insert_node->next = list->head;
            list->head = insert_node;
        }
        else {
            previous_node->next = insert_node;
            insert_node->next = target_node;
        }
        return 1;
    }
}
void push_back_example(example_list* list, const int value) {
    example_node* node = create_example_node(value);
    list->tail->next = node;
    list->tail = node;
}
void push_front_example(example_list* list, const int value) {
    example_node* node = create_example_node(value);
    node->next = list->head;
    list->head = node;
}
int delete_example(example_list* list, const int at) {
    example_node* delete_node, * previous_node;
    int i;
    previous_node = NULL;
    for (delete_node = list->head, i = 0; i < at && delete_node != NULL; ++i, delete_node = delete_node->next) {
        previous_node = delete_node;
    }
    if (delete_node == NULL) {
        //at 번째 노드는 존재하지 않음
        return 0;
    }
    else {
        if (at == 0) {   //at==0 는 delete_node==list->head 와 동치;
            list->head = list->head->next;
        }
        else if (delete_node == list->tail) {
            list->tail = previous_node;
            list->tail->next = NULL;
        }
        else {
            previous_node->next = delete_node->next;
        }
        free(delete_node);
        return 1;
    }
}
example_node* create_example_node(int data) {
    example_node* node = (example_node*)malloc(sizeof(example_node));
    node->data = data;
    node->next = NULL;
    return node;
}
