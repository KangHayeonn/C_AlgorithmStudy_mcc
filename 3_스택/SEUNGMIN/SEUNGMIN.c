#include<stdio.h>
#include<stdlib.h>

typedef char Data;

struct stack{       //여기서 데이터 타입만 수정하면 됨  //이중 연결리스트로 왼쪽 포인터를 준다.
    Data data;
    struct stack *left;
}typedef stack;

typedef struct {    //스택의 탑을 가르킨다.
    stack *top;
}top;

top *createstack(){     //스택을 만든다.
    top *T;
    T = (top*)malloc(sizeof(top));
    T->top = NULL;
    return T;
}

void push(top *T, Data data){   
    if (T->top==NULL){     //첫 요소라면
        T ->top = (stack *)malloc(sizeof(stack));
        T ->top->data = data;
        T->top->left = NULL;
    }
    else{       //첫 요소가 아니라면
        stack *temp = (stack *)malloc(sizeof(stack));
        temp->left = T->top;
        temp->data = data;
        T->top = temp;
    }
}

    
stack *pop(top *T){   
    stack *temp;
    if (T->top->left!=NULL){    //바닥이 아닌경우 
        temp = T->top;
        T->top = T->top->left;      //탑을 하나 아래로 바꾼다
    }else{
        temp = (stack*)malloc(sizeof(stack));
        temp->data = T->top->data;
        temp->left= NULL;
        free(T->top);
        T->top= NULL;
    }
    return temp;
}
