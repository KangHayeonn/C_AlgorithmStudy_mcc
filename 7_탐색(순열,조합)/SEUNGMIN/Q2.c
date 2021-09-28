#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int maxsize = numbers_len*(numbers_len-1)/2;
    int *temp = (int*)malloc(sizeof(int)*maxsize);
    int index=0;
    int tempnum;
    
    
    for (int i=0;i<numbers_len-1;i++){  //우선 다 넣기.. 이후         중복제거와 정렬을 해야함
        for(int j=i+1;j<numbers_len;j++){
            temp[index] = numbers[i]+numbers[j];
            index++;
        }
    }
    
    for (int i=maxsize-1;i>0;i--){      //버블정렬
        for (int j=0;j<i;j++){
            if(temp[j]>temp[j+1]){
                tempnum = temp[j+1];
                temp[j+1] = temp[j];
                temp[j] = tempnum;
            }
        }
    }
    
    int *answer = (int*)malloc(sizeof(int)*maxsize);

    int same =-1; 
    int j=0;
    
    for (int i=0;i<maxsize;i++){
        if (same !=temp[i]){
            answer[j] = temp[i];
            same = temp[i];
            j++;
        }
    }
    //찌꺼기 제거 필요 , 안해도 정답은됨
    
    return answer;
}
