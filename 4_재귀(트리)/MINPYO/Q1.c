//
//  main.c
//  Binary Search Tree
//
//  Created by rabbi on 2021/08/24.
//

#include <stdio.h>
#include <stdlib.h>

typedef int Data;

// 배열로 이진 트리를 구현할 수도 있지만 링크드 리스트로 구현하는 것이 더 직관적
typedef struct BTreeNode {
    Data data;
    struct BTreeNode* left;
    struct BTreeNode* right;
}BTreeNode;

// Node에 동적 할당하여 주소값을 리턴해주는 함수
BTreeNode* MakeBTreeNode() {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->left = NULL;
    node->right = NULL;
    return node;
}

// parameter의 node의 데이터를 설정하는 함수
void SetData(BTreeNode* node, Data data) {
    node->data = data;
}

// parameter의 node의 데이터 값을 반환하는 함수
Data GetData(BTreeNode* node) {
    return node->data;
}

// parent Node의 Left sub Tree를 설정해주는 함수
void MakeLeftSubTree(BTreeNode* parent, BTreeNode* left_child) {
    parent->left = left_child;
}

// parent Node의 Right sub Tree를 설정해주는 함수
void MakeRightSubTree(BTreeNode* parent, BTreeNode* right_child) {
    parent->right = right_child;
}

// parameter의 Left sub Tree의 주소값을 반환하는 함수
BTreeNode* GetLeftSubTree(BTreeNode* parent) {
    return parent->left;
}

// parameter의 Right sub Tree의 주소값을 반환하는 함수
BTreeNode* GetRightSubTree(BTreeNode* parent) {
    return parent->right;
}

// 전위 순회 (루트 노드를 먼저 출력)
void PreorderTraversal(BTreeNode* Node) {
    if(Node == NULL) return;
    printf("%d ", Node->data);
    PreorderTraversal(Node->left);
    PreorderTraversal(Node->right);
    return;
}

// 중위 순회 (루트 노드를 중간(두 번째)에 출력)
void InorderTraversal(BTreeNode* Node) {
    if(Node == NULL) return;
    InorderTraversal(Node->left);
    printf("%d ", Node->data);
    InorderTraversal(Node->right);
    return;
}

// 후위 순회 (루트 노드를 마지막에 출력)
void PostorderTraversal(BTreeNode* Node) {
    if(Node == NULL) return;
    PostorderTraversal(Node->left);
    PostorderTraversal(Node->right);
    printf("%d ", Node->data);
    return;
}

// 재귀를 활용하여 동적 할당된 메모리를 해제하는 함수
void ExitTree(BTreeNode* Node) {
    if(Node == NULL) return;
    ExitTree(Node->left);
    ExitTree(Node->right);
    free(Node);
}

// 재귀를 이용하여 이진 탐색 트리를 생성하는 함수
BTreeNode* BinarySearchTree(BTreeNode* node, Data data) {
    if(node == NULL) { // Node를 넣을 위치를 찾으면
        node = MakeBTreeNode(); // Node 생성
        SetData(node, data); // Data 설정
    } else if(node->data >= data) {
        node->left = BinarySearchTree(node->left, data);
    } else if(node->data < data) {
        node->right = BinarySearchTree(node->right, data);
    }
    return node;
}

int main(int argc, const char * argv[]) {
    Data input;
    BTreeNode* rootNode = NULL;
    
    while(scanf("%d", &input) != EOF) {
        rootNode = BinarySearchTree(rootNode, input);
    }
    
    PostorderTraversal(rootNode);
    ExitTree(rootNode);
    return 0;
}
