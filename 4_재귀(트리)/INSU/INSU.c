// 작성전

#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTreeList.h"

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

/*
이진 검색 트리 조건
1. 노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다
2. 노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
3. 왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.
*/

Node searchtree(Node cur, DATA data) {
	if (cur == NULL) { //아무것도 없는 경우
		cur = makeroot(data);
		return cur;
	}
	else if (data < cur->data) { //조건 1
		cur->lchild = searchtree(cur->lchild, data);
	}
	else if (data > cur->data) { //조건 2
		cur->rchild = searchtree(cur->rchild, data);
	}
	return cur;
}


int isTreeEmpty(Node cur) {
	if (cur == NULL)
		return 1;
	else
		return 0;
}

void frontorder(Node cur) { //전위순회 1. 자신 2. 왼쪽 3. 오른쪽
	if (cur == NULL)
		return;
	printf("%c\n", cur->data);
	frontorder(cur->lchild);
	frontorder(cur->rchild);
}

void inorder(Node cur) { //중위순회 1. 왼쪽 2. 자신 3. 오른쪽
	if (cur == NULL)
		return;
	inorder(cur->lchild);
	printf("%c\n", cur->data);
	inorder(cur->rchild);
}

void postorder(Node cur) { //후위순회 1. 왼쪽 2. 오른쪽 3. 자신
	if (cur == NULL)
		return;
	postorder(cur->lchild);
	postorder(cur->rchild);
	printf("%c\n", cur->data);
}

int main() {
	Node a = makeroot('A');
	Node b = makeleftchild(a, 'B');
	Node c = makerightchild(a, 'C');
	// 중위순회하면 -> B(왼) A(자신) C(오) 
	inorder(a);

	printf("%d", isTreeEmpty(a)); // 트리가 차있으면 0 반환

	return 0;
}

/*

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <stdio.h>
#include <stdlib.h>

typedef char DATA;

typedef struct _Node {
	DATA data;
	struct _Node* lchild;
	struct _Node* rchild;
}*Node;

Node makeroot(DATA data);
Node makeleftchild(Node cur, DATA data);
Node makerightchild(Node cur, DATA data);
Node searchtree(Node cur, DATA data);
int isTreeEmpty(Node root);

#endif

*/
