#include "stack.h"


int main(){
    int N;
    char temp[51];
    top * T;
    stack *cursor;
    char *temp2;
    scanf("%d",&N);
    int status;
    T = createstack();
    

    for(int i=0;i<N;i++){
        status =0;
        scanf("%s",temp);
        temp2 = temp;
        while (*temp2)
        {
            if(temp2[0]=='('){
                push(T,'(');
            }
            else{
                if(T->top!=NULL){ //비지 않았다면
                    pop(T);
                }  
                else{       //비었으면
                    status=1;
                    break;
                }
            }
            temp2++;
        }
        if(T->top!=NULL){ //다 돌리고나서 비지 않았다면
            status = 1;
        }
        if(status==1){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
        while (T->top!=NULL)    //스택을 다 비워준다.
        {
            pop(T);
        }
    }
}
