#include "sample.c"
#include "sample.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    weighted_undirected_graph* G = (weighted_undirected_graph*)malloc(sizeof(weighted_undirected_graph));
    //할당을 여기서 해주어야만 오류가 안남

    init(G, 4);

    insert_edge(G, 0, 1, 1);//간선 추가
    insert_edge(G, 1, 2, 1);//간선 추가
    insert_edge(G, 1, 3, 1);//간선 추가
    insert_edge(G, 2, 3, 1);//간선 추가


    printGraph(G);


    return 0;


}

