#pragma once
#include <stdio.h>
#include <stdlib.h>


typedef struct __tree_node {
	int key;
	struct __tree_node* left_child, * right_child;
}tree_node;

typedef struct __binary_search_tree {
	tree_node* root;
}binary_search_tree;

void init_tree(binary_search_tree* bst);
int insert(binary_search_tree* bst, int key);
int delete_node(binary_search_tree* bst, int key);
tree_node* find(binary_search_tree* bst, int key);
void tree_free(binary_search_tree* bst, tree_node* node);
binary_search_tree* tree_copy(binary_search_tree* target_bst);
void print_bst(binary_search_tree* bst, tree_node* node);
