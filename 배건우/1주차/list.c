#include "sample.h"
#include <stdio.h>
#include <stdlib.h>

void init(int_array *array, const int capacity) //배열 초기화 함수
{
  array->capacity = capacity;
  array->ptr = (int *)malloc(sizeof(int) * capacity);
  array->size = 0;
}

int peek(int_array *array, const int index)
{
  if (index < 0 || index >= array->size)
  {
    exit(1);
  }                         //인덱스가 범위내에 없으면 0리턴
  return array->ptr[index]; //그게아닌경우 해당 index에 위치하는 value 리턴
}

int insert(int_array *array, const int index, const int value) //삽입메소드
{
  if (array->size == array->capacity)
  { //배열이 꽉찬경우
    int *temp_array;
    temp_array = realloc(array->ptr, sizeof(int) * (array->capacity * 2));
    array->ptr = temp_array;
    array->capacity *= 2;
  }

  else if ((index >= 0) && (index <= array->size)) // index가 범위 내에 있는경우
  {
    for (int i = (array->size - 1); i >= index; i--)
      array->ptr[i + 1] = array->ptr[i];
    array->ptr[index] = value;
    array->size++;
  }
}

void push(int_array *array, const int value)
{
  if (array->size == array->capacity) //배열이 꽉찬경우
  {
    int *temp_array;
    temp_array = realloc(array->ptr, sizeof(int) * (array->capacity * 2)); //재할당+capacity를 2배 늘려줌
    array->ptr = temp_array;
    array->capacity *= 2; //구조체 멤버변수인 capacity도 똑같이 2배늘려줌
  }

  else                                 //배열이 꽉차지 않은경우
    array->ptr[array->size++] = value; //마지막 위치에 값을 삽입함
}

int delete (int_array *array, const int index)
{
  if (index < 0 || index >= array->size) //배열의 크기를 벗어나는 index입력시
    return 0;

  else if (array->size == 0)
  {
    return 0;
  }

  else if (array->ptr[index] && index >= 0 && index <= array->size) // ptr[index]에 값이 있으면 삭제  (삭제가 되는경우)
  {
    for (int i = index; i < (array->size - 1); i++)
      array->ptr[i] = array->ptr[i + 1];
    array->size--;
    return 1;
  }

  else //삭제가 안되는경우 false 리턴
    return 0;
}

void print_arr(int_array *array) //배열 출력(메소드를 추가했음)
{
  for (int i = 0; i < array->size; i++)
  {
    printf("%d  ", array->ptr[i]);
  }
}


