#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int len;

int strlen(const char *str){    //문자열 길이 구하기
    const char *temp = str;
    int count =0;
    while (*temp){ 
    temp = temp +1;
    count++;
    }
    return count;
}

void picknum(const char * number ,char *bignum, int k ,  int kcount, int  start){
    if (k==0){  //뽑을게 없다면 종료
        return;
    }
    int pick[2];    //0번인덱스는 최대수를  , 1번 인덱스에는 그 최대수의 인덱스를 저장한다.
    pick[0] = number[start] - '0';
    pick[1] = start;

    for (int i=start+1;i<len-k+1;i++){
        
        if(pick[0]<(number[i]-'0')){
            pick[0] = number[i]-'0';
            pick[1] = i;
        }   
    }
    bignum[kcount] = pick[0] + '0';
    picknum(number, bignum,k-1,kcount+1,pick[1]+1);
}

char* solution(const char* number, int k) {     //몇 개를 제거할지가 k에 담긴다.
    len = strlen(number);
    char* answer = (char*)malloc(len-k+1);
    answer[len-k]='\0';
    picknum(number,answer,len-k,0,0);
    return answer;
}
