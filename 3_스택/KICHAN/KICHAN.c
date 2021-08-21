#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

typedef struct Stack
{
	Node *top;
	int count;
}Stack;

void initStack(Stack *stack);
int isEmpty(Stack *stack);
void Push(Stack *stack,int data);
int Pop(Stack *stack);

void initStack(Stack *stack)
{
	stack->top = NULL;
	stack->count = 0;
}

int isEmpty(Stack *stack)
{
	return stack->count==0;	
}

void Push(Stack *stack,int data)
{
	Node *now = (Node*)malloc(sizeof(Node));
	now->data = data;
	now->next = stack->top;
	stack->top = now;
	stack->count++;
	
}

int Pop(Stack *stack)
{
	int re;
	if(isEmpty(stack))
	{
		return 0;
	}	
	
	Node *now = stack->top;
	re = now->data;
	stack->top = now->next;
	free(now);
	stack->count--;
	return re;
}

int main() {
	int i, N, k;
	Stack stack;
	initStack(&stack);
	
	
	for(i=0; i<5; i++){
		Push(&stack,i+1);
	}
	while(!isEmpty(&stack))
	{
		printf("%d", Pop(&stack));
	}
	printf("\n");
	
	Push(&stack, 3);
	Push(&stack, 7);
	printf("%d",Pop(&stack));
}


// 작성전
