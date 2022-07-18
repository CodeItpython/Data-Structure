#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init(float_double_linked_list *list) // list 초기화
{
  float_node *head_node = (float_node *)malloc(sizeof(float_node));
  float_node *tail_node = (float_node *)malloc(sizeof(float_node));
  list->head = head_node;
  list->tail = tail_node;
}

float_node *peek(float_double_linked_list *list, const int index) // index위치에있는 node리턴
{
  float_node *peeked_node = list->head; // head를 peeked_node로 지정
  for (int i = 0; i < index && peeked_node != NULL; ++i)
    peeked_node = peeked_node->next;
  return peeked_node;
}

float_node *find(float_double_linked_list *list, const float value) // value데이터가 존재하는 노드 리턴
{
  for (float_node *nowNode = list->head; nowNode != NULL; nowNode = nowNode->next)
  {
    if (nowNode->data = value)
      return nowNode;
  }
  return NULL;
}

int insert(float_double_linked_list *list, const int index, const float value)
{
  float_node *target_node, *previous_node;
  float_node *insert_node = create_node(value);

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
    if (index == 0) // head에 넣을경우
    {
      insert_node->next = list->head; // insert_node의 다음이 head로 지정
      list->head->prev = insert_node; // head의 전노드가 insert_node
      list->head = insert_node;       // head를 insert_node로 지정
    }
    else //중간에 삽입하는경우
    {
      previous_node->next = insert_node; // previous_node의 다음이 insert_node로 지정
      insert_node->next = target_node;   // insert_node의 다음이 target_node로 지정
      insert_node->prev = previous_node; // insert_node의 전노드가 previose_node로 지정
      target_node->prev = insert_node;   // target_node의 전노드가 insert_node로 지정
    }
    return 1;
  }
}

void push_back(float_double_linked_list *list, const float value)
{
  float_node *newNode = create_node(value);
  float_node *pre_node = list->tail->prev;
  pre_node->next = newNode;
  newNode->prev = pre_node;
  newNode->next = list->tail;
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

float_node *create_node(float data) //노드 한개를 생성하는 메소드
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
  for (float_node *node = list->head; node != NULL; node = node->next)
  {
    printf("%f ", node->data);
  }
}
