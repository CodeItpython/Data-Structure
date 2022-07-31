#include "array_sample.h"
#include <stdlib.h>

void init(int_array* array, const int capacity)
{
    array->capacity = capacity;
    array->size = 0;
    array->arr = (int*)malloc(sizeof(int) * capacity);
}

int peek(int_array* array, const int index)
{
    if (array->size <= index && index < 0)
    {
        exit(1);
    }
    else
    {
        return array->arr[index];
    }
}

int insert(int_array *array, const int index, const int value)
{
    if (array->size < index && index < 0)
    {
        return 0;
    }

    if (array->size == array->capacity)
    {
        int* temp = array->arr;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity * 2);
        if (array->arr == NULL)
        {
            free(temp);
            exit(1);
        }

        array->capacity = array->capacity * 2;
    }

    for (int i = array->size; i > index; i--)
    {
        array->arr[i] = array->arr[i - 1];
    }
    array->arr[index] = value;
    array->size++;

    return 1;
} 

void push(int_array* array, const int value)
{
    if (array->size == array->capacity)
    {
        int* temp = array->arr;
        array->arr = (int*)realloc(array->arr, sizeof(int) * array->capacity * 2);
        if (array->arr == NULL)
        {
            free(temp);
            exit(1);
        }
        
        array->capacity = array->capacity * 2;
    }

    array->arr[array->size] = value;
    array->size++;
}

int delete (int_array *array, const int index)
{
    if (array->size == 0 || (array->size - 1 < index && index < 0))
    {
        return 0; 
    }

    for (int i = index; i < array->size - 1; i++)
    {
        array->arr[i] = array->arr[i + 1];
    }
    array->size--;

    return 1;
} 

