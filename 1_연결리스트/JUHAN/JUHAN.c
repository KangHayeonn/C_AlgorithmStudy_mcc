#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct listNode {	

	int Data;
	struct listNode* Next;
	struct listNode* Prev;
}Node;

//노드 생성
Node* createNode(int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));

	//variables initialization
	newNode->Data = data;
	newNode->Next = NULL;
	newNode->Prev = NULL;

	return newNode;
}

//노드 삭제(메모리에서)
void deleteNode(Node* Node) {

	free(Node);
}

//입력한 INDEX의 노드 가져오기
Node* getNodeAt(Node* head, int index) {

	Node* horse = head;	//헤드에서부터 horse가 달리도록
	int cnt = 0;

	while (horse != NULL) {

		if (cnt++ == index) {
			return horse;
		}

		horse = horse->Next;	//달린다
	}
	return NULL;	//못 찾았을 때
}

int countNode(Node* head) {

	int cnt = 0;
	Node* horse = head;

	while (horse != NULL) {

		horse = horse->Next;
		cnt++;		
	}

	return cnt;
}

void addNode(Node** Head, Node* newNode) {

}








   

int main() {
	
}
