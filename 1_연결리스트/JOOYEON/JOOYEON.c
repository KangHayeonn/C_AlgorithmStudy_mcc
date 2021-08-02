#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE{ //연결리스트의 노드 구조체 

	struct NODE* next;
	int data;
	char m[100];

};


// 머리 -> 노드 1 -> 노드 2

int main() {


	struct NODE* head = malloc(sizeof(struct NODE)); //머리 노드 생성


	struct NODE* middle = malloc(sizeof(struct NODE)); //middle 노드 생성

	head->next = middle;
	// head 노드 다음에 middle 노드 연결
	//head->next에 middle 메모리 주소 저장

	middle->data = 1; //middle 노드에 1 저장

	strcpy(middle->m,"HI");

	struct NODE* middle2 = malloc(sizeof(struct NODE)); //middle2 생성

	middle->next = middle2;
	// middle 다음에 middle2 연결
	//middle->next에 middle2 메모리 주소 저장

	middle2->data = 2; //middle2에 2 저장

	strcpy(middle2->m, "HELLO WORLD");

	middle2->next = NULL; // middle2 노드 다음은 노드가 존재하지 않는다

	//순회용 노드

	struct NODE* curr = head->next; //첫 번째 노드의 주소를 curr에 저장 


	while (curr!= NULL) { //포인터가 NULL이 아닐 때 반복

		printf("%d\n", curr->data);
		printf("%s\n", curr->m);
		curr = curr->next;
	}

        free(middle2);
	free(middle);
	free(head);

	return 0;
}
