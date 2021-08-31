//
//  main.c
//  SelectionSort
//
//  Created by rabbi on 2021/08/30.
//

// Bubble Sort
// 인접한 두 개의 데이터를 비교하면서 정렬하고, 정렬된 데이터를 제외한 나머지의 정렬을 진행한다.
// 시간 복잡도에 대한 빅오를 비교 횟수를 기준으로 결정한다
// 시간복잡도: O(n^2)
// Best Case: 이미 정렬이 되어있는 상태여서 데이터의 이동이 발생하지 않는 경우
// Worst Case: 정렬기준의 반대로 저장되어 있어 비교할 때마다 데이터의 이동이 발생하는 경우
// Insertion Sort
// 정렬 안된 부분을 정렬 된 부분의 알맞는 특정 위치에 삽입해가며 정렬
// 시간복잡도: O(n^2)
// Best Case: 이미 다 정렬 되어 있어 안쪽 for문의 if 문이 거짓이 되어 break문이 실행되고 바깥 for문의 반복 횟수만큼만 진행된다
// Worst Case: 바깥 for문의 반복 횟수 * 안쪽 for문의 반복 횟수

// Selection Sort
// 정렬 순서상 앞서는 것을 가장 왼쪽으로 이동시키고, 빈 자리에 원래 데이터를 넣는다
// 비교 횟수: n-1 + n-2 + n-3 + ... + 2 + 1
// 시간 복잡도: O(n^2)
// Bubble Sort는 Best Case에서 한 번도 swap하지 않는다는 장점이,
// Selection Sort는 swap이 바깥쪽 for문에 위치에 swap 횟수가 n-1이여서 Worst Case에서의 장점이 있다

#include <stdio.h>
#include <stdlib.h>

// parameter의 두 변수가 가리키는 곳의 data를 swap하는 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int* array, int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < (size - 1 - i); j++) {
            if(array[j] > array[j+1]) {
                swap(&array[j], &array[j+1]);
            }
        }
    }
}

void InsertionSort(int* array, int size) {
    int i,j;
    for(i = 1; i < size; i++) {
        int data = array[i]; // 배열의 i번째 요소를 정렬 대상으로 지정
        for(j = i-1; j >= 0; j--) {
            if(array[j] > data) {
                array[j+1] = array[j];
            } else {
                break; // 삽입 위치를 찾았다면 break
            }
        }
        array[j+1] = data;
    }
}

void SelectionSort(int* array, int size) {
    for(int i = 0; i < size; i++) {
        int minIdx = i; // 배열의 i번째 index를 최솟값을 가진 index로 지정
        for(int j = i + 1; j < size; j++) {
            if(array[minIdx] > array[j]) { // 최솟값보다 더 작은 값이 있다면
                minIdx = j; // 최솟값을 가진 index로 지정한다
            }
        }
        swap(&array[i], &array[minIdx]); // 배열의 i번째 요소와 배열의 나머지 요소 중 최솟값을 가진 요소와 swap
    }
}

int main(int argc, const char * argv[]) {
    int* array;
    int size;
    printf("배열의 크기를 입력하세요: ");
    scanf("%d", &size);
    array = (int*)malloc(sizeof(int) * size);
    
    printf("배열의 요소를 입력하세요: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }
    
    printf("정렬 전: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n");
    
    SelectionSort(array, size);
    
    printf("정렬 후: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}
