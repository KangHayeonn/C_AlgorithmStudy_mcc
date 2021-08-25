// 작성전
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// 트리

typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
}Node;

Node *Search(Node *root, int x) {
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
// 탐색에 실패할 경우 노드 삽입  
Node *Insert(Node *root, int x) {
	Node *p = root;
	Node *parent = NULL;
	while(p!=NULL) {  
		parent = p;
		if(p->key == x) { // 이미 x가 존재  
			return p;
		}
		else if(p->key > x) { // 작은 수는 왼쪽으로  
			p = p->left;
		}
		else { // 큰 수는 오른쪽으로  
			p = p->right;
		}	
	} 
	//새 노드 할당 
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->key = x;
	newNode->left = newNode->right = NULL;
	
	// parent의 자식으로 새 노드 붙이기 
	if(parent != NULL) { // 처음 삽입할 경우를 빼고 실행  
		if(parent->key < newNode->key){
			parent->right = newNode;
		}
		else{
			parent->left = newNode;
		}
	}
	return newNode; // 새 노드 반환  
 
}
// 전위순회  
int preorder(Node *root) { //root-left-right 
	if(root == NULL){
		return 0;
	}
	printf("%d", root->key);
	preorder(root->left);
	preorder(root->right);
}
// 중위 순회 방법  
int inorder(Node *root) { //left-root-right
	if(root == NULL){
		return 0;
	}
	inorder(root->left);
	printf("%d", root->key);
	inorder(root->right);
}

//후위순회 
int postorder(Node *root) { //left-right-root
	if(root == NULL){
		return 0;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d\n", root->key);
} 
int main() {
	int k, i;
	scanf("%d", &k);
	Node *root= Insert(NULL, k);
	//preorder(root);
	while(1){
		//scanf("%d", &i);
		if(scanf("%d", &i)==EOF){
			break;
		}
		Insert(root, i);
	} 
	/*do {
		scanf("%d", &i);
		Insert(root, i);
	}
	while(i!=NULL); // 빈칸이 들어갔을때 반복 멈추는 방법  */
	
	//preorder(root); 
	//inorder(root); 
	postorder(root);
	//printf("\n");
	return 0;
}
