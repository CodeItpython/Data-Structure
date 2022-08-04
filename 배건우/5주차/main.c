#include "sample.h"
#include "sample.c"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int count;
    Heap heap;
    init(&heap);    //초기화

    push(&heap, 17);    //삽입
    push(&heap, 29);
    push(&heap, 27);
    push(&heap, 15);
    push(&heap, 34);

    print_heap(&heap);  //출력

    printf("peek(&heap)=%d\n", peek(&heap));    //루트노드 출력


    count = heap.size;
    for (int i = 0;i < count; i++) //노드를 삭제
        pop(&heap);
    print_heap(&heap);  //출력



    int n = 10;
    int arr[10] = { 5, 6, 10, 4, 3, 8, 7, 1, 2, 9 };    //임의의 배열생성

    for (int i = 0;i < 10;i++) {    //힙정렬 실행
        heap_sort(arr, n);
        heap_sorting(arr, &n);
    }

    //출력 
    for (int i = 0;i < 10; i++) {   //정렬됐는지 확인
        printf("%d ", arr[i]);
    }

    return 0;
}

