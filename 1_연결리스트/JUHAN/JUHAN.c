#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
1. 노드에 메모리 할당
2. next 멤버에 다음 노드의 메모리 주소 저장
3. data 멤버에 데이터 저장
4. 마지막 노드라면 next 멤버에 NULL 저장
*/
typedef struct Node {	//연결리스트의 노드 구조체
	int data;		//데이터를 저장하는 멤버
	struct Node* next;		//다음 노드의 주소를 저장하는 포인터
}node;

int main() {
	int i = 1;

	node* head = malloc(sizeof(node));	//헤드노드 생성, 데이터 저장하지않음

	node* node1 = malloc(sizeof(node));
	head->next = node1;
	node1->data = 100;

	node* node2 = malloc(sizeof(node));
	node1->next = node2;
	node2->data = 200;

	node* node3 = malloc(sizeof(node));
	node2->next = node3;
	node3->data = 300;

	node3->next = NULL;		//node3은 마지막 노드이므로 다음 노드 없음

	node* curr = head->next;	//연결리스트 순회용 포인터. 첫번째 노드의 주소 저장

	while (curr != NULL) {		//마지막 노드에서 NULL을 만나고 종료		
		printf("%d번째 노드의 data: %d\n", i, curr->data);
		curr = curr->next;		
		i++;
	}

	free(node2);
	free(node1);
	free(head);
}
