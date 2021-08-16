// 작성전
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int max;
	int ptr;
	int* stk;
}IntStack;
int initialize(IntStack* s, int max) {
	s->ptr = 0;
	s->stk = calloc(max, sizeof(int));
	if (s->stk == 0)
		return -1;
	s->max = max;
}
int push(IntStack* s, int x) {
	if (s->ptr >= s->max)
		return -1;
	s->stk[s->ptr] = x;
	s->ptr++;
	return 0;
}
int pop(IntStack* s) {
	if (s->ptr <= 0)
		return -1;
	return s->stk[(s->ptr)--];
}
int sumstack(IntStack* s) {
	int i, sum = 0;
	for (i = 0; i < s->ptr; i++) {
		sum += s->stk[i];
	}
	printf("%d", sum);
	return sum;
}
void terminate(IntStack* s) {
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}

int main() {
	int n, m, i, sum = 0;
	IntStack s;
	initialize(&s, 100001);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &m);
		if (m == 0) {
			pop(&s);
		}
		else
			push(&s, m);
	}
	sumstack(&s);
	return 0;
}
