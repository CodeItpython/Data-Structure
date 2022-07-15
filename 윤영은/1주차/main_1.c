#include "array_1.h"
#include <stdio.h>

void show_int_array(int_array* array);

int main() {
    int_array example;
    init(&example, 10);

    for (int i = 0; i < 10; i++)
    {
        push(&example, i);
    }
    show_int_array(&example);

    printf("\n");

    if (insert(&example, 3, 10))
    {
        printf("insert '10' to index 3\n");
        show_int_array(&example);
    }

    printf("\n");

    if (delete(&example, 7))
    {
        printf("delete index 7\n");
        show_int_array(&example);
    }

    printf("\n");

    printf("peek index 6\n");
    peek(&example, 6);

    // µ¿Àû ¸Þ¸ð¸® ÇÒ´ç ÇØÁ¦
    free(example.arr);

    return 0;
}

void show_int_array(int_array* array)
{
    for (int i = 0; i < array->size; i++)
    {
        printf("%d ", array->arr[i]);
    }
    printf("\n");
} 
