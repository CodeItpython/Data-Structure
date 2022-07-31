#include "stack.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
    int* number_order;
    int n;
    int max_number=0; //스택에 넣은 수 중, 가장 큰 수
    int flag=1;
    int_stack stack;
    scanf("%d",&n);
    number_order=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;++i){
        scanf("%d", number_order+i);
    }
    init(&stack);
    for(int i=0;i<n;++i){
        int now_pick=number_order[i];
        //지금까지 스택에 넣은 수 중
        //가장 큰 수 보다 큰 수를 뽑아야 한다면
        //스택에 숫자들 push
        if(max_number<now_pick){
            for(int number=max_number+1;number<=now_pick;++number){
                push(&stack,number);
            }
            max_number=now_pick;
        }
        //그렇지 않다면 스택에서 지금 뽑을 수가 현재 순서의 수인지 확인
        //현재 순서의 수가 아니라면 다른 숫자가 스택에서 제거 되므로
        //number_order의 숫자의 개수 n 개를 맞출 수 없음
        else{
            if(isEmpty(&stack)==0&&peek(&stack)!=now_pick){
                flag=0;
                break; 
            }
        }
        //현재 순서의 수를 스택에서 제거
        pop(&stack);
    }
    if(flag==0){
        printf("No");
    }
    else{
        printf("Yes");
    }
    return 0;
}