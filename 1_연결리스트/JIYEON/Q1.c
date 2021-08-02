#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n, i, max= -1000000, min=1000000;
	int* m;
	scanf_s("%d\n", &n);

	m = (int*)malloc(sizeof(int) * n);

	//for (int i = 0; i < n; i++) {

	//	scanf_s("%d ", &m[i]);// gets 함수처럼 한번에 읽어들여 사용하고 싶었음.

	//}

	//free(m);

	//max = m[0];
	//min = m[0];//

	for (int i = 0; i < n; i++) {

	//	scanf_s("%d", &m[i]); gets 함수처럼 한번에 읽어들여 사용하고 싶었음.
		if (max < m[i]) {
			max = m[i];
		}
		if (min > m[i]) {
			min = m[i];
		}

	}

	printf("%d %d", min, max);

	return 0;


}
