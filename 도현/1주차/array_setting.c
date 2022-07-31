#include "array_setting.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
*  헤더 파일에서 선언한 함수를 "반드시" 여기에 정의
*/

void init(int_array* array, const int capacity){
    array->arr = malloc(sizeof(int) * capacity);    // capacity만큼 동적 할당
    assert(array->arr != NULL); // 메모리 할당이 안되어있다면 프로그램 중단
    
    // 아래 부분부터는 성공적으로 메모리 할당이 되었다면 수행이 된다.
    array->capacity = capacity;
    array->size = 0;    // 처음에는 아무 데이터도 들어가있지 않으므로 size = 0 이다.
}


int insert(int_array* array, const int index, const int value){
    // 배열이 꽉 차 있다면 공간 재할당 필요
    if(array->capacity == array->size){
        int* temp = NULL;
        temp = realloc(array->arr, sizeof(int) * array->capacity*2); // 배열이 꽉찬 상태에서 삽입 시 2배씩 크기 증가
        // 공간 재할당이 성공했다면 arr = temp 및 capacity 갱신
        if(temp != NULL){
            array->arr = temp;
            array->capacity = array->capacity*2;  // capacity 갱신
        } else {
            // 재할당 실패 시 insert 실패이므로 0 리턴
            return 0;
        }
    }
    
    // index가 0보다 작게 들어오거나 size 보다 크게 들어온다면 insert 실패
    if(index < 0 || index > array->size){
        return 0;
    } else {
        // 정상 범위로 index가 들어왔다면 arr[index] ~ arr[size-1] 범위에 있는 값을 한 칸씩 뒤로 미룬다. (O(n))
        for(int i = array->size; i > index; i--){
            array->arr[i] = array->arr[i-1];
        }
        // 뒤로 미룬 후 index에 데이터 삽입
        array->arr[index] = value;
        array->size += 1;   // 데이터가 추가되었기 때문에 size 증가
        return 1;
    }
}


void push(int_array* array, const int value){
    // 배열이 꽉 차 있다면 공간 재할당 필요
    if(array->capacity == array->size){
        int* temp = NULL;
        temp = realloc(array->arr, sizeof(int) * array->capacity*2); // 배열이 꽉찬 상태에서 삽입 시 2배씩 크기 증가
        // 공간 재할당이 성공했다면 arr = temp 및 capacity 갱신
        if(temp != NULL){
            array->arr = temp;
            array->capacity = array->capacity*2;  // capacity 갱신
        }
    }
    
    // 데이터 삽입 (O(1))
    array->arr[array->size] = value;
    array->size += 1;   // 데이터가 추가되었기 때문에 size 증가
}


int delete(int_array* array, const int index){
    // index범위를 벗어나거나 배열이 비어있다면 삭제 연산 불가
    if(index < 0 || index > array->size || array->size == 0){
        return 0;
    } else {
        // 정상 범위로 index가 들어왔다면 arr[index+1] ~ arr[size-1] 범위에 있는 값을 한 칸씩 앞으로 당긴다. (O(n))
        for(int i = index; i < array->size-1; i++){
            array->arr[i] = array->arr[i+1];
        }
        // 위에서 값을 한 칸씩 앞으로 당겼기 때문에 원래 index에 있는 값은 다른 값으로 대체되며 삭제 되었다.
        
        array->size -= 1;   // 데이터가 삭제되었기 때문에 size 1 감소
        return 1;
    }
}


int peek(int_array* array, const int index){
    // index 범위를 벗어났다면 프로그램 종료
    if(index < 0 || index >= array->size){
        printf("Invalid access.. Program exit\n");
        exit(1);
    } else {
        int ans = array->arr[index];
        printf("[%d]: %d\n", index, ans);
        return ans;
    }
}

// 특정 데이터를 찾는 함수
void find(int_array* array, const int value){
    int_array indexArray;
    init(&indexArray, array->size); // array size 만큼 배열 생성 (data에 해당하는 index 값을 담을 배열 - 중복이 있기에 배열로 설정했습니다)
    
    for(int i = 0; i<array->size; i++){
        if(array->arr[i] == value) {
            push(&indexArray, i);
        }
    }
    
    if(indexArray.size == 0){
        printf("%d에 해당하는 데이터는 해당 배열에 존재하지 않습니다.\n", value);
    } else {
        for(int i = 0; i<indexArray.size; i++){
            if(i == indexArray.size - 1) {
                printf("%d 에 해당 데이터가 존재합니다.", indexArray.arr[i]);
            } else {
                printf("%d, ", indexArray.arr[i]);
            }
        }
    }
    free(indexArray.arr);
}


void display(int_array* array){
    printf("array size: %d\n", array->size);
    printf("array capacity: %d\n", array->capacity);
    for(int i = 0; i < array->size; i++){
        printf("[%d]: %d \n", i, array->arr[i]);
    }
}

