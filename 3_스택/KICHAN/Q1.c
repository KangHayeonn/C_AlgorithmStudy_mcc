// 작성전#include <stdio.h>
#include <stdlib.h>

// 1 <- 2 <- 3(stack->top)      <-4(now)
// now->next == stack->top

// 런타임 에러 발생!!
 
typedef struct Node{ //노드 구조체 선언  
	int data;
	struct Node *next;
}Node;

typedef struct Stack{ // stack 구조체 선언  
	
	Node *top;
	int count;
}Stack;

void initStack(Stack *stack);
int isEmpty(Stack *stack);
void Push(Stack *stack,int data);
int pop(Stack *stack);

void initStack(Stack *stack){
	stack->top = NULL;
	stack->count = 0;
}

int isEmpty(Stack *stack){
	// 스택이 비었으면 stack->count ==0;
	return stack->count ==0; 
}

void Push(Stack *stack,int data){
	Node *now = (Node*)malloc(sizeof(Node));
	now->data = data;
	now->next = stack->top; // 처음일 경우 stack->top이 NULL이므로 NULL값 갖음  
    
	stack->top = now; //처음일때는 if문 무시  
	stack->count++;
}

int Pop(Stack *stack){
	int re = 0;
	Node *now;
	if(isEmpty(stack)){
		return re;
	}
	now = stack->top;
	re = stack->top->data;
	stack->top = now->next;
	free(now);
	stack->count--;
	return re;
	
} 

int main(){
	
	int i, N, k;
	int sum = 0;
	Stack stack;
	initStack(&stack);
	
	
	scanf("%d", &N); 
	for(i =1; i<=N; i++){  
		scanf("%d", &k); // N개의 정수 입력  
		if(k!=0){ //입력된 정수가 0이 아닐 때 push 
			Push(&stack,k);
		}
		else{ // 입력된 정수가 0이면 pop 
			Pop(&stack);
		}
		
	}
	while(!isEmpty(&stack)){ // 스택이 빌 때 까지 pop 
		sum += Pop(&stack); // pop한 정수들의 합을 구함  
	}
	printf("%d",sum);
	
}

