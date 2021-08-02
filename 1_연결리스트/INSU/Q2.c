#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct NODE {  
	struct NODE* next; 
	double data; //data 받을때 'double'로 받을 것!!!!!!!!!!!!
};

void ADDNODE(struct NODE* target, double data) //'double'!!!!!!!!!!!!!!!!!!!!!
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

void REMOVENODE(struct NODE* target) {
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

int main()
{
	int num, i, n = 0;
	int subject;
	double max = INT_MIN, sum = 0, score = 0;

	struct NODE* head = malloc(sizeof(struct NODE)); 
	head->next = NULL;
	

	scanf("%d", &subject);
	for (i = 0; i < subject; i++) {
		scanf("%lf", &score);
		ADDNODE(head, score);
		if (score > max)
			max = score;
	}
	
	struct NODE* p = head->next;

	for (i = 0; i < subject; i++) {
		p->data = p->data / max * 100;
		sum += p->data;
		p = p->next;
	}

	printf("%lf", sum / subject);
	free(head);
	return 0;
}
