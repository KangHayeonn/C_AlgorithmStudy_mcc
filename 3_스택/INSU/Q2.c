// 작성전
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int max;
	int ptr;
	int* stk;
} IntStack;

int initialize(IntStack* s, int max) {
	s->ptr = 0;
	s->stk = calloc(max, sizeof(int));
	if (s->stk == 0)
		return -1; // 배열 생성 실패
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
	s->stk[(s->ptr)--];
	return 0;
}

void terminate(IntStack* s) {
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr = 0;
}

int main() {
	IntStack s;
	char str[51];
	int i, j, n = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		initialize(&s, 51);
		scanf("%s", str);
		for (j = 0; j < strlen(str); j++) {
			if (str[j] == '(') {
				push(&s, 1);
			} 
			else if (str[j] == ')') {
				if (pop(&s) == 0);
				else
					break;
			}
		}
		if (j != strlen(str) || s.ptr != 0) //// 배열을 끝까지 안 돈 경우 = 중간에 break or 상쇄가 되지 않은 경우
			printf("NO\n");
		else
			printf("YES\n");
	}
	terminate(&s);
	return 0;
}
