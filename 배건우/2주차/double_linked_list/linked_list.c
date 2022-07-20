#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void init(float_double_linked_list *list) // list 초기화
{
  list->head = list->tail = NULL;
  list->list_size = 0;
}

float_node *peek(float_double_linked_list *list, const int index) // index위치에있는 node리턴
{
  float_node *peeked_node = list->head; // head를 peeked_node로 지정
  for (int i = 0; i < index && peeked_node != NULL; ++i, peeked_node = peeked_node->next)
    return peeked_node;
}

float_node *find(float_double_linked_list *list, const float value) // value데이터가 존재하는 노드 리턴
{
  for (float_node *nowNode = list->head; nowNode != NULL; nowNode = nowNode->next)
  {
    if (nowNode->data == value)
      return nowNode;
  }
  return NULL;
}

void push_back(float_double_linked_list *list, const float value) // tail뒤에 삽입
{
  float_node *newNode = create_node(value);
  if (list->head == NULL) // head가 비어있는경우
  {
    list->head = list->tail = newNode;
    list->tail->prev = newNode;
    list->tail->next = newNode;
  }
  else
  {
    newNode->prev = list->tail;
    newNode->next = list->tail->next;
    list->tail->next = newNode;
    list->head->prev = newNode;
    list->tail = newNode;
  }
  list->list_size++;
}

void push_front(float_double_linked_list *list, const float value) // head앞에 삽입
{
  float_node *newNode = create_node(value);
  if (list->head == NULL) // head가 비어있는경우
  {
    list->head = list->tail = newNode;
    list->head->prev = newNode;
    list->head->next = newNode;
  }
  else
  {
    newNode->prev = list->head->prev;
    newNode->next = list->head;
    list->head->prev = newNode;
    list->tail->next = newNode;
    list->head = newNode;
  }
  list->list_size++;
}

int insert(float_double_linked_list *list, const int index, const float value)
{
  float_node *new_node = create_node(value);
  float_node *current_node;

  if (index <= list->list_size) //범위 내의 인덱스에 대해 실행
  {
    if (index == 1) // head의 앞에 삽입하고싶을때
    {
      push_front(list, value);
      return 1;
    }
    else if (index == list->list_size) // tail뒤에 삽입하고싶을때
    {
      push_back(list, value);
      return 1;
    }
    else //중간에 삽입하고싶을때
    {
      int n = index - 1;         //따로 int n을 생성해주는 이유는 index가 const int 이기때문
      current_node = list->head; //임시의 현재 node를 head로 지정
      while (--n)
      { // 내가 넣고 싶은 자리 바로 앞으로 current_node가 설정된다.
        current_node = current_node->next;
      }
      new_node->prev = current_node;
      new_node->next = current_node->next;
      current_node->next = new_node;
      new_node->next->prev = new_node;
      ++list->list_size;
      return 1;
    }
  }
  return 0;
}

void delete_back(float_double_linked_list *list)
{
  float_node *current_node;
  float_node *tmp;
  tmp = list->tail;

  if (tmp == NULL) // list->tail이 비어있을경우
  {
    puts("list가 비어있음\n");
  }
  else
  {
    current_node = list->tail->prev;
    current_node->next = list->head;
    list->head->prev = current_node;
    list->tail = current_node;
    free(tmp); //할당 해제
    list->list_size--;
  }
}

void delete_front(float_double_linked_list *list)
{
  float_node *current_node;
  float_node *tmp;
  tmp = list->head; // tmp를 list->head로 초기화

  if (tmp == NULL) // list->head가 비어있는경우
  {
    puts("list가 비어있음\n");
  }
  else
  {
    current_node = list->head->next;
    current_node->prev = list->head->prev;
    list->tail->next = current_node;
    list->head = current_node;
    free(tmp); //할당 해제
    list->list_size--;
  }
}

int delete (float_double_linked_list *list, const int index) // node 삭제 메소드
{
  float_node *current_node;
  float_node *tmp;

  if (index <= list->list_size) //범위 내의 index에 대한 조건문
  {
    if (list->head == NULL) // head가 비어있는경우
    {
      puts("list가 비어있음\n");
      return 0;
    }
    else if (index == 1) // head를 삭제하고싶은경우
    {
      delete_front(list);
      return 1;
    }
    else if (index == list->list_size) // tail을 삭제하고싶은경우
    {
      delete_back(list);
      return 1;
    }
    else //중간의 index를 삭제하고싶은경우
    {
      int n = index;
      current_node = list->head;
      while (--n)
      { // 내가 지우고 싶은 자리로 current_node이 설정된다.
        current_node = current_node->next;
      }
      tmp = current_node;
      current_node->prev->next = current_node->next;
      current_node->next->prev = current_node->prev;
      free(tmp);
      list->list_size--;
      return 1;
    }
  }
  return 0;
}

float_node *create_node(float data) //노드 한개를 생성하는 메소드
{
  float_node *node = (float_node *)malloc(sizeof(float_node));
  node->data = data;
  node->next = NULL;
  node->prev = NULL;
  return node;
}

void print_list(float_double_linked_list *list) // node의 data를 출력하는 메소드
{
  float_node *current_node;
  current_node = list->head;
  if (current_node == NULL)
  {
    puts("list가 비어있음\n");
  }
  else
  {
    int index = 1;
    while (index <= list->list_size) //범위내의  index에 대해
    {
      printf("L[%d] = %f\n", index, current_node->data);
      current_node = current_node->next; //출력후 다음노드로 초기화
      index++;                           // index증가
    }
  }
  printf("\n");
}
