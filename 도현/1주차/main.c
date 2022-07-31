#include "array_setting.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int_array intArr;
    int arrCapacity;
    printf("Specify the array size: ");
    scanf("%d", &arrCapacity);
    
    init(&intArr, arrCapacity);
    
    while(1) {
        printf("===== Select option ===== \n");
        printf("0. exit\n");
        printf("1. insert\n");
        printf("2. push\n");
        printf("3. delete\n");
        printf("4. peek\n");
        printf("5. find\n");
        printf("option number >> ");
        int option, idx, val;
        scanf("%d", &option);
        switch(option){
            case 0:
                printf("exit program\n");
                exit(1);
                break;
            case 1:
                printf("Enter index & value: ");
                scanf("%d %d", &idx, &val);
                if(insert(&intArr, idx, val)){
                    printf("insert success!\n");
                    display(&intArr);
                } else {
                    printf("insert fail. \n");
                    display(&intArr);
                }
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                push(&intArr, val);
                display(&intArr);
                break;
            case 3:
                printf("Enter the index you want to delete: ");
                scanf("%d", &idx);
                if(delete(&intArr, idx)){
                    printf("delete success!\n");
                    display(&intArr);
                } else {
                    printf("delete fail. \n");
                    display(&intArr);
                }
                break;
            case 4:
                printf("Enter the index of the data you want to see: ");
                scanf("%d", &idx);
                peek(&intArr, idx);
                break;
            case 5:
                printf("Enter the data you want to find: ");
                scanf("%d", &val);
                find(&intArr, val);
                break;
            default:
                printf("please enter valid number \n");
        }
    }
    return 0;
}
