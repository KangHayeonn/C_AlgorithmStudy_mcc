// 작성전

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int DATA;

typedef struct _Node {
	DATA data;
	struct _Node* lchild;
	struct _Node* rchild;
}*Node;
//빈 트리

Node tree = NULL;

Node makeroot(DATA data) {
	tree = (struct _Node*)malloc(sizeof(struct _Node));
	tree->data = data;
	tree->lchild = tree->rchild = NULL;
	return tree;
}
Node makeleftchild(Node cur, DATA data) {
	struct _Node* newnode = (struct _Node*)malloc(sizeof(struct _Node));
	newnode->data = data;
	newnode->lchild = newnode->rchild = NULL;
	cur->lchild = newnode;
	return newnode;
}
Node makerightchild(Node cur, DATA data) {
	struct _Node* newnode = (struct _Node*)malloc(sizeof(struct _Node));
	newnode->data = data;
	newnode->lchild = newnode->rchild = NULL;
	cur->rchild = newnode;
	return newnode;
}
Node searchtree(Node cur, DATA data) {
	if (cur == NULL) {
		cur = makeroot(data);
		return cur;
	}
	else if (data < cur->data) {
		cur->lchild = searchtree(cur->lchild, data);
	}
	else if (data > cur->data) {
		cur->rchild = searchtree(cur->rchild, data);
	}
	return cur;
}
int isTreeEmpty(Node root) {
	if (root == NULL)
		return 1;
	else
		return 0;
}
void postorder(Node cur) {
	if (cur == NULL)
		return;
	postorder(cur->lchild);
	postorder(cur->rchild);
	printf("%d\n", cur->data);
}


int main() {
	int n;
	Node a = NULL;
	while (scanf("%d", &n) != EOF) {
		a = searchtree(a, n);
	}
	postorder(a);

	return 0;
}
