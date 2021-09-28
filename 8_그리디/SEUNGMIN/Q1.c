/*  백준 11047번 , 현재 보유한 화폐가 들어오고 그 화폐로 K원을 만들 수 있는 최소의 화폐수를 구하는문제
*/
#include<stdio.h>
#include<stdlib.h>

int main(){
    int N,K , divtemp , minimum =0; //divtemp 에 몇개까지 가능한지를 저장한다. minimum 은 총 코인의 수
    int *coin; //입력이 되어 들어올 화폐들을 저장할 1차원 배열을 선언 , 이후 동적할당한다.
    scanf("%d %d",&N,&K);

    coin = (int*)malloc(sizeof(int)*N);

    for (int i=N-1;i>=0;i--){   //오름차순으로 들어오는 화폐를 역으로 넣어준다.
        scanf("%d",&coin[i]);
    }

    for (int i=0;i<N&&K>0;i++){
        if (coin[i]<=K){
            divtemp = K/coin[i];
            K-=coin[i]*divtemp;
            minimum+=divtemp;
        }
    }

    printf("%d",minimum);
}                                               
