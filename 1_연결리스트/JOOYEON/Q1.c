#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE { //연결리스트의 노드 구조체 

	struct NODE* next;
	int data;
	

};


// 머리 -> 노드 1 -> 노드 2

int main() {
	/*
	int n;
	char tmp;

	scanf("%d", &n); //정수의 개수 N을 입력받는다.

	char* s = (char*)malloc((sizeof(char) * n) +1);

	

	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	//버블 소트 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-i; j++) {
			if (s[j] > s[j+1]) {
				tmp =  s[j];
				s[j] = s[j+1];
				s[j+1] = tmp;
			}
		}
	}

	for (int i = 1; i < n+1; i++) {
		printf("%d ", s[i]);
	}

	printf("\n");
	
	printf("%d %d", s[1], s[n]);

	*/


	/*
	1. 노드를 N개만큼 생성한다. (머리 노드 제외)

    2. 버블소트 정렬을 이용하여 정렬한 뒤, data를 노드에 순서대로 저장한다. 

    3. 첫 노드랑 마지막 노드의 데이터를 출력해주면 최솟값과 최댓값을 출력할 수 있다. 

 
 */
	int n;
	char tmp;
	int r = 0;
	scanf("%d", &n);

	char* s = (char*)malloc((sizeof(char) * n) + 1);



	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}

	//버블 소트 시작
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (s[j] > s[j + 1]) {
				tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}


	struct NODE* head = malloc(sizeof(struct NODE));
	
	struct NODE* node1 = malloc(sizeof(struct NODE));

	head->next = node1;

	node1->data = s[1];

	struct NODE* node2 = malloc(sizeof(struct NODE));

    node1->next = node2;

	node2->data = s[2];


	struct NODE* node3 = malloc(sizeof(struct NODE));

	node2->next = node3;

	node3->data = s[3];


	struct NODE* node4 = malloc(sizeof(struct NODE));

	node3->next = node4;

	node4->data = s[4];

	struct NODE* node5 = malloc(sizeof(struct NODE));

	node4->next = node5;

	node5->data = s[5];

	node5->next = NULL;

	//struct NODE* curr = head->next; 

	/*
	while (r < N) {


	

		curr = curr->next;


		N--;
	}
	*/

	printf("%d %d", node1->data, node5->data);

	

	/*



	struct NODE* head = malloc(sizeof(struct NODE)); //머리 노드 생성


	struct NODE* middle = malloc(sizeof(struct NODE)); //middle 노드 생성

	head->next = middle;
	// head 노드 다음에 middle 노드 연결
	//head->next에 middle 메모리 주소 저장

	middle->data = 1; //middle 노드에 1 저장

	strcpy(middle->m, "HI");

	struct NODE* middle2 = malloc(sizeof(struct NODE)); //middle2 생성

	middle->next = middle2;
	// middle 다음에 middle2 연결
	//middle->next에 middle2 메모리 주소 저장

	middle2->data = 2; //middle2에 2 저장

	strcpy(middle2->m, "HELLO WORLD");

	middle2->next = NULL; // middle2 노드 다음은 노드가 존재하지 않는다

	//순회용 노드

	struct NODE* curr = head->next; //첫 번째 노드의 주소를 curr에 저장 


	while (curr != NULL) { //포인터가 NULL이 아닐 때 반복

		printf("%d\n", curr->data);
		printf("%s\n", curr->m);
		curr = curr->next;
	}

	free(middle2);
	free(middle);
	free(head);
	*/
	return 0;
}
