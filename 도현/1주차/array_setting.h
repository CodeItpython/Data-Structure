//
//  array_setting.h
//  DKU_DataStructure
//
//  Created by 정도현 on 2022/07/06.
//

#pragma once

typedef struct __int_array{
    int* arr; // 배열 주소
    int size;   // 현 배열에 있는 데이터 개수( siez <= capacity)
    int capacity;   // 할당된 크기
}int_array;

void init(int_array* array, const int capacity);    //배열 초기화
int peek(int_array* array, const int index);
int insert(int_array* array, const int index, const int value);
void push(int_array* array, const int value);
int delete(int_array* array, const int index);
void find(int_array* array, const int value);
void display(int_array* array);

