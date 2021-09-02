// 좌표 정렬하기 (백준 11650번)

#include <stdio.h>
#include <stdlib.h>

int partition(int** list, int begin, int end);
void QuickSort(int** list, int begin, int end) {
	if (begin <= end) {
		int p;
		p = partition(list, begin, end); // 확정된 피봇
		QuickSort(list, begin, p-1); // 왼쪽 부분집합에 대해 퀵정렬
		QuickSort(list, p + 1, end); // 오른쪽 부분집합에 대해 퀵정렬
	}
}


int partition(int** list, int L, int R) {
	int pivot = (L + R) / 2;
	int *temp;
	while (L < R) {
		/*for (int i = L; i < R; i++) {
		printf("%p -> %d,%d\n", list[i], list[i][0], list[i][1]);
		}*/
		while (list[L][0] < list[pivot][0] && L != R) L++;
		while (list[R][0] > list[pivot][0] && L != R) R--;
		while (list[L][0] == list[pivot][0] && list[L][1] < list[pivot][1] && L != R) L++;
		while (list[R][0] == list[pivot][0] && list[R][1] >= list[pivot][1] && L != R) R--;
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
	int N;
	scanf("%d", &N);
	int** list;
	list = (int**)malloc(sizeof(int*) * N);
	//list = (int**)calloc(N, sizeof(int*));
	for (int i = 0; i < N; i++) {
		list[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &list[i][0], &list[i][1]);
	}

	QuickSort(list, 0, N - 1);
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", list[i][0], list[i][1]);
	}

	for (int i = 0; i < N; i++) free(list[i]);
	free(list);
	return 0;
}
