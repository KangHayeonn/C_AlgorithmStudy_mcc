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

int main(){

    int M,t,N;  //
    int time;   //사람이 도착하는 시간
    char LOR[6];
    int Lcount=0 ,Rcount=0;
    int timer=0;   //보트는 좌측 0초부터
    int count=0;

    
    front *QL = createqueue();
    front *QR = createqueue();
    rear *RL, *RR;
    
    queue *temp;

    scanf("%d %d %d",&M,&t,&N);
    int *timearr = (int*)malloc(sizeof(int)*N);
    int *indexarr = (int*)malloc(sizeof(int)*M);

    for (int i=0;i<N;i++){
        scanf("%d %s",&time,&LOR);
        if (LOR[0]=='l'){
            if (Lcount ==0){
                RL = enqueuefirst(QL,time,count);
                Lcount++;
                count++;
            }
            else{
                enqueue(RL,time,count);
                count++;
            }
        }
        else {
            if (Rcount ==0){
                RR = enqueuefirst(QR,time,count);
                Rcount++;
                count++;
            }
            else{
                enqueue(RR,time,count);
                count++;
            }
        }
    }
    
    int d, brkcode;
    while (preview(QR)!=-1||preview(QL)!=-1)
    {
        LEFT:
        d=0;
        brkcode=0;
        if(preview(QR)==-1&&preview(QL)==-1){
            break;
        }
        for (int i=0;i<M;i++){      //보트 수용인원까지 돌리는데
            if(QL->front!=NULL){        //왼쪽에 올 손님이 있다면
                if (preview(QL)<=timer){        //현재 시간에 존재하는지를 확인해서
                    temp = dequeue(QL);     //손님을 태운다
                    indexarr[d] = temp->counter;
                    d++;
                }
            }else{      //올 순님 자체가 없다면 , 브래이크 코드를 증가
                brkcode++;
            }
        }
        if (d==0){      //아무도 안 태웠다면 한 사람이라도 태울 손님을 기다리고 출발한다. (태울 손님이 있을경우 ) 
                int temp1=0,temp2=0;
                if (preview(QR)!=-1){       //좌측에 올 손님이 존재하면
                    temp1 = preview(QR);
                }
                if (preview(QL)!=-1){       //우측에 올 손님이 존재하면
                    temp2 = preview(QL);
                }
                if (temp1==0&&temp2==0){        //두곳 다 올 손님이 없다면 탈출
                    break;
                }
                else if(temp1>temp2){//현재 내가 있는곳이 배가 빠르게 올 경우
                    if(timer<temp2){        //배가 기다린다
                        timer=temp2;
                    }       //아니면 바로 태운다.
                    goto LEFT;
                }       
                else{       //상대 구역이라면?
                    if(timer+t<temp1){ //배가 이동하고 기다린다
                        timer=temp1;
                    }else{      //배가이동한다
                        timer += t;    
                    }
                    goto RIGHT;
                }
        }
        timer +=t;      //누구라도 태웠다면 배가 이동한다
        for(int i=0;i<d;i++){       //손님이 도착한 시간을 기록한다
            timearr[indexarr[i]] =timer;
        }
       
        RIGHT:
        d=0;
        brkcode=0;
        for (int i=0;i<M;i++){      //보트 수용인원까지
            if(QR->front!=NULL){        //우측에 올 사람이 있다면
                if (preview(QR)<=timer){        //현재 태울 수 있다면
                    temp = dequeue(QR);
                    indexarr[d] = temp->counter;
                    d++;
                }
            }else{
                brkcode++;
            }
        }
        if (d==0){      //아무도 안 태웠다면 한 사람이라도 태울 손님을 기다리고 출발한다. (태울 손님이 있을경우 ) 
                int temp1=0,temp2=0;
                if (preview(QR)!=-1){
                    temp1 = preview(QR);        //d오른쪽 손님
                }
                if (preview(QL)!=-1){
                    temp2 = preview(QL);        //왼쪽 손님
                }
                if (temp1==0&&temp2==0){        //둘 다 뺄게 없을때
                    break;
                }
                else if(temp1>temp2){//현재 반대편이 배가 빠르게 올 경우
                    if(timer+t<temp2){ //배가 이동하고 기다린다
                        timer=temp2;
                    }else{      //배가이동한다
                        timer += t;    
                    }
                    goto LEFT;
                }       
                else{       //우리구역에 빠르게 올 경우
                    if(timer<temp1){        //배가 기다린다
                        timer=temp1;
                    }       //아니면 바로 태운다.
                    goto RIGHT;
                }
        }
        timer +=t;      //한 사람이라도 손님을 태웠다면  배가 이동한다.
        for(int i=0;i<d;i++){       //손님을 기록한다.
            timearr[indexarr[i]] =timer;
        }
    }
    for (int i=0;i<N;i++){
        printf("%d\n",timearr[i]);
    }
}
