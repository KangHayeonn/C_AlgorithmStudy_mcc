// 자료구조 6주차
// DFS/BFS

// DFS (Depth First Search)
// : 인접한 정점이 존재한다면 계속 한 우물만 깊게 파고드는 알고리즘
//	 만약, 인접한 정점이 막다른 길에 부딪힌다면, 이 전에 있었던 정점으로 돌아가서 또 새로운 우물이 있는지 봄
// ** 재귀함수 사용 
// 시간나면 스택 이용하는 것도 한번 짜보기 !

#include <stdio.h>
#include <stdlib.h>

void DFS(int** graph, int N, int START, int** dfs_arr) {
	printf("%d", START);
	// printf("%d", *(*dfs_arr+START));
	// printf("%d", dfs_arr[0][START]);

	*(*dfs_arr + START) = 1;
	for (int i = 1; i < N + 1; i++) {
		if (graph[START][i] == 1 && dfs_arr[0][i] == 0) {
			DFS(graph, N, i, dfs_arr);  // dfs_arr 주솟값 자체를 보냄
		}
	}
	return;
}

int main() {
	int N, M, V;
	int** graph;
	int j, k;

	scanf("%d %d %d", &N, &M, &V);

	int* dfs_arr = (int*)calloc(N + 1, sizeof(int));
	int* bfs_arr = (int*)calloc(N + 1, sizeof(int));

	graph = (int**)malloc(sizeof(int*) * (N + 1));

	for (int i = 0; i < N + 1; i++) graph[i] = (int*)calloc(N + 1, sizeof(int));

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		graph[j][k] = 1;
		graph[k][j] = 1;
	}
	/*
	for (int i = 0; i < N+1; i++)
		for (int j = 0; j < N+1; j++)
			printf("graph[%d][%d] = %d\n", i, j, graph[i][j]);
	*/
	DFS(graph, N, V, &dfs_arr); // 이차원 배열처럼 dfs_arr 주솟값 자체를 보냄

	for (int i = 0; i < M; i++) free(graph[i]);

	free(graph);
	free(dfs_arr);

	return 0;
}
