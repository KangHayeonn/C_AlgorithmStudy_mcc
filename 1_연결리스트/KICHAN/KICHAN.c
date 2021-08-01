// 작성전 작성중
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 연결리스트
// 책 제목 연도 입력하면 내용 저장
#define size 50

typedef struct NODE {
	char name[size];
	int year;
	struct NODE *next; //다음 노드를 가리키는 포인터 
}NODE; 

NODE *start = NULL; // 시작노드를 가리키는 포인터 
NODE *prev; //이전 노드를 가리키는 포인터  

int main(void) {
	NODE *cur = NULL; // 현재주소를 가리키는 포인터
	NODE *newnode = NULL; //새로 생성된 노드를 가리키는 포인터
	NODE *late;
	int end;
	while(1){
	
	printf("이름을 입력하시오!:");
	 newnode = (NODE*)malloc(sizeof(NODE));//노드 생성
		scanf("%s", &newnode->name );
		
		/*if(newnode->name == NULL){
			break;
		}*/
		
		printf("나이를 입력하시오!");
		scanf("%d", &newnode->year); 
		
		
		
		
		
		
		
	
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
	printf("종료하려면 0 을 입력하시오:");
		scanf("%d",&end);
		if(end== 0){
			break;
		}  
	
	
}

newnode = start;
while(newnode != NULL){
	printf("%s %d\n", newnode->name, newnode->year );
	newnode = newnode->next;
	
}
newnode = start;
while(newnode != NULL){
	late = newnode->next;
	free(newnode);
	newnode = late;
	
}


	return 0;
}
