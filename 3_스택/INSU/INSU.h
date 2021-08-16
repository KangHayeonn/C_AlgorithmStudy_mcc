// 작성전
#ifndef ___IntStack
#define ___IntStack
#include<stdio.h>
#include<stdlib.h>
typedef struct {
	int max; //스택 용량
	int ptr; //스택 포인터 (갯수)
	int* stk; //스택을 가르키는
} IntStack;

int initialize(IntStack* s, int max);

int push(IntStack* s, int x) {
	if (s->ptr >= s->max) //용량보다 개수가 많으면
		return -1; // 실패합니다.
	s->stk[s->ptr++] = x; 
	return 0;
}
int pop(IntStack* s) {
	if (s->ptr <= 0)
		return -1;
	return s->stk[(s->ptr)--];
}
int sumstack(IntStack* s) { // 문제1 풀기 위해서 만들음.
	if (s->ptr <= 0)
		return -1;
	int i, sum = 0;
	for (i = 0; i < s->ptr; i++) {
		sum += s->stk[i]; // 스택 안에 있는걸 다 더해줌
	}
	printf("%d", sum);
	return sum;
}
int peek(IntStack* s, int* x) {
	if (s->ptr <= 0)
		return -1;
	*x = s->stk[s->ptr - 1]; // 현재 가리키고 있는걸 보여줌~~
}
void clear(IntStack* s)
{
	s->ptr = 0; //클리어
}
int capacity(IntStack* s) {
	return s->max;
}
int size(IntStack* s) {
	return s->ptr;
}
void print(const IntStack* s) {
	int i;
	for (i = 0; i < s->ptr; i++) {
		printf("%d ", s->stk[i]);
	}
	printf(" \n");
}
void terminate(IntStack* s);
#endif 
