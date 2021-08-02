#include "linkedlist.h"

int main(){
    node *cursor;
    int N,temp;
    int min,max;

    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&temp);
        if (i==0){  //첫 노드는 퍼스트노드로 헤드에 추가
            firstnode(temp);
        }
        else {      //이후 addnode함수로 추가
            addnode(temp);
        }
    }
    min = listhead->head->data;
    max = listhead->head->data;
    for(cursor= listhead->head;cursor->next!=NULL;cursor=cursor->next){
        if (min>cursor->data){
            min = cursor->data;
        }
        if (max<cursor->data){
            max = cursor->data;
        }   
    }
    if (min>cursor->data){
        min = cursor->data;
    }
    if (max<cursor->data){
        max = cursor->data;
    }
    freelist();
    printf("%d %d",min,max);
    
}
