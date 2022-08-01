#include "linked_list_sample.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    float_double_linked_list* list = (float_double_linked_list*)malloc(sizeof(float_double_linked_list));

    init(list);

    for (int i = 0; i < 10; i++)
    {
        push_back(list, i);
    }

    for (int i = 0; peek(list, i) != NULL; i++)
    {
        printf("%f->", peek(list, i)->value);
    }
    printf("\n");

    delete(list, 3);

    for (int i = 0; peek(list, i) != NULL; i++)
    {
        printf("%f->", peek(list, i)->value);
    }
    printf("\n");

    insert(list, 3, 3);

    for (int i = 0; peek(list, i) != NULL; i++)
    {
        printf("%f->", peek(list, i)->value);
    }
    printf("\n");

    printf("%f", find(list, 3)->value);

    return 0;
}




