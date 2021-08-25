// 작성전#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 트리

typedef struct Node {
	char key;
	struct Node *left;
	struct Node *right;
}Node;

Node *Search(Node *root, char x) {
	Node *p = root;
	while(p != NULL){
		if(p->key == x) {
			return p;
		}
		else if(p->key > x) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	return NULL; // 탐색하지 못할경우  
} 

Node *Insert(Node *root, char x) {
	Node *p = root;
	Node *parent = NULL;
	while(p!=NULL) {
		parent = p;
		if(p->key == x) {
			return p;
		}
		else if(p->key > x) {
			p = p->left;
		}
		else {
			p = p->right;
		}	
	} 
	//새 노드 할당 
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->key = x;
	newNode->left = newNode->right = NULL;
	
	// parent의 자식으로 새 노드 붙이기 
	if(parent != NULL) {
		if(parent->key < newNode->key){
			parent->right = newNode;
		}
		else{
			parent->left = newNode;
		}
		return newNode; // 새 노드 반환  
	} 
}
// 전위순회  
void preorder(Node *root) {
	if(root == NULL){
		return 0;
	}
	printf("%c", root->key);
	preorder(root->left);
	preorder(root->right);
}
// 중위 순회 방법  
void inorder(Node *root) {
	if(root == NULL){
		return 0;
	}
	inorder(root->left);
	printf("%c", root->key);
	inorder(root->right);
}

//후위순회 
void postorder(Node *root) {
	if(root == NULL){
		return 0;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%c", root->key);
} 
int main() {
	Node *root = Insert(NULL, 'D');
	Insert(root,'I');
	Insert(root,'F');
	Insert(root,'A');
	preorder(root); 
	//inorder(root); 
	//postorder(root);
	printf("\n");
	return 0;
}
