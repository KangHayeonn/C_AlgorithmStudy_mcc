#include <stdio.h>
#include <stdlib.h>


void permuminus(int **arr,int size,int pick, int **change){
    if (pick==0){
        int max = 0;
        int temp;
        int index;
        for (int i=1;i<size;i++){
            if (arr[0][i]<arr[0][0]){
                temp = arr[0][i];
                if (temp>max){
                    max = temp;
                    index = i;
                }
            }
        }
        change[0][0] = max;
        arr[0][index] = -1;
        permuminus(arr,size,pick+1,change);
    }
    else if (pick<size){
        int max = 0;
        int index;
        for (int i=0;i<size;i++){
            if(max<arr[0][i]){
                max = arr[0][i];
                index = i;
            }
        }
        arr [0][index] = -1;
        change[0][pick] = max;
        permuminus(arr,size,pick+1,change);
    }
    else{
        return;
    } 
}

int main(){
    int N;
    scanf("%d",&N);

    int size=1, temp;
    int *arr = (int*)malloc(sizeof(int)*N);
    
    for (int i=0;i<N;i++){  //입력받기
        scanf("%d",&arr[i]);
    }

    for (int i=N-1;i>0;i--){    //뒤에서부터 다운사이징할 사이즈 측정
        if (arr[i]>arr[i-1]){
            size++;
        }
        else break;
    }  
    size++;

    if (size>N){    //사전순으로 최신일 경우
        printf("-1");
        return 0;       //프로그램 종료
    }
   
    int *temparr = (int*)malloc(sizeof(int)*size); //임시 변수 설정
    int *change = (int*)malloc(sizeof(int)*size); //임시 변수 설정
    
    int j=0;

    for (int i=N-size;i<N;i++){     //temp에 복사
        temparr[j] = arr[i];
        j++;
    }

    permuminus(&temparr,size,0,&change);
    
    j=0;
    for (int i=N-size;i<N;i++){     //temp에 복사
        arr[i] = change[j];
        j++;
    }
        
    for (int i=0;i<N;i++){     //temp에 복사
        printf("%d ",arr[i]);
    }
}
