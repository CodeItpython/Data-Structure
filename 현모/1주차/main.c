#include <stdio.h>
#include <stdlib.h>
#include "array_sample.h"

int main(int argc, char const* argv[])
{
    int_array array;

    init(&array, 10);

    for (int i = 0; i < 10; i++)
    {
        push(&array, i);
        printf("%5d", peek(&array, i));
    }
    printf("\n");

    insert(&array, 4, 250);
    delete(&array, 3);

    for (int i = 0; i < array.size; i++)
    {
        printf("%5d", peek(&array, i));
    }
    
    free(array.arr);

    return 0;
}


