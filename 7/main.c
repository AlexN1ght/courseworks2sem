#include<stdio.h>

int main(void)
{
	int M;
	int N;
	int LB[101];
	int YE[100];
	int tmp;
	int no = 0;
	
	scanf("%d%d", &M, &N);
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
		scanf("%d", &tmp);
		if (tmp != 0) {
			LB[no] = n + m * N;
			YE[no] = tmp;
			no++;
			}
		}
	}
	LB[no] = -1;
	for (int i = 0;i <= no; i++) {
		printf("%d ", LB[i]);
	}
	putchar('\n');
	for (int i = 0;i < no; i++) {
		printf("%d ", YE[i]);
	}
	putchar('\n');
	no = 0;
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
		if (n + m * N == LB[no]) {
			printf("%d ", YE[no]);
			no++;
		} else {
			printf("0 ");
		}
		}
		putchar('\n');
	}
	return 0;
}