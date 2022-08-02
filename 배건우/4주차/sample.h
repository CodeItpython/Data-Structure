#pragma once
#define MAX_VERTICES 50

typedef struct __weighted_undirected_graph {
    int size;
    int** arr;
}weighted_undirected_graph;

void init(weighted_undirected_graph* graph, int n); //n개의 정점인 그래프로 초기화
void insert_edge(weighted_undirected_graph* graph, int u, int v, int w);
void remove_edge(weighted_undirected_graph* graph, int u, int v);
int get_degree(weighted_undirected_graph* graph, int u);
void DFS(weighted_undirected_graph* graph, int u);
void BFS(weighted_undirected_graph* graph, int u);
void printGraph(weighted_undirected_graph* graph);


