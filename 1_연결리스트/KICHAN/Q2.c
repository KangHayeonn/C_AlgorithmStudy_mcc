#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 연결리스트


typedef struct NODE {
	double num;
	struct NODE *next; //다음 노드를 가리키는 포인터 
}NODE; 

NODE *start = NULL; // 시작노드를 가리키는 포인터 
NODE *prev; //이전 노드를 가리키는 포인터  

int main(void) {
	NODE *cur = NULL; // 현재주소를 가리키는 포인터
	NODE *newnode = NULL; //새로 생성된 노드를 가리키는 포인터
	NODE *late;
	int end, k, i;
	double sum = 0;
	double avg = 0;
	double max = -1000000; //최댓값  
	
	scanf("%d", &k);
	for(i=0; i<k; i++){
		newnode = (NODE*)malloc(sizeof(NODE));//노드 생성
		scanf("%lf", &newnode->num );
		
		if(start==NULL) { // 노드가 없는경우  
		
		newnode->next = NULL;
		start = newnode; //시작점으로 설정
		prev = start;  
	} 
	else{
		prev->next = newnode;
		newnode->next = NULL;
		prev = newnode;
		
	}	
}

newnode = start;
while(newnode != NULL){
	
	if(newnode->num>max){
		max = newnode->num;
	}
	newnode = newnode->next;
	
}
printf("최댓값: %lf\n",  max);

newnode = start;
while(newnode != NULL){
	newnode->num = newnode->num/max*100;
	sum += newnode->num;
	newnode = newnode->next;
}
avg = sum/k;
printf("%lf", avg);




newnode = start;


while(newnode != NULL){ //동적할당 해제  
	late = newnode->next;
	free(newnode);
	newnode = late;
	
}


	return 0;
}
