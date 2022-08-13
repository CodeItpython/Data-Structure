#include "tree.h"
#include <stdio.h>
#include <stdlib.h>



void init_tree(binary_search_tree* bst) {
    bst->root = NULL;
}

int insert(binary_search_tree* bst, int key) {
    tree_node* newNode = (tree_node*)malloc(sizeof(tree_node));
    tree_node* cur = bst->root;
    newNode->key = key;
    newNode->left_child = newNode->right_child = NULL;
    //root노드가 NULL일경우 새로운노드를 root노드로 지정
    if (bst->root == NULL)
        bst->root = newNode;

    while (cur != NULL) {
        //삽입하려는 key의값이 더 클경우 
        if (cur->key < key) {
            if (cur->right_child == NULL) {
                cur->right_child = newNode;
                return 1;
            }
            else
                cur = cur->right_child;
        }
        //삽입하려는 key의값이 더 작을경우
        else if (cur->key > key) {
            if (cur->left_child == NULL) {
                cur->left_child = newNode;
                return 1;
            }
            else
                cur = cur->left_child;
        }
        //삽입하려는 key의값이 같을경우
        else
            return 0;
    }

}

int delete_node(binary_search_tree* bst, int key) {
    tree_node* cur2 = NULL;
    tree_node* cur = bst->root;
    tree_node* parent = NULL;
    tree_node* child = NULL;
    tree_node* left_temp = NULL;

    //내가 원하는 key의값의 노드를 찾는과정
    while (cur->key != key)
    {
        if (key > cur->key) {
            parent = cur;  //이동하기전의 cur노드를 parent에 저장
            cur = cur->right_child;
        }
        else {
            parent = cur;   //이동하기전의 cur노드를 parent에 저장
            cur = cur->left_child;
        }
    }

    //삭제하려는노드의 차수가 0인경우
    if ((cur->left_child == NULL) && (cur->right_child == NULL)) {
        if (parent->left_child == cur)
            parent->left_child = NULL;
        if (parent->right_child == cur)
            parent->right_child = NULL;
        tree_free(bst, cur);  //할당해제
        return 1;
    }


    //삭제하려는노드의 차수가 1인경우
    if ((cur->left_child == NULL) || (cur->right_child == NULL)) {
        if (cur->left_child != NULL)    //삭제하려는 노드의 좌측노드가 존재하는경우
            child = cur->left_child;    //child노드를 지정
        else if (cur->right_child != NULL)    //삭제하려는 노드의 우측노드가 존재하는경우
            child = cur->right_child;   //child노드를 지정
        else if (parent->left_child == cur) //부모노드의 좌측노드가 삭제하려는노드일때 
            parent->left_child = child; //삭제노드를 건너뛴 child로 지정
        else    //부모노드의 우측노드가 삭제하려는노드일때
            parent->right_child = child;    //삭제노드를 건너뛴 child로 지정
        tree_free(bst, cur);  //할당해제
        return 1;
    }

    //삭제하려는노드의 차수가 2인경우
    if ((cur->left_child != NULL) && (cur->right_child != NULL)) {
        cur2 = cur;
        cur2 = cur2->right_child;

        if (cur2->left_child == NULL) { //삭제하려는노드의 우측이동한후의 좌측노드가 없을경우
            left_temp = cur->left_child;
            child = cur2;
            if (parent->right_child == cur) {
                parent->right_child = child;
                child->left_child = left_temp;
            }
            else if (parent->left_child == cur) {
                parent->left_child = child;
                child->left_child = left_temp;
            }
            tree_free(bst, cur);
            return 1;
        }

        while (cur2->left_child != NULL) {  //삭제하려는노드의 우측이동한후의 좌측노드가 있을경우
            parent = cur2;  //cur2의 자리를 parent에 놓고 
            cur2 = cur2->left_child;    //가장 작은값을 찾아 탐색을 이어나간다
        }

        parent->left_child = NULL;
        cur->key = cur2->key;
        tree_free(bst, cur2);   //할당해제
    }
    //없는값을 입력했을경우
    return 0;
}



tree_node* find(binary_search_tree* bst, int key) {
    tree_node* cur = bst->root;
    while (cur != NULL) {
        if (cur->key == key)    //파라미터로 넣은 key의값을 찾았을경우
            return cur;
        else if (cur->key < key)
            cur = cur->right_child;
        else
            cur = cur->left_child;
    }
    return NULL;    //찾지못했을경우
}


void tree_free(binary_search_tree* bst, tree_node* node) {
    if (node != NULL) {
        tree_free(bst, node->left_child);
        tree_free(bst, node->right_child);
        free(node);
    }
}

binary_search_tree* tree_copy(binary_search_tree* target_bst) {
    binary_search_tree* copied_bst = (binary_search_tree*)malloc(sizeof(binary_search_tree));
    tree_node* cur = target_bst->root;

    copied_bst->root->left_child = tree_copy(target_bst)->root;
    copied_bst->root->right_child = tree_copy(target_bst)->root;
    copied_bst->root->key = cur->key;

    return copied_bst;
}


void print_bst(binary_search_tree* bst, tree_node* node) {
    if (node != NULL) {
        print_bst(bst, node->left_child);
        printf("%d ", node->key);
        print_bst(bst, node->right_child);
    }
}

