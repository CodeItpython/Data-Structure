#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct __float_node
{
  float data;
  struct __float_node *prev;
  struct __float_node *next;
} float_node;

typedef struct __float_double_linked_list
{
  float_node *head;
  float_node *tail;
  int count;
} float_double_linked_list;

//이중 연결 리스트 관련 함수
void init(float_double_linked_list *list);
float_node *peek(float_double_linked_list *list, const int index);
float_node *find(float_double_linked_list *list, const float target);
int insert(float_double_linked_list *list, const int index, const float value);
void push_back(float_double_linked_list *list, const float value);
void push_front(float_double_linked_list *list, const float value);
int delete (float_double_linked_list *list, const int index);
float_node *create_node(int data);
void free_node(float_node *Node);