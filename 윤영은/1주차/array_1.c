#include "array_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void init(int_array* array, const int capacity) {
	// 동적 메모리 할당
	array->arr = (int*)malloc(sizeof(int) * capacity);

	assert(array != NULL); // 동적 메모리 할당 확인

	array->capacity = capacity;
	array->size = 0;
}

int peek(int_array* array, const int index) {
	if (index < 0 || index > array->size - 1)
	{
		printf("peek 연산 실패\n");
		exit(1);
	}

	int result = array->arr[index];
	printf("index %d: %d\n", index, result); // 출력
	return result;
}

int insert(int_array* array, const int index, const int value) {
	if (index < 0 || index > array->size)
	{
		return 0;
	}

	if (array->size == array->capacity)
	{
		int* temp = NULL;
		temp = realloc(array->arr, sizeof(int) * (array->capacity + 10));
		if (temp != NULL)
		{
			array->arr = temp;
		}
		array->capacity += 10;
	}

	// insert 위치(index)를 기준으로 데이터를 한 칸 씩 뒤로 밀기
	for (int i = array->size; i > index; i--)
	{
		array->arr[i] = array->arr[i - 1];
	}

	// 데이터 insert
	array->arr[index] = value;

	array->size++;

	return 1;
}

void push(int_array* array, const int value) {
	if (array->size == array->capacity)
	{
		int* temp = NULL;
		temp = realloc(array->arr, sizeof(int) * (array->capacity + 10));
		if (temp != NULL)
		{
			array->arr = temp;
		}
		array->capacity += 10;
	}

	array->arr[array->size] = value;
	array->size++;
}

int delete(int_array* array, const int index) {
	if (array->size == 0) // 배열이 빈 경우
	{
		return 0;
	}
	if (index < 0 || index > (array->size)) // index가 허용된 범위 인지
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
