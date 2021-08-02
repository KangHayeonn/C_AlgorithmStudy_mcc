#include "linkedlist.h"

int main(){
    node *cursor;
    int N,temp;
    double sum=0;
    double max;
    double n=0;

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
    insert(3,10);
    max = listhead->head->data;
    for (cursor=listhead->head;cursor->next!=NULL;cursor =cursor->next){
        sum += cursor->data;
        n++;
        if (max<cursor->data)
            max = cursor->data;
    }
    if (max<cursor->data)
            max = cursor->data;
    sum += cursor->data;
    sum = sum*100/max;
    n++;
    printf("%f",sum/n);
    
}
