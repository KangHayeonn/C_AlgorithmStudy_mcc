// 소트인사이드 (백준 1427번)

#include <stdio.h>
#include <string.h>

BubbleSort(char list[], int size) {
	char temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
		}
	}
}
int main() {
	char list[10000];
	scanf("%s", &list);
	BubbleSort(list, strlen(list));
	for (int t = strlen(list) - 1; t >= 0;  t--) printf("%c", list[t]);
	return 0;
}
