#include "array.h"
#include <stdio.h>

int main() {
    int_array arr1;

    //초기화
    init(&arr1, 6);

    //PUSH
    for (int i = 0; i < 4; i++) {
        push(&arr1, i + 1);
    }

    //INSERT
    insert(&arr1, 2, 5); //index = 2 자리에 값5 대입

    //DELETE
    delete(&arr1, 1); //index = 1 자리 값 삭제

    //PEEK
    printf("%d", peek(&arr1, 1));

    return 0;
}
