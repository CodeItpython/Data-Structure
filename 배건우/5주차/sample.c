#include "sample.h"
#include <stdio.h>
#include <stdlib.h>

void init(Heap* heap) {
    heap->size = 0;
}

void push(Heap* heap, int data) {
    int index;
    if (heap->size >= (MAX_COUNT - 1)) {
        printf("full\n");
        return;
    }

    heap->size++;
    index = heap->size;
    heap->data[index] = data;

    while ((index != 1) && (heap->data[index / 2] < heap->data[index])) {
        int temp = heap->data[index / 2];
        heap->data[index / 2] = heap->data[index];
        heap->data[index] = temp;

        index = index / 2;
    }
}

void pop(Heap* heap) {
    int cur, child;
    int temp;
    int topdata = heap->data[1];
    if (heap->size == 0) {  //힙이 비어있는경우
        printf("empty\n");
        return;
    }

    heap->data[1] = heap->data[heap->size];
    heap->size--;

    cur = 1;
    while ((cur * 2) <= heap->size) {
        child = cur * 2;
        if (((child + 1) <= heap->size) && (heap->data[child] < heap->data[child + 1]))
            child++;
        if (heap->data[child] < heap->data[child + 1])
            break;
        temp = heap->data[child];
        heap->data[child] = heap->data[cur];
        heap->data[cur] = temp;

        cur = child;
    }
}

int peek(Heap* heap) {
    return heap->data[1];
}

int isEmpty(Heap* heap) {
    if (heap->size == 0)
        return 0;
    else
        return 1;
}

void heap_sort(int* arr, int n) {
    for (int i = 1;i < n;++i) {
        int child = i;
        do {
            //자식 노드가 부모 노드보다 크면 교환
            int root = (child - 1) / 2;
            if (arr[root] < arr[child]) {
                int temp = arr[root];
                arr[root] = arr[child];
                arr[child] = temp;
            }
            child = root;
        } while (child != 0);	//최상단 노드까지 점검
    }
}

void heap_sorting(int* arr, int* n) {
    int temp = arr[0];
    arr[0] = arr[*n - 1];
    arr[*n - 1] = temp;
    --(*n);
}

void print_heap(Heap* heap) {
    int i;
    for (i = 1;i <= heap->size; i++)
        printf("%d ", heap->data[i]);
    printf("\n");
}

