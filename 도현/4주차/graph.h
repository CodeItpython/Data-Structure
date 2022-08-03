//
//  graph.h
//  graph
//
//  Created by 정도현 on 2022/08/01.
//

#pragma once

typedef struct __weighted_undirected_graph{
    int nodeCount;  // 정점 개수
    int** arr;
    bool* visited;  // 탐색에 쓰일 점
}weighted_undirected_graph;

void init(weighted_undirected_graph* graph, int n); //n개의 정점인 그래프로 초기화
void insert_edge(weighted_undirected_graph* graph, int u, int v, int w);
void remove_edge(weighted_undirected_graph* graph, int u, int v);
int get_degree(weighted_undirected_graph* graph, int u);
void DFS(weighted_undirected_graph* graph, int u);
void BFS(weighted_undirected_graph* graph, int u);
