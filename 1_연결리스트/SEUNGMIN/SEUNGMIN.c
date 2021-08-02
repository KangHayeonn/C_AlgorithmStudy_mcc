// 작성전
#include<stdio.h>
#include<stdlib.h>

struct node{       //여기서 데이터 타입만 수정하면 됨
    int data;
    struct node *next;
}typedef node;

typedef struct {
    node *head;
}nodehead;

typedef struct {
    node *tail;
}nodetail;

// 현재 버전은 링크드 리스트를 하나만 생성하는 버전임.
node *listnode;
nodehead *listhead;
nodetail *listtail;

void firstnode(int data){       //첫번째 노드를 생성한다.
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next =NULL;
    listhead = (nodehead*)malloc(sizeof(nodehead));
    listtail = (nodetail*)malloc(sizeof(nodetail));
    listhead->head = temp;
    listtail->tail = temp;
}

void addnode(int data){     //맨 뒤에 노드 추가
    node *temp = (node*)malloc(sizeof(node));
    temp->data = data;
    temp->next =NULL;
    listtail->tail->next = temp;
    listtail->tail = temp;
}

int countnode(){    //노드 수 세기
    node *cursor;
    int count =0;
    for(cursor= listhead->head;cursor->next!=NULL;cursor=cursor->next){
        count++;
    }
    count++;
    return count;
}

void freelist(){    //리스트 메모리 전체 해제
    node *temp,*cursor;

    for(cursor= listhead->head;cursor->next!=NULL;){
        temp = cursor;
        cursor = cursor->next;
        free(temp);
    }
}


void insert(int N,int data){// data 삽N번째에 요소입 
    node *cursor,*temp,*temp2;
    temp = (node*)malloc(sizeof(node));
    temp->data = data; 
    int count =0;
    if (N==0){
        cursor = listhead->head;
        listhead->head = temp;
        temp->next = cursor;
    }
    else {
        for(cursor= listhead->head;cursor->next!=NULL;){
            if(count==N-1){
                temp2 = cursor->next;
                cursor->next = temp;
                temp->next = temp2;
                break;
            }
            count++;
        }
    }
}  


void delete(int N,int data){//N번째에 요소 data 삽입 
    node *cursor,*temp,*temp2;
    temp = (node*)malloc(sizeof(node));
    temp->data = data; 
    int count =0;
    if (N==0){
        cursor = listhead->head;
        listhead->head = listhead->head->next;
        free(cursor);
    }
    else {
        for(cursor= listhead->head;cursor->next!=NULL;){
            if(count==N-1){
                temp2 = cursor->next;
                cursor->next = temp;
                temp->next = temp2;
                break;
            }
            count++;
        }
    }
}  
