#include<stdio.h>
#include<stdlib.h>

void bubblesolt(int **arr, int digits){    //오름차순 이지만 내림차순처럼 써도됨
    int temp[2];

    for (int j=0;j<digits;j++){
        for (int i=j;i>0;i--){
            if (arr[i][0]<arr[i-1][0]){
                temp[0] = arr[i][0];
                temp[1] = arr[i][1];
                arr[i][0] = arr[i-1][0];
                arr[i][1] = arr[i-1][1];
                arr[i-1][0] = temp[0];   
                arr[i-1][1] = temp[1];               
            }
            else if (arr[i][0]==arr[i-1][0]&&arr[i][1]<arr[i-1][1]){
                temp[0] = arr[i][0];
                temp[1] = arr[i][1];
                arr[i][0] = arr[i-1][0];
                arr[i][1] = arr[i-1][1];
                arr[i-1][0] = temp[0];   
                arr[i-1][1] = temp[1];      
            }
        }
    }

}

void swap(int **arr, int i, int j){
    int temp[2];
    temp [0] = arr[i][0];
    temp[1] = arr[i][1];
    arr[i][0] = arr[j][0];
    arr[i][1] = arr[j][1];
    arr[j][0] = temp[0];
    arr[j][1] = temp[1];
}

int partition(int **arr, int l, int r){
    int pivot, i,j,temp;
    pivot = l;
    i = l; j = l+1;
    for (;j<=r;j++){
        if (arr[j][0]<arr[pivot][0]){
            i++;
            if (i!=j)
                swap(arr,i,j);
        }
        else if (arr[j][0]==arr[pivot][0]&&arr[j][1]<arr[pivot][1]){
            i++;
            if (i!=j)
                swap(arr,i,j);
        }
    }
    swap(arr,pivot,i);
    return i;
}

void quickSort(int **arr, int l,int r){

    if (l<r){
        int j = partition(arr,l,r);
        quickSort(arr,l,j-1);
        quickSort(arr,j+1,r);
    }
}


int main(){
    int N;
    scanf("%d",&N);
    int **arr = (int**)malloc(sizeof(int*)*N);
    for (int i=0;i<N;i++){
        arr[i] = (int*)malloc(sizeof(int)*2);
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }

    quickSort(arr,0,N-1);

    for (int i=0;i<N;i++){
        printf("%d %d\n",arr[i][0],arr[i][1]);
    }
}
