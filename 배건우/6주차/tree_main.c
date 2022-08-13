#include "tree.h"
#include "tree.c"
#include <stdio.h>
#include <stdlib.h>


int main(void) {

    binary_search_tree* bst = (binary_search_tree*)malloc(sizeof(binary_search_tree));
    init_tree(bst);
    insert(bst, 8);
    insert(bst, 4);
    insert(bst, 3);
    insert(bst, 2);
    print_bst(bst, bst->root);
    printf("\n");

    delete_node(bst, 2);
    print_bst(bst, bst->root);











    return 0;
}