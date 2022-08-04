#pragma once
#define MAX_COUNT 100

typedef struct {
    int data[MAX_COUNT];
    int size;
}Heap;


void init(Heap* heap); //n개의 정점인 그래프로 초기화
void push(Heap* heap, int data);   //삽입함수
void pop(Heap* heap);//루트노드를 삭제하는 함수
int peek(Heap* heap);   //루트노드를 반환
int isEmpty(Heap* heap);    //힙의 원소 존재 판별
void heap_sort(int* arr, int n);    //arr[1] ~ arr[n] 까지 정렬
void heap_sorting(int* arr, int* n);
void print_heap(Heap* heap);    //힙 출력함수

