// 자료구조 3주차
// Stack

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data; 

struct Stack{
	Data data;
	struct Stack* link;
}typedef Stack;

typedef struct{ 
	Stack* top;
} Top;

typedef struct {
	Stack* bottom;
} Bottom;

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

	// ver1
	// 기존 stack->link에 newstack을 붙이는 느낌
	/*
	Stack* temp;
	newstack->link = '\0';

	if (isEmpty_Stack(stack)) {
		stack->top = newstack;
		return;
	}

	temp = stack->top;

	while (temp->link != '\0') temp = temp->link;

	temp->link = newstack;
	return;
	*/
	

	// ver2
	// 새로들어온 newstack의 link에다 기존 stack을 붙이는 느낌    
	
	newstack->link = stack->top; // stack으로 하면 오류뜸
	stack->top = newstack;                
	return;
}

Data pop(Top* stack) {
	// Stack* temp = (Stack*)malloc(sizeof(Stack)); // 공간을 temp 주소에 할당해주고 사용하지 않고 다른 곳을 가리키게함
	// temp = stack->top;  // 그래서 이부분은 없어도됨
	Data item;
	if (isEmpty_Stack(stack)) {
		printf("빈 Stack 입니다.");
		return 0;
	}
	else {
		//item = temp->data; 
		//stack->top = temp->link;
		//free(temp);
		item = stack->top->data;
		stack->top = stack->top->link; // 이부분은 실제로 뒤로 밀려지는 부분이라 이렇게 작성해도 무방
		return item;
	}
}

int isEmpty_Stack(Top* stack) {
	if (stack->top == '\0') return 1;  // stack자체가 null 인지 볼게 아니라 stack->top이 null인지 판단해줘야함
	return 0;
}

Data peekStack(Top* stack) {
	
	if (isEmpty_Stack(stack)) {
		printf("빈 Stack 입니다.");
		return 0;
	}
	else { 
		Data data = stack->top->data; 
		return data;
		//return -1;
	}
}

void printStack(Top* stack) {
	Stack* p;
	p = stack->top;
	printf("스택 출력\n");
	printf("[ ");
	while (p != '\0') {
		printf("%d ", p->data);
		p = p->link;   
	}
	printf("]\n");
}


int main() {
	Top* stack;

	stack = createStack();
	//InitStack(stack);

	printStack(stack);

	
	push(stack, 2);  
	printStack(stack);

	push(stack, 13);  
	printStack(stack);
	
	push(stack, 200);
	printStack(stack);
	
	printf("////////////////////\n");
	peekStack(stack);
	int a = peekStack(stack);
	printf("%d\n", a);
	pop(stack);
	printStack(stack);
	printf("");

	return 0;
}
