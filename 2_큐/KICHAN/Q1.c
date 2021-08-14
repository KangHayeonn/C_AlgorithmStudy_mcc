// 큐 형식은 구글링,,,,,
#include <stdio.h>
#include <stdlib.h>

// 카드문제 
// 1 2 3 4 차례로 enqueue
// 1 dequeue, 2dequeue 후 enqueue, 3 dequeue, 4 dequeu 후 enqueue
// 1 2 3 4 - 2 3 4 - 3 4 - 3 4 2 - 4 2 - 2 - 2 4 - 4
// enqueue - dequeue-...

typedef struct Node{ //노드 구조체 선언  
	int data;
	struct Node *next;
}Node;

typedef struct Queue{ // 큐 구조체 선언  
	Node *front;
	Node *rear;
	int count;
}Queue;

void initQueue(Queue *queue); // queue초기화 
// 큐가 비어있는지 확인
int isEmpty(Queue *queue);
// enqueue
void Enqueue(Queue *queue, int data);
// dequeue
int Dequeue(Queue *queue);

void initQueue(Queue *queue) {
	queue->front = queue->rear = NULL;
	queue->count = 0;
}
int card(Queue *queue);
int card(Queue *queue){
	return queue->count ==1;
}


// 큐가 비어있는지 확인  

int isEmpty(Queue *queue) {
	return queue->count == 0; // queue count 가 0일때 비어있다. 
}
// enqueue
void Enqueue(Queue *queue, int data){
     Node *now = (Node*)malloc(sizeof(Node));
	 now->data = data;
	 now->next = NULL;
	 
	 if(isEmpty(queue)){
	 	queue->front = now;
	 }	
	 else
	 {
	 	queue->rear->next = now;
	 }
	 queue->rear = now;
	 queue->count++;
}

// dequeue
int Dequeue(Queue *queue){
    int re = 0;
	Node *now; //큐에서 빠져나가는 데이터 저장할 함수  
	if(isEmpty(queue)){
		return re; //큐가 비어있으면 돌려줄게 없음 
	}
	now = queue->front;
	re = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;	
	return re;
	
}

int main()
{
	int i, N, k;
	Queue queue;
	
	printf("카드의 갯수:");
	scanf("%d", &N);
	 
	initQueue(&queue);
	for(i =1; i<=N; i++){
		Enqueue(&queue,i);
	}
	// 노드의 갯수가 1일떼 까지
	// while(queue->count == 1)이 실행되게 하려면? 
	while(!card(&queue)){
		printf("%d", Dequeue(&queue));
		Enqueue(&queue,Dequeue(&queue));
	}

	
		printf("%d", Dequeue(&queue));
	
	
	
	

	
	return 0;
}
