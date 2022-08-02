#include "sample.h"
#include <stdio.h>
#include <stdlib.h>

void init(weighted_undirected_graph* graph, int n) {
    int i, j = 0;

    graph->size = n;
    graph->arr = malloc(sizeof(int*) * n);

    for (i = 0; i < n; i++) {
        graph->arr[i] = malloc(sizeof(int) * n);
    }

    // 그래프 초기화
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph->arr[i][j] = 0;
        }
    }
}

void insert_edge(weighted_undirected_graph* graph, int u, int v, int w) {
    graph->arr[u][v] = w;
    graph->arr[v][u] = w;
}

void remove_edge(weighted_undirected_graph* graph, int u, int v) {
    graph->arr[u][v] = 0;
    graph->arr[v][u] = 0;
}

int get_degree(weighted_undirected_graph* graph, int u) {
    int degree;
    for (int i = 0; i < graph->size; i++)
    {
        degree = 0;//0으로 설정
        if (graph->arr[u][i] != 0)
        {
            degree++;//차수 1 증가
        }
    }
    return degree;
}

void DFS(weighted_undirected_graph* graph, int u) {

}

void BFS(weighted_undirected_graph* graph, int u) {

}

void printGraph(weighted_undirected_graph* graph)
{
    for (int i = 0; i < graph->size; i++) {
        for (int j = 0; j < graph->size; j++) {
            printf("%d ", graph->arr[i][j]);
        }
        printf("\n");
    }
}


