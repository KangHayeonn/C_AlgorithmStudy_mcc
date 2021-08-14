#include<stdio.h>
#include<stdlib.h>

struct queue{       //여기서 데이터 타입만 수정하면 됨
    int time;
    int counter;
    struct queue *next;
}typedef queue;

typedef struct {
    queue *front;
}front;

typedef struct {
    queue *rear;
}rear;

front *createqueue(){
    front *Q;
    Q = (front *)malloc(sizeof(front));
    Q->front = NULL;
    return Q;
}
rear *enqueuefirst(front *Q, int Time , int Counter){   //이 시점에 rear 가 생성되고 rear 를 반납함 
    rear *R;
    Q ->front = (queue *)malloc(sizeof(queue));
    Q->front->time = Time;
    Q->front->counter = Counter;
    R = (rear *)malloc(sizeof(rear));
    R->rear  = Q->front;    //첫 큐는 프론트와 레어가 같은 공간을 가르킴
    return R;
}

void enqueue(rear *R, int Time , int Counter){     // rear와 X(좌표) 와  Time(시간)을 받아 새로운 노드를 생성하고 레어 뒤를 이어줌
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->time = Time;
    temp->counter = Counter;
    temp->next = NULL;
    R->rear->next =temp;
    R ->rear = temp;
}
    
queue *dequeue(front *F){   //temp 에 front 를 가르키게 한 후 front 를 한칸 미룬다 . 그리고 방금 temp를 반납한다  -> 메인함수에서받은 템프를 free해주어야함
    queue *temp = F->front;
    if (F->front->next!=NULL)
        F->front = F->front->next;
    else{
        temp = (queue *)malloc(sizeof(queue));
        temp->time = F->front->time;
        temp->counter = F->front->counter;
        temp->next = NULL;
        free(F->front);
        F->front=NULL;
    } 
    return temp;
}
int preview(front *F){
    if(F->front!=NULL){
        return F->front->time;
    }
    else{
        return -1;
    }
}
