#pragma once

typedef struct _Heap{
    //최대 힙 혹은 최소 힙 구현
    //힙에 저장할 데이터의 타입은 자유
}Heap;


void init(Heap* heap); //n개의 정점인 그래프로 초기화
void init(Heap* heap);
void push(Heap* heap, int data);   //data 타입은 자유롭게
void pop(Heap* heap);
int peek(Heap* heap);
int isEmpty(Heap* heap);

void heap_sort(int* arr, int n);    //arr[1] ~ arr[n] 까지 정렬
