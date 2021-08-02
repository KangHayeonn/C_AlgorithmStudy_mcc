// 자료구조 1주차
// 연결리스트 (LinkedList)

// 배열에 비해 추가/삭제가 용이, '동적 할당'을 기반으로 해 크기 미리 지정안해줘도 됨
// but, 순차 탐색을 이용해 특정 데이터를 찾으므로 속도가 느림

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* strcpy_hy(char* str1, const char* str2);


// 연결리스트의 node 구조 (data+link)
typedef struct Node { //typedef를 쓰면 struct 키워드 안 붙이고 별칭 쓸 수 있음.
	char data[10];
	struct Node* link; // 다음 노드를 가리키는 포인터
}listNode;

// 리스트의 시작 (head 노드)
typedef struct Start_Linked {
	struct Node* head; // 리스트의 시작 (Node의 주솟값: head)
}linkedlist_h;

// 공백 리스트 생성
linkedlist_h* createLL(void) {
	struct Start_Linked* L; // Node의 첫 주솟값인 head를 값으로 가지고 있는 L
	L = (linkedlist_h*)malloc(sizeof(linkedlist_h));
	L->head = '\0'; // 리스트가 없다
	return L;
}

// 맨 앞에 노드 삽입
void unshiftLL(linkedlist_h* L, char* input) {
	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy_hy(newnode -> data, input);
	newnode -> link = L -> head; // newnode가 맨 앞으로 이동
	L -> head = newnode; // newnode 의 주솟값 가리킴
}

// 중간에 노드 삽입
void spliceLL(linkedlist_h* L, listNode* input_node, char* input) {
	listNode* newnode;
	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy_hy(newnode->data, input);
	
	if (input_node == '\0') L->head = newnode; // 앞에 노드가 없을 때
	else if (L == '\0') { // 공백 리스트일때
		L->head = newnode;
		newnode->link = '\0';
	}
	else {
		newnode->link = input_node->link;
		input_node->link = newnode;
	}
}

// 마지막에 노드 삽입
void pushLL(linkedlist_h* L, char* input) {
	listNode* newnode;
	listNode* temp;

	newnode = (listNode*)malloc(sizeof(listNode));
	strcpy_hy(newnode->data, input);
	newnode->link = '\0';

	if (L == '\0') {
		L->head = newnode;
		return;
	}

	temp = L->head;

	while (temp->link != '\0') temp = temp->link;
	temp->link = newnode;
	/*
	while (L->head->link != '\0') L->head = L->head->link;
	L->head->link = newnode;
	*/
}

// 노드 탐색
listNode* searchLL(linkedlist_h* L, char* input) {
	listNode* temp;
	temp = L->head;
	int count = 0;
	while (temp != '\0') {
		if (strcmp(temp->data, input) == 0) {
			printf("탐색한 노드번호 : %d\n", count); // 인덱스처럼
			return temp;
		}
		else {
			temp = temp->link;
			count++;
		}
	}
	return temp; // 만약 탐색 못하면 NULL값 나옴.
}

// 노드 삭제
void popLL(linkedlist_h* L, listNode* input_node) {
	listNode* pre;  // pre_input_node

	if (L->head == '\0') return; // 공백 리스트
	if (L->head->link == '\0') { // 노드가 한개만 있는경우
		free(L->head);
		L->head = NULL;
		return;
	}
	else if (input_node == '\0') return;
	else {
		pre = L->head;
		while (pre->link != input_node) pre = pre->link;
		pre->link = input_node->link;
		printf("삭제된 것: %s\n", input_node->data);
		free(input_node);
	}
}
int main() {
	linkedlist_h* L;
	listNode* Node1;
	L = createLL();
	//printf(L);
	printf("%s dd\n", L->head->data);
	unshiftLL(L, "하연");
	printf("%s\n", L->head->data);
	unshiftLL(L, "메롱");
	printf("%s\n", L->head->data);
	unshiftLL(L, "오바팅");
	printf("%s\n", L->head->data);
	pushLL(L, "야야");
	printf("%s\n", L->head->link->link->link->data);


	Node1 = searchLL(L, "하연");

	if (Node1 == '\0') printf("데이터없음\n");
	else printf("%s 를 찾음\n", Node1->data);
	
	spliceLL(L, Node1, "얏호"); // Node1 뒤에 얏호 노드 삽입
	/*
	listNode* Node1;
	Node1 = "22";
	spliceLL(L, (L+1), "333");
	*/

	popLL(L, Node1);
	

	int count = 0;
	printf("\n[ 연결리스트 출력 확인 ]\n");
	while (L->head != NULL) {
		printf("%s ", L->head->data);
		L->head = L->head->link;
		count++;
	}
	printf("\n");
	printf("node의 갯수: %d", count);
}

char* strcpy_hy(char* str1, const char* str2) {
	int i = 0;
	while (str2[i] != '\0') {
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return str1;
}
