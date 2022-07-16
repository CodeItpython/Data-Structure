#include "ex.h"
#include <stdio.h>
#include <stdlib.h>

void init_example(example_list *list)
{
  list->head = list->tail = NULL;
}

example_node *peek_example(example_list *list, const int at)
{
  example_node *peeked_node = list->head;
  for (int i = 0; i < at && peeked_node != NULL; ++i, peeked_node = peeked_node->next)
    ;
  return peeked_node;
}
example_node *find_example(example_list *list, const int target)
{
  for (example_node *now_node = list->head; now_node != NULL; now_node = now_node->next)
  {
    if (now_node->data == target)
    {
      return now_node;
    }
  }
  return NULL;
}
int insert_example(example_list *list, const int at, const int value)
{
  example_node *target_node, *previous_node;
  int i;
  previous_node = NULL;
  for (target_node = list->head, i = 0; i < at && target_node != NULL; ++i, target_node = target_node->next)
  {
    previous_node = target_node;
  }
  if (target_node == NULL)
  {
    return 0;
  }
  else
  {
    example_node *insert_node = create_example_node(value);
    if (at == 0)
    {
      insert_node->next = list->head;
      list->head = insert_node;
    }
    else
    {
      previous_node->next = insert_node;
      insert_node->next = target_node;
    }
    return 1;
  }
}
void push_back_example(example_list *list, const int value)
{
  example_node *node = create_example_node(value);
  list->tail->next = node;
  list->tail = node;
}
void push_front_example(example_list *list, const int value)
{
  example_node *node = create_example_node(value);
  node->next = list->head;
  list->head = node;
}
int delete_example(example_list *list, const int at)
{
  example_node *delete_node, *previous_node;
  int i;
  previous_node = NULL;
  for (delete_node = list->head, i = 0; i < at && delete_node != NULL; ++i, delete_node = delete_node->next)
  {
    previous_node = delete_node;
  }
  if (delete_node == NULL)
  {

    return 0;
  }
  else
  {
    if (at == 0)
    {
      list->head = list->head->next;
    }
    else if (delete_node == list->tail)
    {
      list->tail = previous_node;
      list->tail->next = NULL;
    }
    else
    {
      previous_node->next = delete_node->next;
    }
    free(delete_node);
    return 1;
  }
}
example_node *create_example_node(int data)
{
  example_node *node = (example_node *)malloc(sizeof(example_node));
  node->data = data;
  node->next = NULL;
  return node;
}
