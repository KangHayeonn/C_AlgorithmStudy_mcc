#include <stdio.h>
#include <stdlib.h>

// 나 혼자짜본 큐,,,, 엉망  
/* typedef struct Node {
	int data;
	struct Node *next;
}Node;

typedef struct Queue{
    struct Node *front;
	struct Node *back; 
	int count=0; 	
}Queue;

	Queue *queue ; //queue구조체 선언했을 때 오류발생  
	Node *newnode = NULL;
	Node *prev = NULL;
	
	

void enqueue(int data){//데이터 삽입 
newnode->data = data;
    if(queue->front==queue->back){
    	
    	queue->front = queue->back = newnode;
    	prev = queue->back;
    	queue->count++;
	}
	else{
		queue->back = newnode;
		prev->next = newnode;
		prev= queue->back;
		queue->count++;
	}

	
}
 

int dequeue(Queue *queue){//데이터 꺼내기
int k=0;
int size[100]; //큐에서 빠져나간 data저장하는 배열  
    size[k] = queue->front->data; // 빠져나간 데이터 저장 
	queue->front = queue->front->next; 
	k++;
	queue->count--;
	return size[k-1]; 
	
	// if(queue->front==queue->back){
	//	return queue->front->data;
	//}
	 
} 

int main(void) {
	 
	 newnode = (Node*)malloc(sizeof(Node));//노드 생성
	//queue->back = (Node*)malloc(sizeof(Node));//노드 생성

	 //queue->front = (Node*)malloc(sizeof(Node));//노드 생성

	queue = (Queue*)malloc(sizeof(Queue));

	queue->front = NULL;
	queue->back = NULL;
	queue->count = 0;
		
} */


// 구글링 해서 구형한 큐  
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
	int i;
	Queue queue;
	
	initQueue(&queue);
	for(i =1; i<5; i++){
		Enqueue(&queue,i);
	}
	while(!isEmpty(&queue)){
		printf("%d", Dequeue(&queue)); //1234
	}
	printf("\n");
	
	Enqueue(&queue,3); // 3
	Enqueue(&queue,4); // 3 4
	Enqueue(&queue,5); // 3 4 5
	Enqueue(&queue,6); // 3 4 5 6
	Enqueue(&queue,7); // 3 4 5 6 7
	printf("%d\n", Dequeue(&queue)); //3출력, 4567 
 
	Enqueue(&queue,1); // 4 5 6 7 1
	printf("%d\n", Dequeue(&queue)); //4출력, 5 6 7 1 
	
	while(!isEmpty(&queue)){
		printf("%d", Dequeue(&queue)); // 5 6 7 1 출력  
	}
	printf("\n");
	
	return 0;
}




