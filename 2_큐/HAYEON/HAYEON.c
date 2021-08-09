// 자료구조 2주차
// 큐 (Queue)

// ver1 : 배열을 이용한 순차큐
// ver2 : 연결 자료구조를 이용한 연결큐

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Q_Size 10 // 여기에 세미콜론 쓰지말것 ㅡㅡ

; // 엥?
typedef struct node {
    char queue[Q_Size];
    // int element;
    //char front, rear; // 첫번째, 마지막 원소의 인덱스를 저장
    int front, rear;
}Queue;

Queue* createQ_list() { // 반환값이 포인터인 함수
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->front = -1; // 인덱스 처음 초기화
    Q->rear = -1;
    return Q;
}

int isEmptyQ_list(Queue* Q) { // 반환값이 정수형인 함수
    if (Q->front == Q->rear) {
        printf("큐 비어있음");
        return 1;
    }
    else return 0;
}

int isFullQ_list(Queue* Q) {
    if (Q->rear == Q_Size - 1) return 1;
    else return 0;
}

void enQueue_list(Queue* Q, char data) {
    if (isFullQ_list(Q)) return;
    else {
        // 기존 rear 뒤쪽에 삽입

        // 방법1 : 실패 (idx에 값을 넣어준거라 rear값은 그대로)
        //int idx = (*Q).rear+1;
        //Q->queue[idx] = data;

        // 방법2 : 실패 (rear자체의 값을 늘려주고 rear를 갱신시켜 주지않음)
        //해당 방법은 prinfQ의 범위를 늘려주면 출력은 되지만 뭉개짐
        // Q->queue[Q->rear+1] = data;

        // 방법3 : 성공 (rear의 값을 갱신해주고 늘려줌)
        //Q->rear++; // Q->rear (*Q).rear
        //Q->queue[Q->rear] = data;

        // 방법4 : 성공 (방법3랑 같은 문법)
        Q->rear = Q->rear + 1;
        Q->queue[Q->rear] = data;

        // 방법5 : 성공 (방법4의 순서만 다름 , 레어의 증감과 갱신 모두)
        //Q->queue[Q->rear+1] = data;
        //Q->rear = Q->rear + 1; //갱신

        // 방법 6 : 성공 (방법 3과 방법 4와 같은 문법)
        //Q->rear += 1;
        //Q->queue[Q->rear] = data;
    }
}

void deQueue_list(Queue* Q) {
    // 매개변수를 굳이 Q만 써주는 이유
    // 큐의 삭제는 어차피 선입선출이라 제일 앞에 있는걸 뽑아내면 됨

    if (isEmptyQ_list(Q)) return;
    else {
        Q->front = Q->front + 1;  
        return Q->queue[Q->front]; // 기존 front 자리 부분꺼 삭제됨
    }
}

char searchQ_list(Queue* Q) {
    if (isEmptyQ_list(Q)) {
        printf("탐색할게 없음");
        return;
    }
    else {
        printf("s: %d\n", Q->front);
        //return Q->queue[Q->front];
        return Q->queue[Q->front]; // 이부분 때려맞췄는데 왜 되지이잉ㅇ..
    }
}

void printQ_list(Queue* Q) {
    printf("Q의 출력\n");
    printf("[");
    for (int i = Q->front + 1; i < Q->rear + 1; i++) {
        printf("%c", Q->queue[i]);
    }
    printf("]\n");
}

int main() {
    Queue* Q = createQ_list();
    char data;
    printQ_list(Q);
    enQueue_list(Q, 'A');
    printQ_list(Q);
    
    enQueue_list(Q, 'B');
    printQ_list(Q);
    enQueue_list(Q, 'a');
    printQ_list(Q);
    deQueue_list(Q);
    printQ_list(Q);
    deQueue_list(Q);
    printQ_list(Q);

    enQueue_list(Q, 'A');
    printQ_list(Q);
    enQueue_list(Q, 'B');
    printQ_list(Q);
    enQueue_list(Q, 'C');
    printQ_list(Q);
    char c = searchQ_list(Q);
    printf("search해서 찾은것 : %c\n", c);
    //printf("%d\n",createQ_list());
    //printf("%s\n", createQ_list());

}
