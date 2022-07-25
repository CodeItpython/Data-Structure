#include "linked_list_sample.h"
#include <stdio.h>
#include <stdlib.h>

/*
*  헤더 파일에서 선언한 함수를 "반드시" 여기에 정의
*/

void init(float_double_linked_list* list) {
	list->head = list->tail = NULL;
}

float_node* peek(float_double_linked_list* list, const int index) {
	float_node* peeked_node = list->head;
	for (int i = 0; i < index && peeked_node != NULL; i++, peeked_node = peeked_node->next);
	return peeked_node;
}

float_node* find(float_double_linked_list* list, const float target) {
	for (float_node* now_node = list->head; now_node != NULL; now_node = now_node->next)
	{
		if (now_node->value == target)
		{
			return now_node;
		}
	}
	return NULL;
}

int insert(float_double_linked_list* list, const int index, const float value) {
	float_node* next_node = peek(list, index);

	if (list->head == NULL) // 수정(list가 비어있을 때 삽입)
	{
		push_front(list, value);
		return 1;
	}

	if (next_node == NULL) 
	{
		return 0;
	}
	else
	{
		if (next_node == list->head) // index == 0;
		{
			push_front(list, value);
		}
		else if (next_node == list->tail) // index == size - 1
		{
			push_back(list, value);
		}
		else
		{
			float_node* node = create_node(value);
			float_node* prev_node = next_node->previos;

			prev_node->next = node;
			node->previos = prev_node;
			next_node->previos = node;
			node->next = next_node;
		}
		return 1;
	}
}

void push_back(float_double_linked_list* list, const float value) {
	float_node* node = create_node(value);
	if (list->head == NULL) // list에 노드가 없을 경우
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->previos = list->tail;
		list->tail->next = node;
		list->tail = node;
	}
}

void push_front(float_double_linked_list* list, const float value) {
	float_node* node = create_node(value); 
	if (list->head == NULL) // list에 노드가 없을 경우
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->next = list->head;
		list->head->previos = node;
		list->head = node;
	}
}

int delete(float_double_linked_list* list, const int index) {
	float_node* node = peek(list, index);

	if (node == NULL)
	{
		return 0;
	}
	else
	{
		if (list->head == list->tail) // 수정(노드가 1개 있을 때)
		{
			list->head = list->tail = NULL;
			free(node);
		}
		else if (node == list->head) // index == 0;
		{
			float_node* next_node = node->next;

			next_node->previos = NULL;
			list->head = next_node;

			free(node);
		}
		else if (node == list->tail) // index == size - 1
		{
			float_node* prev_node = node->previos;

			prev_node->next = NULL;
			list->tail = prev_node;

			free(node);
		}
		else
		{
			float_node* next_node = node->next;
			float_node* prev_node = node->previos;

			next_node->previos = prev_node;
			prev_node->next = next_node;

			free(node);
		}
		return 1;
	}
}

float_node* create_node(float value)
{
	float_node* node = (float_node*)malloc(sizeof(float_node));
	node->value = value;
	node->next = NULL;
	node->previos = NULL;

	return node;
}

