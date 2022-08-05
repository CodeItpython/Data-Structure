#include "sample.h"
#include <stdio.h>
#include <stdlib.h>

void init(Heap* heap) { //초기화함수
    heap->size = 0;
}

void push(Heap* heap, int data) {
    int index;
    if (heap->size >= (MAX_COUNT - 1)) {    //꽉찬경우
        printf("full\n");
        return;
    }

    heap->size++;  //삽입진행할것이므로 size를 1증가시킨다.
    index = heap->size;
    heap->data[index] = data;   //마지막노드에 집어넣는다

    while ((index != 1) && (heap->data[index / 2] < heap->data[index])) {   //index가 부모노드가 아니고 
        //삽입된노드의 부모노드가 더 작을시 진행
        //아래의 코드는 swap을 진행
        int temp = heap->data[index / 2];
        heap->data[index / 2] = heap->data[index];
        heap->data[index] = temp;

        index = index / 2;  //index를 최신화(부모노드로)
    }
}

void pop(Heap* heap) {
    int parent, child;
    int item, tmp;

    item = heap->data[1];   //item을 루트노드로 지정
    tmp = heap->data[heap->size];   //tmp를 힙의 마지막노드로 지정
    heap->size = heap->size - 1;    //삭제를 진행할예정이므로 size를 1줄임

    parent = 1;
    child = 2;

    while (child <= heap->size) {       //반복문은 child가 마지막노드까지 돌아야한다.

        if ((child < heap->size) && (heap->data[child]) < heap->data[child + 1])
            child++;
        if (tmp >= heap->data[child])   //tmp값이 child번째 노드보다 크거나같으면 break
            break;

        else {  //위조건이 모두아니면 child번째 노드를 루트노드에 담고 왼쪽자식노드로 이동후 루프를 다시돈다
            heap->data[parent] = heap->data[child];
            parent = child;
            child = child * 2;
        }
    }

    heap->data[parent] = tmp;

}

int peek(Heap* heap) {
    return heap->data[1];
}

int isEmpty(Heap* heap) {   //heap이 비어있는지를 확인
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

void print_heap(Heap* heap) {   //출력함수 구현
    int i;
    for (i = 1;i <= heap->size; i++)
        printf("%d ", heap->data[i]);
    printf("\n");
}

