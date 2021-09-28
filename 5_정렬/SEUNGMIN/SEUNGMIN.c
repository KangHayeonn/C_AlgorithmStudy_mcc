#include<stdio.h>
#include<stdlib.h>

void bubblesolt(char **arr, int digits){    //오름차순 이지만 내림차순처럼 써도됨
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

void swap(int *a,int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}

int partition(int **arr, int l, int r){
    int pivot, i,j,temp;
    pivot = l;
    i = l; j = l+1;
    for (;j<=r;j++){
        if (arr[j][0]<arr[pivot][0]){
            i++;
            if (i!=j)
                swap(&arr[0][i],&arr[0][j]);
        }
    }
    swap(&arr[0][pivot],&arr[0][i]);
    return i;
}

void quickSort(int **arr, int l,int r){

    if (l<r){
        int j = partition(arr,l,r);
        quickSort(arr,l,j-1);
        quickSort(arr,j+1,r);
    }
}
