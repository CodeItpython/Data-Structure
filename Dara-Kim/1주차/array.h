#pragma once

typedef struct __int_array {
	int* arr; // 배열의 시작점
	int size; // 배열에 있는 데이터의 수
	int capacity; // 배열이 수용할 수 있는 데이터의 수
}int_array;

void init(int_array* array, const int capacity);    //배열 초기화
int peek(int_array* array, const int index);
int insert(int_array* array, const int index, const int value);
void push(int_array* array, const int value);
int delete(int_array* array, const int index);
