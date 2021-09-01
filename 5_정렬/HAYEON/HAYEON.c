// 자료구조 5주차
// 정렬

// 선택정렬 (Selection Sort)
// : 전체 원소 중에서 기준 위치에 맞는 원소를 선택해 자리를 교환하는 방식
// ex 오름차순 : 전체 원소 중에서 가장 작은 원소를 찾은 다음 첫째 원소와 자리를 교환. 
//               다음으로 작은 원소를 둘째 자리와 교환. 이런식으로 끝까지 반복

#include <stdio.h>
/*
SelectionSort(int list[], int size) {
	int temp;
	for (int idx = 0; idx < size; idx++) {
		int min = idx;
		for (int i = idx+1; i < size; i++) {
			if (list[i] < list[min]) min = i;
			else min = min;
		}
		temp = list[idx];
		list[idx] = list[min];
		list[min] = temp;
		printf("\n%d단계 : ", idx + 1);
		for (int t = 0; t < size; t++) printf("%d  ", list[t]);
	}
}
int main() {
	int list[7] = { 22,10,3,8,52,22,34 };
	SelectionSort(list, 7);
	return 0;
}*/

// 버블정렬 (Bubble Sort)
// : 인접한 원소를 두 개 비교하여 자리를 교환하는 방식을 반복
// 처음 작업이 수행된 후 가장 큰 원소가 가장 마지막 자리에 정렬된다.
/*
BubbleSort(int list[], int size) {
	int temp;
	for (int i = 0; i < size-1; i++) {
		printf("\n%d단계 : ", i + 1);
		for (int j = 0; j < size-1; j++) {
			if (list[j] > list[j+1]) {
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
			printf("\n");
			for (int t = 0; t < size; t++) printf("%d  ", list[t]);
		}
		//printf("\n%d단계 : ", i + 1);
		//for (int t = 0; t < size; t++) printf("%d  ", list[t]);
	}
}
int main() {
	int list[7] = { 80,10,3,8,52,22,34 };
	BubbleSort(list, 7);
	return 0;
}*/

// 퀵 정렬 (Quick Sort)
// : 기준값을 중심으로 왼쪽 부분집합과 오른쪽 부분집합을 분할한다.
// 이때, 기준값을 피봇(Pivot) 이라고 한다. 
// 그리고 왼쪽 부분집합에는 기준값보다 작은 원소를 이동시키고 오른쪽 부분집한에는 기준값보다 큰 원소들을 이동시킨다.

#include <stdio.h>

int partition(int *list, int begin, int end);
void QuickSort(int *list, int begin, int end) {
	int p;
	p = partition(list, begin, end); // 확정된 피봇
	if(begin < p) QuickSort(list, begin, p); // 왼쪽 부분집합에 대해 퀵정렬
	if(p+1 < end) QuickSort(list, p + 1, end); // 오른쪽 부분집합에 대해 퀵정렬
}
int partition(int *list, int L, int R) {
	int pivot = (L + R) / 2;
	int temp;
	
	while (L < R) {
		while (list[L] < list[pivot] && L != R) L++;
		while (list[R] >= list[pivot] && L!=R ) R--;
		if (L < R) {
			temp = list[L];
			list[L] = list[R];
			list[R] = temp;
		}
		else break;
	}

	// L==R 인 경우
	temp = list[pivot];
	list[pivot] = list[R];
	list[R] = temp;
	return R;
}
int main() {
	int list[10] = { 5, 6, 10, 4, 3, 8, 7, 1, 2, 9 };
	printf("\n초기 입력\n");
	for (int i = 0; i <= 9; i++) printf("%d ", list[i]);
	QuickSort(list, 0, 9);
	printf("\n\n최종 출력\n");
	for (int i = 0; i <= 9; i++) printf("%d ", list[i]);
	return 0;
}
