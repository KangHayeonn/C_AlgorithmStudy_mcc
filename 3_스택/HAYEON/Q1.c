// 제로 (백준 삼성역량 10773번)

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Stack {
	Data data;
	struct Stack* link;
}typedef Stack;

typedef struct {
	Stack* top;
} Top;


Top* createStack(void) {
	Top* start_stack; // 이 부분이 이중포인터를 의미
	start_stack = (Top*)malloc(sizeof(Top));
	start_stack->top = '\0';
	return start_stack;
}

void push(Top* stack, Data data) {

	Stack* newstack;
	newstack = (Stack*)malloc(sizeof(Stack));
	newstack->data = data;
	newstack->link = stack->top; // stack으로 하면 오류뜸
	stack->top = newstack;
}

void pop(Top* stack) {
	Stack* temp = (Stack*)malloc(sizeof(Stack));
	temp = stack->top;
	Data item;
	if (isEmpty_Stack(stack)) {
		printf("빈 Stack 입니다.");
		return;
	}
	else {
		item = temp->data; 
		stack->top = temp->link;
		free(temp);
	}
}

int isEmpty_Stack(Top* stack) {
	if (stack == '\0') return 1;
	return 0;
}

long sumStack(Top* stack) {
	Stack* p;
	long sum = 0;
	p = stack->top;
	//printf("스택의 합\n");
	//printf("[ ");
	while (p != '\0') {
		sum += p->data;
		//printf("%ld ", sum);
		p = p->link;
	}
	//printf("]\n");

	return sum;
}

int main() {
	Top* stack;
	int K, N;
	stack = createStack();

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {
		scanf("%d", &N);
		if (N == 0) pop(stack);
		else push(stack, N);
	}

	printf("%ld", sumStack(stack));

	return 0;
}
