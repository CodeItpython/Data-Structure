#include "linked_list_2.h"
#include <stdio.h>

void show_data(float_double_linked_list* list);

int main() {
    float_double_linked_list example;
    init(&example);

    // push_back 테스트
    printf("*** push_back ***\n");
    for (int i = 0; i < 5; i++)
    {
        push_back(&example, i * 0.1f);
    }
    show_data(&example);

    // push_front 테스트
    printf("\n*** push_front ***\n");
    for (int i = 5; i < 10; i++)
    {
        push_front(&example, i * 0.1f);
    }
    show_data(&example);

    // insert 테스트
    printf("\n*** insert ***\n");
    if (insert(&example, 6, 5.4))
    {
        printf("Complete to insert '5.4' to index 6\n");
        show_data(&example);
    }
    else
    {
        printf("Failed to insert data\n");
    }

    if (insert(&example, 11, 7.3))
    {
        printf("Complete to insert '7.3' to index 11\n");
        show_data(&example);
    }
    else
    {
        printf("Failed to insert data\n");
    }

    // delete 테스트
    printf("\n*** delete ***\n");
    if (delete(&example, 3))
    {
        printf("Complete to delete data of index 3\n");
        show_data(&example);
    }
    else
    {
        printf("Failed to delete data\n");
    }

    if (delete(&example, 12))
    {
        printf("Complete to delete data of index 12\n");
        show_data(&example);
    }
    else
    {
        printf("Failed to delete data\n");
    }

    // peek 테스트
    printf("\n*** peek ***\n");
    float_node* peek_data = peek(&example, 8);
    if (peek_data == NULL)
    {
        printf("Failed to find data index 8\n");
    }
    else
    {
        printf("Succeed to find data of index 8 is %f\n", peek_data->value);
    }

    peek_data = peek(&example, 16);
    if (peek_data == NULL)
    {
        printf("Failed to find data index 16\n");
    }
    else
    {
        printf("Succeed to find data of index 16 is %f\n", peek_data->value);
    }

    // find 테스트
    printf("\n*** find ***\n");
    float_node* find_data = find(&example, 0.7f);
    if (find_data == NULL)
    {
        printf("Failed to find data 0.7\n");
    }
    else
    {
        printf("Succeed to find data %f\n", find_data->value);
    }

    find_data = find(&example, 12.3f);
    if (find_data == NULL)
    {
        printf("Failed to find data 12.3\n");
    }
    else
    {
        printf("Succeed to find data %f\n", find_data->value);
    }

    return 0;
}

void show_data(float_double_linked_list* list)
{
    for (float_node* now = list->head; now != NULL; now = now->next)
    {
        printf("%f ", now->value);
    }
    printf("\n");
}
