// 자료구조 1주차
// 평균 1546번 ( 백준 )


#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* strcpy_hy(char* str1, const char* str2);

// 연결리스트의 node 구조 (data+link)
typedef struct Node { //typedef를 쓰면 struct 키워드 안 붙이고 별칭 쓸 수 있음.
    char data[10];
    struct Node* link; // 다음 노드를 가리키는 포인터
}listNode;

// 리스트의 시작 (head 노드)
typedef struct Start_Linked {
    struct Node* head; // 리스트의 시작 (Node의 주솟값: head)
}linkedlist_h;


// 공백 리스트 생성
linkedlist_h* createLL(void) {
    struct Start_Linked* grade; // Node의 첫 주솟값인 head를 값으로 가지고 있는 L
    grade = (linkedlist_h*)malloc(sizeof(linkedlist_h));
    grade->head = '\0'; // 리스트가 없다
    return grade;
}

// 맨 앞에 노드 삽입
void unshiftLL(linkedlist_h* grade, char* input) {
    listNode* newnode;
    newnode = (listNode*)malloc(sizeof(listNode));
    strcpy_hy(newnode->data, input);
    newnode->link = grade->head; // newnode가 맨 앞으로 이동
    grade->head = newnode; // newnode 의 주솟값 가리킴
}

int main() {
    linkedlist_h* grade;
    linkedlist_h* a_s;
    int count;
    int s1[10];

    scanf("%d", &count);
    int* arr = (int*)malloc(sizeof(int) * count); // 배열 동적할당

    grade = createLL();
    a_s = createLL();

    for (int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
        sprintf(s1, "%d", arr[i]);
        unshiftLL(grade, s1);
        unshiftLL(a_s, s1);
    }
    //grade = createLL();

    /*
    grade = createLL();
    for (int i = 0; i < count; i++) {
       printf("arr[%d] : %d ", i, arr[i]);
    }*/
    float sum = 0;
    int k = 0;
    int before = 0;
    int max = 0;
    int number = 0;

    printf("[ 링크드 입력 값 ]\n");
    while (grade->head != NULL) {
        number = atoi(grade->head->data);
        if (before < number) max = number;

        before = atoi(grade->head->data);
        grade->head = grade->head->link;
        k++;
        printf("%d ", number);
    }
    printf("\n");

    //sum += before;
    while (a_s->head != NULL) {
        number = atoi(a_s->head->data);
        sum += number / (float)max * 100;
        a_s->head = a_s->head->link;
    }

    float average = sum / k;

    printf("average: %.2f", average);

    //printf("%f",float(6 / 8));

    free(arr); // 메모리 반납
    return 0;
}

char* strcpy_hy(char* str1, const char* str2) {
    int i = 0;
    while (str2[i] != '\0') {
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
    return str1;
}
