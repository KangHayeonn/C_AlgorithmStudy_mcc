// DFS와 BFS (백준 1260번)

#include <stdio.h>
#include <stdlib.h>

typedef int Data;
typedef struct Node {
	Data data;
	struct Node* next;
}Node;
typedef struct Queue {
	Node* front;
	Node* rear;
	int count;
}Queue;

void InitQueue(Queue* queue) {
	queue->front = queue->rear = NULL;
	queue->count = 0; // 보관개수
}

int IsEmpty(Queue* queue) {
	return queue->count == 0;
}

void Enqueue(Queue* queue, Data data) {
	Node* now = (Node*)malloc(sizeof(Node));
	now->data = data;
	now->next = NULL;

	if (IsEmpty(queue)) {
		queue->front = now;
	}
	else queue->rear->next = now;

	queue->rear = now;
	queue->count++;
}
int Dequeue(Queue* queue) {
	Data requeue = 0;
	Node* now;
	if (IsEmpty(queue)) return requeue;
	now = queue->front;
	requeue = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;
	return requeue;
}

void DFS(int** graph, int N, int START, int** dfs_arr) {
	printf("%d ", START);
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

	int* dfs_arr = (int*)calloc(N + 1, sizeof(int));
	int* bfs_arr = (int*)calloc(N + 1, sizeof(int));

	graph = (int**)malloc(sizeof(int*) * ((N+1)*(N+1)));

	for (int i = 0; i < N + 1; i++) graph[i] = (int*)calloc(N +1, sizeof(int));

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &j, &k);
		graph[j][k] = 1;
		graph[k][j] = 1;
	}
	
	DFS(graph, N, V, &dfs_arr); // 이차원 배열처럼 dfs_arr 주솟값 자체를 보냄
	printf("\n");
	BFS(&graph, N, V, &bfs_arr);

	for (int i = 0; i < M; i++) free(graph[i]);

	free(graph);
	free(dfs_arr);
	free(bfs_arr);

	return 0;
}
