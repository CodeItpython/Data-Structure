#include "answer.h"

void init(float_double_linked_list* list){
    list->head=list->tail=NULL;
}

float_node* peek(float_double_linked_list* list, const int at){
    int i=0;
    float_node* target=NULL:
    for(target=list->head;target!=NULL&&i<at;target=target->next,++i);
    return target;
}

float_node* find(float_double_linked_list* list, const float target){
    for(float_node* now=list->head;now!=NULL;now=now->next){
        if(now->data==target){
            return now;
        }
    }
    return NULL;
}

int insert(float_double_linked_list* list, const int at, const float value){
    if(at==0){
        push_front(list,value);
    }
    else{
        int i=0;
        float_node* node=list->head;
        for(;node!=NULL&&i<at;node=node->next,++i);
        if(node==NULL){
            if(i==at){
                push_back(list,value);
            }
            else{
                return 0;
            }
        }
        }
        else{
            float_node* new_node=create_node(value);
            node->previous->next=new_node;
            new_node->previous=node->previous;
            new_node->next=node;
            node->previous=new_node;
        }
    }
    return 1;
}

void push_back(float_double_linked_list* list, const float value){
    if(list->head==NULL){
        list->head=list->tail=create_node(value);
    }
    else{
        float_node* new_node=create_node(value);
        list->tail->next=new_node;
        new_node->previous=list->tail;
        list->tail=new_node;
    }
}

void push_front(float_double_linked_list* list, const float value){
    if(list->head==NULL){
        list->head=list->tail=create_node(value);
    }
    else{
        float_node* new_node=create_node(value);
        list->head->previous=new_node;
        new_node->next=list->head;
        list->head=new_node;
    }
}

int delete(float_double_linked_list* list, const int at){
    if(list->head==NULL){
        return 0;
    }
    float_node* del_node=NULL;
    if(at==0){
        del_node=list->head;
        if(list->head==list->tail){
            list->head=list->tail=NULL;
        }
        else{
            list->head=list->head->next;
            list->head->previous=NULL:
        }
    }
    else{
        int i=0;
        for(del_node=list->head;i<at&&del_node!=NULL;++i,del_node=del_node->next);
        if(del_node==NULL){
            return 0;
        }
        else if(del_node==list->tail){
            list->tail=list->tail->previous;
            list->tail->next=NULL;
        }
        else{
            del_node->previous->next=del_node->next;
            del_node->next->previous=del_node->previous;
        }
    }
    free_node(del_node);
    return 1;
}

float_node* create_node(const float value){
    float_node* node=(float_node*)malloc(sizeof(float_node));
    node->data=value;
    node->next=node->previous=NULL;
    return node;
}

void free_node(float_node* node){
    free(node);
}