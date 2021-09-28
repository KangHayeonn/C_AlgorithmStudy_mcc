#include<stdio.h>
#include<stdlib.h>

int digits(int N){
    int temp=0;
    while (N!=0)
    {
        N = N/10;
        temp++;
    }
    return temp;
}

void charcp(char **arr, int N, int digit){
    for (int i=digit-1;i>=0;i--){
        arr[0][i] = N%10;
        N /=10;
    }
}

void bubblesolt(char **arr, int digits){
    int temp;

    for (int j=0;j<digits;j++){
        for (int i=j;i>0;i--){
            if (arr[0][i]<arr[0][i-1]){
                temp = arr[0][i];
                arr[0][i] = arr[0][i-1];
                arr[0][i-1] = temp;
            }
        }
    }

}


int main(){
    int N , digit;
    scanf("%d",&N);
    digit = digits(N);
    char *arr = (char*)malloc(digit);
    charcp(&arr,N,digit);
    bubblesolt(&arr,digit);
    int sum =0;    
    for (int i=digit-1;i>=0;i--){
        sum*=10;
        sum +=arr[i];  
    }
    printf("%d",sum);

}
