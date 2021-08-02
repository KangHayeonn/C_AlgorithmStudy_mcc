#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct NODE {  //노드 정의
	struct NODE* next; //다음 노드의 주소 저장
	int data; //데이터를 저장할 멤버
};

void ADDNODE(struct NODE* target, int data) //기준 노드(0번 노드) 뒤에 노드를 추가하는 함수
{
	if (target == NULL)
		return;

	struct NODE* newnode = malloc(sizeof(struct NODE)); //새 노드 생성
	if (newnode == NULL)
		return;

	newnode->next = target->next; //새 노드의 다음 노드에 기존 1번 노드를 지정 -> 즉 1번 노드부터 한칸씩 뒤로 밀립니다.
	newnode->data = data; //새 노드에 데이터를 저장합니다.

	target->next = newnode; //0번노드의 다음 노드(1번노드 자리)에 새 노드를 지정합니다.
}

void REMOVENODE(struct NODE* target) //0번 노드의 다음 노드 (1번 노드 자리)를 삭제하는 함수
{
	if (target == NULL)
		return;

	struct NODE* removenode = target->next; //1번 노드의 주소를 저장
	if (removenode == NULL)
		return;

	target->next = removenode->next; // 2번노드를 0번 노드와 연결
	free(removenode); //노드 메모리 해제
}

void print_list(struct NODE* target) {
	struct NODE* curr = target->next; //연결리스트 순회용 포인터에 0번째 노드의 주소 저장
	while (curr != NULL) { // 포인터가 NULL이 나올때 까지 반복
		printf("%d\n", curr->data);
		curr = curr->next; //
	}
}
