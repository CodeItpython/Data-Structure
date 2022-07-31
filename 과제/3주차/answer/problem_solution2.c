#include "queue.h"
#include <stdio.h>

int main(){
    int_queue queue;    //초기 A 에서 맨 앞에 있는 수는 뒤로 가기에 큐로 관리
    int n,k;
    int* order;
    scanf("%d %d",&n,&k);
    order=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;++i){
        scanf("%d",order+i);
    }
    init(&queue);
    for(int i=0;i<n;++i){
        //초기 A
        push(&queue,order[i]);
    }
    for(int i=0;i<n;++i){
        //n개의 수가 빠지므로 n번 반복
        int now;
        for(int j=1;j<k;++j){   //앞의 수를 뒤로 옮기는 과정을 k-1 번 반복 
            now=peek(&queue);
            pop(&queue);
            push(&queue,now);
        }
        //k번째수를 제거
        now=peek(&queue);
        pop(&queue);
        printf("%d ", now);
    }
    return 0;
}