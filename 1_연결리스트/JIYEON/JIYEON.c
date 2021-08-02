#include <stdio.h>
#include <stdlib.h>


int main()
{
	int n, a; //n,a은 임의의 수
	int i;
	int* m;
	scanf_s("%d\n", &n);

	m = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++) {
		
		*(m + i) = a + i;

	}
	free(m);

	return 0;


}
