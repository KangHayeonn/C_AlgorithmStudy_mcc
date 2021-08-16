// 괄호 (백준 삼성역량 9012번)

#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>


typedef int Data;

struct Stack {
	Data data;
	struct Stack* link;
}typedef Stack;

typedef struct {
	Stack* top;
} Top;

int test(char* str);
int isEmpty_Stack(Top* stack);

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

Data pop(Top* stack) {
	//Stack* temp;
	//temp = stack->top;
	Data item;
	if (isEmpty_Stack(stack)) {
		printf("빈 Stack 입니다.");
		return 0;
	}
	else {
		item = stack->top->data;
		stack->top = stack->top->link; //실제로 꺼내는거

		/*if (stack->top->link == '\0') stack->top = '\0';*/
		//free(temp);*/
		return item;
	}
}

int isEmpty_Stack(Top* stack) {
	if (stack->top == '\0') return 1;
	return 0;
}

int main() {
	int length=0;
	scanf("%d", &length);

	char* str = (char*)malloc(sizeof(char) * (50+1));

	for (int i = 0; i < length; i++) {
		scanf("%s", str);
		
		if (test(str)) printf("YES\n");
		else printf("NO\n");
	}
	//printf("%s", str);
	free(str);
	return 0;
}

int test(char* str) {
	Top* stack;
	stack = createStack();
	int size = strlen(str);
	bool result = true;
	
	for (int j = 0; j < size; j++) {
	  
		if (str[j] == '(') push(stack, 1);
		else {
			if (stack->top == '\0') {
				result = false;
				break;
			}
			else {
				pop(stack);
			}
		}
	}
	if (isEmpty_Stack(stack)!=1) result = false;

	while (stack->top != '\0') pop(stack);

	return result;
}
