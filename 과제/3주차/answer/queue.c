#include "queue.h"

void init(int_queue* queue){
    queue->front=queue->rear=NULL;
}

void push(int_queue* queue, int data){
    int_node* node=NULL;
    node=create_node(data);
    if(isEmpty(queue)==1){
        queue->front=queue->rear=node;
    }
    else{
        queue->rear->next=node;
        queue->rear=node;
    }
}
void pop(int_queue* queue){
    if(isEmpty(queue)==0){
        int_node* del_node=queue->front;
        if(queue->front==queue->rear){
            queue->front=queue->rear=NULL;
        }
        else{
            queue->front=queue->front->next;
        }
        free_node(del_node);
    }
}
int peek(int_queue* queue){
    if(isEmpty(queue)==0){
        return queue->front->data;
    }
    else{
        exit(1);
    }
}

int isEmpty(int_queue* queue){
    return queue->front==NULL?1:0;
}

int_node* create_node(int data){
    int_node* ret=(int_node*)malloc(sizeof(int_node));
    ret->data=data;
    ret->next=NULL;
    return ret;
}

void free_node(int_node* node){
    free(node);
}

