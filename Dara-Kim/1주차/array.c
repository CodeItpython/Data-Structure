#include "array.h"
#include <stdio.h>
#include <stdlib.h>

void init(int_array* array, const int capacity) {
    array->arr = (int*)malloc(sizeof(int) * capacity);
    if (array == NULL) { // 메모리 할당 여부 확인
        printf("메모리 할당 실패로 프로그램 종료\n");
        exit(1);
    }
    array->capacity = capacity;
    array->size = 0;
}

int peek(int_array* array, const int index) {
    if (index < 0 && array->size <= index) { // 인덱스가 배열 범위를 벗어나면 실패
        printf("확인하고자 하는 위치가 배열 범위를 벗어나 프로그램 종료\n");
        exit(1);
    }
    else {
        return array->arr[index];
    }
}

int insert(int_array* array, const int index, const int value) {
    if (index < 0 && array->size < index) { // 인덱스가 배열 범위를 벗어나면 연산 불가
        return 0;
    }

    if (array->size == array->capacity) {
        int* temp = NULL;
        // 재할당을 실패할 경우 프로그램 종료
        if (temp = (int*)realloc(array->arr, sizeof(int) * (array->capacity + 10)) == NULL) {
            free(temp);
            printf("메모리 재할당 실패로 프로그램 종료\n");
            exit(1);
        }
        array->capacity += 10;
    }

    for (int i = array->size; i > index; i--) { // 저장할 위치부터 원소를 한 칸씩 밀어 저장
        array->arr[i] = array->arr[i - 1];
    }
    array->arr[index] = value;
    array->size++;

    return 1;
}

void push(int_array* array, const int value) {
    if (array->size == array->capacity) {
        int* temp = NULL;
        // 재할당을 실패할 경우 프로그램 종료
        if (temp = (int*)realloc(array->arr, sizeof(int) * (array->capacity + 10)) == NULL) {
            free(temp);
            printf("메모리 재할당 실패로 프로그램 종료\n");
            exit(1);
        }
        array->capacity += 10;
    }
    array->arr[array->size] = value;
    array->size++;
}

int delete(int_array* array, const int index) {
    if (index < 0 && array->size <= index) { // 인덱스가 배열 범위를 벗어나면 실패
        return 0;
    }
    if (array->size == 0) { // 배열이 비어있으면 실패
        return 0;
    }

    for (int i = index; i < array->size - 1; i++) { // 지우고자 하는 인덱스까지 한 칸씩 당겨 저장
        array->arr[i] = array->arr[i + 1];
    }
    array->size--;

    return 1;
}

