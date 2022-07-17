#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init(float_double_linked_list *list)
{

  list->head = create_node(0);
  list->tail = create_node(0);
  list->head->next = list->tail; //머리 다음은 꼬리
  list->tail->prev = list->head; //꼬리 앞은 머리
}

float_node *peek(float_double_linked_list *list, const int index)
{
  float_node *peeked_node = list->head;
  for (int i = 0; i < index && peeked_node != NULL; ++i)
    peeked_node = peeked_node->next;
  return peeked_node;
}

float_node *find(float_double_linked_list *list, const float target)
{
  for (float_node *nowNode = list->head; nowNode != NULL; nowNode = nowNode->next)
  {
    if (nowNode->data = target)
      return nowNode;
  }
  return NULL;
}

int insert(float_double_linked_list *list, const int index, const float value)
{
  float_node *target_node, *previous_node;
  int i;
  previous_node = NULL;
  for (target_node = list->head, i = 0; i < index && target_node != NULL; ++i, target_node = target_node->next)
  {
    previous_node = target_node;
  }

  if (target_node == NULL)
  {
    return 0;
  }
  else
  {
    float_node *insert_node = create_node(value);
    if (index == 0)
    {
      insert_node->next = list->head;
      list->head->prev = insert_node;
      list->head = insert_node;
    }
    else
    {
      previous_node->next = insert_node;
      insert_node->next = target_node;
      insert_node->prev = previous_node;
      target_node->prev = insert_node;
    }
    return 1;
  }
}

void push_back(float_double_linked_list *list, const float value)
{
  float_node *newNode = create_node(value);
  list->tail->next = newNode;
  newNode->prev = list->tail;
  list->tail = newNode;
}

void push_front(float_double_linked_list *list, const float value)
{
  float_node *newNode = create_node(value);
  newNode->next = list->head;
  list->head->prev = newNode;
  list->head = newNode;
}

int delete (float_double_linked_list *list, const int index)
{
  float_node *delete_node, *previous_node;
  int i;
  previous_node = NULL;
  for (delete_node = list->head, i = 0; i < index && delete_node != NULL; ++i, delete_node = delete_node->next)
  {
    previous_node = delete_node;
  }
  if (delete_node == NULL)
  {
    return 0;
  }
  else
  {
    if (index == 0) //지우려는 노드가 head일경우
    {
      list->head = list->head->next;
      list->head->prev = NULL;
    }
    else if (delete_node == list->tail) //지우려는 노드가 tail일경우
    {
      list->tail = previous_node;
      list->tail->next = NULL;
    }
    else //사이에있는 노드를 지울때
    {
      previous_node->next = delete_node->next;
      delete_node->next->prev = previous_node;
    }
    free_node(delete_node);
    return 1;
  }
}

float_node *create_node(float data)
{
  float_node *node = (float_node *)malloc(sizeof(float_node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void free_node(float_node *Node)
{
  free(Node);
}

void print_list(float_double_linked_list *list)
{
  float_node *node = list->head;
  while (node != list->tail)
  {
    printf("%f ", node->data);
    node = node->next;
  }
}