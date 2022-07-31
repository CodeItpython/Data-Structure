#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	int_array test;
	init(&test, 10);

	printf("test1. push\n");
	for (int i = 0; i < 10; i++) {
		push(&test, i);
		printf(" %d", peek(&test, i));
	}
	printf("\n\n");

	printf("test2. 3번째 위치에 5를 insert\n");
	insert(&test, 3, 5);
	for (int i = 0; i < test.size; i++) {
		printf("% d", peek(&test, i));
	}
	printf("\n\n");

	printf("test3. 5번째 위치의 원소를 delete\n");
	delete(&test, 5);
	for (int i = 0; i < test.size; i++) {
		printf(" %d", peek(&test, i));
	}
	printf("\n");

	free(test.arr);

    return 0;
}

