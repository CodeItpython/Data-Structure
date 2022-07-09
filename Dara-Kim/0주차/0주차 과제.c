/*c언어에서의 메모리 동적할당은 malloc, calloc, realloc으로 가능함.

malloc 함수의 원형 : void* malloc(size_t size)
-- > 함수 호출 시 할당하고자 하는 메모리의 크기를 바이트 단위로 전달하면
그 크기만큼 메모리를 할당하게 되고, 할당한 메모리의 첫 번째 바이트 주소를 리턴.
실패 시 NULL 리턴.

calloc 함수의 원형 : void* calloc(size_t elt_count, size_t elt_size)
-- > elt_size 크기의 변수를 elt_count개 만큼 저장할 수 있는 메모리 공간을 할당하고,
그 공간의 값을 전부 0으로 바꾼다.리턴은 malloc과 동일.

realloc 함수의 원형 : void* realloc(void* memblock, size_t size);
-- > 이미 할당한 포인터 변수를 memblock에 넣고, 공간의 크기를 size에 입력된 값으로 바꾼다.

free 함수의 원형 : void free(void* ptr)
-- > 메모리 해제 필수

공부할 때 참고한 블로그 :
https://dsnight.tistory.com/51*/

#define _CRTDBG_MAP_ALLOC // CRT 힙 함수의 기본 버전을 해당 디버그 버전에 매핑
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // malloc 및 free 함수가 해당 디버그 버전인 _malloc_dbg 및 _free_dbg에 매핑되어 메모리 할당 및 할당 해제를 추적 가능하게 됨


int main() {
	int arr_1[5];	// 배열 선언
	int* arr_2;		// 포인터 변수 선언
	int i;

	for (i = 0; i < 5; i++) {
		arr_1[i] = i + 1;	// 배열에 값 대입
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);	// 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free함수를 이용하여 메모리 해제

	_CrtDumpMemoryLeaks(); // 앱이 종료될 때 메모리 누수 보고서를 표시

	return 0;
}

#define _CRTDBG_MAP_ALLOC // CRT 힙 함수의 기본 버전을 해당 디버그 버전에 매핑
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // malloc 및 free 함수가 해당 디버그 버전인 _malloc_dbg 및 _free_dbg에 매핑되어 메모리 할당 및 할당 해제를 추적 가능하게 됨

int main() {
	int arr_1[5];	// 배열 선언
	int* arr_2;		// 포인터 변수 선언
	int i;

	for (i = 0; i < 5; i++) {
		arr_1[i] = i + 1;	// 배열에 값 대입
	}

	//arr_2 = (int*) malloc(sizeof(int)*5);	// 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함
	arr_2 = (int*)calloc(5, sizeof(int));	// sizeof(int)크기의 변수를 5개 저장할 수 있는 공간할당

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free함수를 이용하여 메모리 해제

	_CrtDumpMemoryLeaks(); // 앱이 종료될 때 메모리 누수 보고서를 표시

	return 0;
}

#define _CRTDBG_MAP_ALLOC // CRT 힙 함수의 기본 버전을 해당 디버그 버전에 매핑
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> // malloc 및 free 함수가 해당 디버그 버전인 _malloc_dbg 및 _free_dbg에 매핑되어 메모리 할당 및 할당 해제를 추적 가능하게 됨

int main() {
	int arr_1[10];	// 배열 선언
	int* arr_2;		// 포인터 변수 선언
	int i;

	for (i = 0; i < 10; i++) {
		arr_1[i] = i + 1;	// 배열에 값 대입
	}

	arr_2 = (int*)malloc(sizeof(int) * 5);	// 메모리 할당, 배열의 크기만큼 할당하기 위해 5를 곱함

	for (i = 0; i < 5; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	printf("\n");

	// sizeof(int) = 4바이트
	realloc(arr_2, sizeof(int) * 10);	// arr_2의 메모리를 40바이트로 재 할당
	// arr_2의 메모리 크기 : 20바이트 -> 40바이트

	for (i = 0; i < 10; i++) {
		arr_2[i] = arr_1[i];
		printf("%d ", arr_2[i]);
	}

	free(arr_2);	// free함수를 이용하여 메모리 해제

	_CrtDumpMemoryLeaks(); // 앱이 종료될 때 메모리 누수 보고서를 표시

	return 0;
}

