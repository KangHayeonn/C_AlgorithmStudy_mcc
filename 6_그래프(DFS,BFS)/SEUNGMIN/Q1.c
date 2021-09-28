#include<stdio.h>
#include<stdlib.h>

int **Map;
int *Visit;


struct queue{       //여기서 데이터 타입만 수정하면 됨
    int data;
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
rear *enqueuefirst(front *Q, int data){   //이 시점에 rear 가 생성되고 rear 를 반납함 
    rear *R;
    Q ->front = (queue *)malloc(sizeof(queue));
    Q->front->data = data;
    R = (rear *)malloc(sizeof(rear));
    R->rear  = Q->front;    //첫 큐는 프론트와 레어가 같은 공간을 가르킴
    return R;
}

void enqueue(rear *R, int data){     // rear와 X(좌표) 와  Time(시간)을 받아 새로운 노드를 생성하고 레어 뒤를 이어줌
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->data = data;
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
        temp->data = F->front->data;
        temp->next = NULL;
        free(F->front);
        F->front=NULL;
    } 
    return temp;
}
int preview(front *F){
    if(F->front!=NULL){
        return F->front->data;
    }
    else{
        return -1;
    }
}



void DFS(int V , int N){
    if (Visit[V]==1){
        return ;
    }
    printf("%d ",V+1);
    Visit[V] = 1;
    for(int i=0;i<N;i++){
        if (Map[V][i]==1){      //연결된 노드가 있다면            
            DFS(i,N);
        }
    }
}

void BFS(int V , int N , front *F , rear *R){
    if(F->front==NULL){ //처음거라면
        if(Visit[V]!=1){
            R = enqueuefirst(F,V);
            printf("%d ",V+1);
        }
    }
    Visit[V] = 1;
    


    for(int i=0;i<N;i++){
        if (Map[V][i]==1){      //연결된 노드가 있다면            
            if(Visit[i]==0){    //방문한적도 없어
                enqueue(R,i);
                printf("%d ",i+1);
                Visit[i]=1;
            }
        }
    }

    while (F->front!=NULL)
    {
        queue *temp = dequeue(F);
        if(temp->data!=V){
            BFS(temp->data,N,F,R);
        }
    }
    
}


int main () {
    int i ;
    int N,M,V , a, b;
    scanf("%d %d %d",&N,&M,&V);

    Map = (int**)malloc(sizeof(int*)*N);
    for(i=0;i<N;i++){
        Map[i] = (int*)calloc(N,sizeof(int));
    }
    Visit = (int*)calloc(N,sizeof(int));

    for ( i = 0 ; i < M ; i ++){
        scanf("%d %d",&a,&b);
        Map[a-1][b-1] = 1;
        Map[b-1][a-1] = 1;
    }

    DFS(V-1,N);
    for ( i = 0 ; i < N ; i ++){
        Visit[i]=0;
    }
    printf("\n");
    front *F = createqueue();
    rear *R;
    BFS(V-1,N,F,R);
}
