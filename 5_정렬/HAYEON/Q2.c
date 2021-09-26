// 좌표 정렬하기 (백준 11650번)

#include <stdio.h>
#include <stdlib.h>

// ver1 : 동적 메모리 할당 ( 이차원 배열 이용 )
// 실패

/*
void QuickSort(int **n, int left, int right);
int Partition(int **n, int left, int right);
void Swap(int **n, int left, int right);

int main()
{
    int N;
    scanf("%d", &N);

    int** arr = (int**)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    QuickSort(arr, 0, N-1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
    return 0;
}

void QuickSort(int **n, int left, int right) {
    if (left <= right) {
        int pivot = Partition(n, left, right);
        QuickSort(n, left, pivot - 1);
        QuickSort(n, pivot + 1, right);
    }
}

int Partition(int **n, int i, int right) {
    int pivot = n[i][0];
    int pivot_y = n[i][1];
    int pivot_idx = i;
    int j = i + 1;
    while (j <= right) {
        if (pivot < n[j][0]) {
            j++;
        }
        else if (pivot == n[j][0]) {
            if (pivot_y < n[j][1]) {
                j++;
            }
            else {
                do {
                    i++;
                } while (n[i][1] < pivot_y && i < j);

                if (i == j && n[i][1] < pivot_y) {
                    j++;
                    continue;
                }
                if (i == j && i >= right) break;
                Swap(n, i, j);
            }
        }
        else {
            do {
                i++;
            } while (n[i][0] < pivot && i < j);

            if (i == j && n[i][0] < pivot) {
                j++;
                continue;
            }
            if (i == j && i >= right) break;
            Swap(n, i, j);
        }
    }
    Swap(n, pivot_idx, i);
    return i;
}

void Swap(int **n, int left, int right) {
    int* temp;
    temp = n[left];
    n[left] = n[right];
    n[right] = temp;
}*/

// ver2 : 구조체 이용
// 실패
/*
typedef struct coordinate {
    int x;
    int y;
}coor;

void QuickSort(coor n[], int left, int right);
int Partition(coor n[], int left, int right);
void Swap(coor n[], int left, int right);

int main()
{
    int N;
    coor dot[100000];
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &dot[i].x, &dot[i].y);
    }

    QuickSort(dot, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", dot[i].x, dot[i].y);
    }
    return 0;
}

void QuickSort(coor n[], int left, int right) {
    if (left <= right) {
        int pivot = Partition(n, left, right);
        QuickSort(n, left, pivot - 1);
        QuickSort(n, pivot + 1, right);
    }
}

int Partition(coor n[], int i, int right) {
    int pivot = n[i].x;
    int pivot_y = n[i].y;
    int pivot_idx = i;
    int j = i + 1;
    while (j <= right) {
        if (pivot < n[j].x) {
            j++;
        }
        else if (pivot == n[j].x) {
            if (pivot_y < n[j].y) {
                j++;
            }
            else {
                do {
                    i++;
                } while (n[i].y < pivot_y && i < j);

                if (i == j && n[i].y < pivot_y) {
                    j++;
                    continue;
                }
                if (i == j && i >= right) break;
                Swap(n, i, j);
            }
        }
        else {
            do {
                i++;
            } while (n[i].x < pivot && i < j);

            if (i == j && n[i].x < pivot) {
                j++;
                continue;
            }
            if (i == j && i >= right) break;
            Swap(n, i, j);
        }
    }
    Swap(n, pivot_idx, i);
    return i;
}

void Swap(coor n[], int left, int right) {
    coor temp;
    temp = n[left];
    n[left] = n[right];
    n[right] = temp;
}*/

// ver3 : Partition if-else문 수정, 동적 메모리 할당 ( 이차원 배열 이용 )
// 성공

void QuickSort(int** n, int left, int right);
int Partition(int** n, int i, int right);
void Swap(int** n, int left, int right);

int main()
{
    int N;
    scanf("%d", &N);

    int** arr = (int**)malloc(sizeof(int*) * N);

    for (int i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * 2);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    QuickSort(arr, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d %d\n", arr[i][0], arr[i][1]);
    }
    return 0;
}

void QuickSort(int** n, int left, int right) {
    if (left < right) {
        int pivot = Partition(n, left, right);
        QuickSort(n, left, pivot - 1);
        QuickSort(n, pivot + 1, right);
    }
}

int Partition(int** n, int i, int right) {
    int pivot = n[i][0];
    int pivot_y = n[i][1];
    int pivot_idx = i;
    int j = i + 1;

    while (j <= right) {
        if (pivot > n[j][0]) {
            i++;
            if (i != j) Swap(n, i, j);
        }
        else if (pivot == n[j][0] && pivot_y > n[j][1]) {
            i++;
            if (i != j)Swap(n, i, j);
        }
        j++;
    }
    Swap(n, pivot_idx, i);
    return i;
}

void Swap(int** n, int left, int right) {
    int* temp;
    temp = n[left];
    n[left] = n[right];
    n[right] = temp;
}
