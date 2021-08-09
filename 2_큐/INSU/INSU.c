// 작성전
#define _CRT_SECURE_NO_WARNINGS
#include "IntQueue.h"
#include <stdio.h>
#include <stdlib.h>

int initialize(IntQueue* q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = calloc(max, sizeof(int))) == NULL) {  // 배열 생성에 실패
		q->max = 0;// 배열 생성에 실패
		return -1;
	}
	q->max = max;//매개변수 max로 받은 큐의 최대 용량을 max에 저장!
	return 0;
}
int enque(IntQueue* q, int x) {
	if (q->num >= q->max) //큐가 꽉찼어용
		return -1;
	else {
		q->num++;//인큐했으니까 num값 증가
		q->que[q->rear++] = x; //rear의 값 증가
		if (q->rear == q->max) //max와 rear가 같아지면 순환이 안되기때문에 
			q->rear = 0;//max와 rear가 같아지면 rear를 0으로 변경
		return 0;
	}
}
int deque(IntQueue* q, int* x) {
	if (q->num <= 0) // 큐가 비었어용
		return -1;
	else {
		q->num--;//디큐했으니까 num값 감소
		*x = q->que[q->front++]; //front에 저장되어 있던 값을 꺼내고 front값 증가
	}
	if (q->front == q->max) // front가 max를 초과하는 것을 방지
		q->front = 0;//0으로 변경
	return 0;
}
int peek(IntQueue* q, int* x)
{
	if (q->num <= 0) //큐가 비었어용
		return -1;
	*x = q->que[q->front]; //que[front]값
	return 0;
}
void clear(IntQueue* q)
{
	q->num = q->front = q->rear = 0; //큐를 초기화시킴
}
int cpacity(const IntQueue* q) {
	return q->max;//단순히 max값 
}
int size(const IntQueue* q) {
	return q->num;//단순히 num값 
}
void print(const IntQueue* q) {
	for (int i = 0; i < q->num; i++) {
		printf("%d ", q->que[i + q->front] % q->max); 
	}// 현재 검색하는 위치의 인덱스를 구하는 식은 (i+q->front)%q->max <<<<   ???????????????
	printf("\n");
}
void terminate (IntQueue* q) {
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0; //할당 해제하고 큐를 종료함.
}



int main() {
	IntQueue que;
	if (initialize(&que, 64) == -1) {
		printf("생성 실패 !!!");
		return 1;
	}
	while (1) {
		int m, x;
		printf("현재 데이터 수 : %d / %d \n", size(&que), cpacity(&que));
		printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료 : ");
		scanf("%d", &m);
	
		if (m == 0)
			break;
		switch (m)
		{
		case 1:
			printf("데이터 : ");
			scanf(" %d", &x);
			if (enque(&que, x) == -1)
				printf("\a오류: 인큐에 실패했습니다.\n");
			break;
		case 2:
			if (deque(&que, &x) == -1)
				printf("\a오류: 디큐에 실패했습니다.\n");
			else {
				printf("디큐 성공!!!\n");
				printf("디큐에 성공한 데이터 : %d\n", x);
			}break;
		case 3:
			if (peek(&que, &x) == -1)
				printf("\a오류: 피크에 실패했습니다.\n");
			else
				printf("피크한 데이터는 %d 입니다.\n", x);
			break;
		case 4:
			print(&que);
			break;
		}
	}
	terminate(&que);
	return 0;
}
