#include "array.h"
#include <stdio.h>

void init(int_array* array, const int capacity) {


	//malloc()로 동적배열할당
	array->arr = (int*)malloc(sizeof(int) * capacity);
	//assert문
	assert(array->arr != NULL);
	//capacity(배열크기)를 정해준다.
	array->capacity = capacity;
	//초기화 size는 0
	array->size = 0;
}

int peek(int_array* array, const int index) {
	if (index >= 0 && index <= array->size - 1) {
		printf("%d", array->arr[index]);
		return array->arr[index];
	}
	else {
		printf("허용된 범위가 아니에요!");
		exit(1); //프로그램 종료
	}
}

int insert(int_array* array, const int index, const int value) {
	//만약 size랑 capacity같으면 push랑 동일 
	if (array->size == array->capacity) {
		int* temp = NULL;
		temp = realloc(array->arr, sizeof(int) * (array->capacity + 5));
		if (temp != NULL) {
			array->arr = temp;
			array->capacity = array->capacity + 5;
		}
		else {
			return 0;
		}
	}
	//가능한 위치(0~size)인지 확인
	if (index >= 0 && index <= array->size) {
		for (int i = array->size; i > index; i--) {
			array->arr[i] = array->arr[i - 1];  //한 칸씩 뒤로 복사
		}
		array->arr[index] = value; 
		array->size++;
		return 1;

	}
	else {
		return 0;
	}
}

void push(int_array* array, const int value) {

	//만약 size랑 capacity같으면 realloc으로 크기 +5
	if (array->size == array->capacity) {
		int* temp = NULL;
		temp = realloc(array->arr, sizeof(int) * (array->capacity + 5)); //크기재할당
		if ( temp != NULL) {
			array->arr = temp;
			array->capacity = array->capacity + 5;  //capacity변경
		}
	}

	array->arr[array->size] = value; //마지막 자리에 값 넣어주기
	array->size++; //사이즈 +1
}

int delete(int_array* array, const int index) {
	
	if (index >= 0 && index <= array->size - 1) {
		for (int i = index; i <  array->size-1; i++) {
			array->arr[i] = array->arr[i+1];  //한 칸씩 앞으로 복사
		}
		array->size--; 
		return 1;

	}
	else {
		return 0;
	}
}