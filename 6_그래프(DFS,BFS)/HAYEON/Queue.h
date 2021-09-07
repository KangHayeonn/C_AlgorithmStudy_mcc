#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	queue->count = 0; // º¸°ü°³¼ö
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
void Printqueue(Queue* queue) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp = queue->front;
	printf("QÀÇ Ãâ·Â\n");
	printf("[ ");
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("]\n");
}
/*
int main(void) {
	Queue queue;
	InitQueue(&queue);
	for (int i = 1; i <= 5; i++) {
		Enqueue(&queue, i);
	}
	Printqueue(&queue);
	while (!IsEmpty(&queue)) {
		printf("%d ", Dequeue(&queue));
	}
	printf("\n");
	Printqueue(&queue);
	return 0;
}*/
