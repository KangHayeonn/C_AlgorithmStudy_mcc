// 자료구조 4주차
// 트리(재귀)

//    left   data(root) right
//  ---------------------------
//  |       |         |       |
//  ---------------------------

#include <stdio.h>
#include <stdlib.h>

typedef char Data;

struct treeNode {
	Data data;
	struct treeNode* left;
	struct treeNode* right;
}typedef treeNode;

treeNode* rootNode(Data data, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

// 전위 순회 (root -> left -> right)
void preorder(treeNode* root) {
	if (root!='\0') {
		printf("%c", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

// 중위 순회 (left -> root -> right)
void inorder(treeNode* root) {
	if (root != '\0') {
		inorder(root->left);
		printf("%c", root->data);
		inorder(root->right);
	}
}

// 후위 순회 (left -> right -> root)
void postorder(treeNode* root) {
	if (root != '\0') {
		postorder(root->left);
		postorder(root->right);
		printf("%c", root->data);
	}
}

treeNode* insertNode(treeNode* root, char input) {
	treeNode* newNode;
	if (root == '\0') {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		newNode->data = input;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	else if (input < root->data) root->left = insertNode(root->left, input);
	else if (input > root->data) root->right = insertNode(root->right, input);
	else if (input == root->data) return;
}

int main() {
	treeNode* n7 = rootNode('D', NULL, NULL);
	treeNode* n6 = rootNode('C', NULL, NULL);
	treeNode* n5 = rootNode('B', NULL, NULL);
	treeNode* n4 = rootNode('A', NULL, NULL);
	treeNode* n3 = rootNode('/', n6, n7);
	treeNode* n2 = rootNode('*', n4, n5);
	treeNode* n1 = rootNode('-', n2, n3);

	preorder(n1);
	printf("\n");

	inorder(n1);
	printf("\n");

	postorder(n1);
	printf("\n");

	return 0;
}
