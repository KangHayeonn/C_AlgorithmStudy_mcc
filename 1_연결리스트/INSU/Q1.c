#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct NODE {  
	struct NODE* next; 
	int data; 
};

void ADDNODE(struct NODE* target, int data) 
{
	if (target == NULL)
		return;

	struct NODE* newnode = malloc(sizeof(struct NODE)); 
	if (newnode == NULL)
		return;

	newnode->next = target->next; 
	newnode->data = data; 

	target->next = newnode;
}

void REMOVENODE(struct NODE* target)
{
	if (target == NULL)
		return;

	struct NODE* removenode = target->next; 
	if (removenode == NULL)
		return;

	target->next = removenode->next; 
	free(removenode); 
}

void print_list(struct NODE* target) {
	struct NODE* curr = target->next; 
	while (curr != NULL) { 
		printf("%d\n", curr->data);
		curr = curr->next; 
	}
}

int main() {
	int max = -1000001, min = 1000001;
	int num;
	int i, n;
	struct NODE* head = malloc(sizeof(struct NODE)); //머리 노드 생성
	head->next = NULL;


	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		ADDNODE(head, num);
		if (max < num) max = num;
		if (min > num) min = num;
	}

	printf("%d %d", min, max);

	free(head);

	return 0;
}
