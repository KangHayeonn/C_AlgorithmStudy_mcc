#include<stdio.h>
#include<stdlib.h>

struct queue{       //여기서 데이터 타입만 수정하면 됨
    int x;
    int time;
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
rear *enqueuefirst(front *Q,int X, int Time){   //이 시점에 rear 가 생성되고 rear 를 반납함 
    rear *R;
    Q ->front = (queue *)malloc(sizeof(queue));
    Q->front->x = X;
    Q->front->time = Time;
    R = (rear *)malloc(sizeof(rear));
    R->rear  = Q->front;    //첫 큐는 프론트와 레어가 같은 공간을 가르킴
    return R;
}

void enqueue(rear *R, int X, int Time){     // rear와 X(좌표) 와  Time(시간)을 받아 새로운 노드를 생성하고 레어 뒤를 이어줌
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->x = X;
    temp->time = Time;
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
        temp->x = F->front->x;
        temp->time = F->front->time;
        temp->next = NULL;
        free(F->front);
    } 
    return temp;
}

int main(){
    
    front * Q = createqueue();
    rear *R;
    queue *temp;
    int t;

    scanf("%d",&t);
    

    for(int i=1;i<=t;i++){
        if (i==1){
            R =enqueuefirst(Q,i,0);
        }
        else {
            enqueue(R,i,0);
        }
    }


    for(int j=0;j<t;j++){
        if(j%2==0){
            temp = dequeue(Q);
            printf("%d ",temp->x);
            free(temp);
        }
        else{
            temp = dequeue(Q);
            enqueue(R,temp->x,0);
            free(temp);
            t++;
        }
    }
    
    free(R);
    free(Q);


}
