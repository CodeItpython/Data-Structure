//
//  main.c
//  graph
//
//  Created by 정도현 on 2022/08/01.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"

int main(int argc, const char * argv[]) {
    weighted_undirected_graph *graph = (weighted_undirected_graph *)malloc(sizeof(weighted_undirected_graph));
    
    int n, m;
    
    printf("정점 개수와 간선 수를 순서대로 입력해주세요 : ");
    scanf("%d %d", &n, &m);
    
    init(graph, n);
    
    
    int start, dest, w;
    for(int i = 0; i < m; i++) {
        printf("간선 정보 입력 -> [출발] [도착] [가중치] : ");
        scanf("%d %d %d", &start, &dest, &w);
        insert_edge(graph, start, dest, w);
    }
    
    int menu;
    while(true) {
        printf("0 - 프로그램 종료 \n");
        printf("1 - 간선 삽입 \n");
        printf("2 - 간선 삭제 \n");
        printf("3 - 노드 차수 얻기 \n");
        printf("4 - DFS \n");
        printf("5 - BFS \n");
        printf("원하는 작업 번호를 선택하세요: ");
        
        scanf("%d", &menu);
        
        switch(menu){
            case 0:
                exit(1);
                break;
            case 1:
                printf("삽입 간선 정보 입력 -> [출발] [도착] [가중치] : ");
                scanf("%d %d %d", &start, &dest, &w);
                insert_edge(graph, start, dest, w);
                break;
            case 2:
                printf("삭제 간선 정보 입력 -> [출발] [도착] : ");
                scanf("%d %d", &start, &dest);
                remove_edge(graph, start, dest);
                break;
            case 3:
                printf("원하는 정점 번호 입력 : ");
                scanf("%d", &start);
                printf("%d 정점의 차수 = %d\n", start, get_degree(graph, start));
                break;
            case 4:
                printf("시작 정점을 입력하세요 :");
                scanf("%d", &start);
                DFS(graph, start);
                break;
            case 5:
                printf("시작 정점을 입력하세요 :");
                scanf("%d", &start);
                BFS(graph, start);
                break;
            default:
                printf("정확하게 다시 입력해주세요");
        }
    }
}
