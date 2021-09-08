// 작성전
#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50


typedef struct GraphType {
	int n; // 정점 개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int visited[MAX_VERTICES]; //DFS용

//그래프 초기화
void init(GraphType* g) {
	int i, j;
	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++)
		for (j = 0; j < MAX_VERTICES; j++)
			g->adj_mat[i][j] = 0;
}

//정점 추가
void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프 : 정점의 개수 초과");
		return;
	}
	g->n++;
}

//간선 삽입

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프 : 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

//함수 출력
void print(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

//깊이 우선 탐색(DFS)
void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = true; //정점 v의 방문 표시
	printf("정점 %d ->", v); //방문한 정점 출력
	for (w = 0; w < g->n; w++) //인접 정점 탐색
		if (g->adj_mat[v][w] && !visited[w])
			dfs_mat(g, w); //정점 w에서 다시 깊이 우선 탐색
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 4);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 4);

	dfs_mat(g, 0);

	return 0;
}
