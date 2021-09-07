// 자료구조 6주차
// DFS/BFS

// BFS (Breadth First Search)
// : 넓게 넓게 파고드는 탐색 알고리즘.
//	 만약, 인접한 정점을 발견하면 거길 탐색하고 다시 캠프로 돌아와서 다음 인접 정점을 탐색
// ** 선입선출(큐)

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void BFS(int*** graph, int N, int START, int** bfs_arr) {
	Queue queue;
	InitQueue(&queue);
	
	Enqueue(&queue, START);
	printf("%d ", START);
    bfs_arr[0][START] = 1;
	
	while (!IsEmpty(&queue)) {
		int Pop = Dequeue(&queue);
		for (int i = 1; i <= N; i++) {
			if (graph[0][Pop][i] == 1 && bfs_arr[0][i] == 0) {
				printf("%d ", i);
				Enqueue(&queue, i);
				bfs_arr[0][i] = 1;
			}
		}
	}

	return;
}

int main() {
	int N, M, V;
	int** graph;
	int j, k;

	scanf("%d %d %d", &N, &M, &V);

	int* bfs_arr = (int*)calloc(N + 1, sizeof(int));

	graph = (int**)malloc(sizeof(int*) * (N + 1));

	for (int i = 0; i < N + 1; i++) graph[i] = (int*)calloc(N + 1, sizeof(int));

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		graph[j][k] = 1;
		graph[k][j] = 1;
	}
	
	BFS(&graph, N, V, &bfs_arr);

	for (int i = 0; i < M; i++) free(graph[i]);

	free(graph);
	free(bfs_arr);

	return 0;
}
