#include<stdio.h>
#include<math.h>

void readMatrix(int *M, int *N, int *LB, int *YE)
{
	int no = 0;
	int tmp;
	
	scanf("%d%d", M, N);
	
	for (int m = 0; m < *M; m++) {
		for (int n = 0; n < *N; n++) {
		scanf("%d", &tmp);
		if (tmp != 0) {
			LB[no] = n + m * *N;
			YE[no] = tmp;
			no++;
			}
		}
	}
	LB[no] = -1;
}

void printVectorsOfMatrix(int *LB, int *YE)
{
	int i = 0;
	printf("--------------------\nLB	YE\n");
	while (LB[i] != -1) {
		printf("%d\t%d\n",LB[i], YE[i]);
		i++;
	}
	printf("%d\n--------------------\n",LB[i]);
}

void printNormalMatrix(int M, int N, int *LB, int *YE)
{
	int no = 0;
	printf("--------------------\n");
	for (int m = 0; m < M; m++) {
		for (int n = 0; n < N; n++) {
		if (n + m * N == LB[no]) {
			printf("%d\t", YE[no]);
			no++;
		} else {
			printf("0\t");
		}
		}
		putchar('\n');
	}
	printf("--------------------\n");
}

int isDiag(int M, int N, int *LB)
{
	if (M != N) {
		return 0;
	}
	for (int i = 0; LB[i] != -1; i++) {
		if (LB[i] / N != LB[i] % N) {
			return 0;
		}
	}
	return 1;
}

void multiplyMatrix(int M_1, int N_1, int *LB_1, int *YE_1, int M_2, int N_2, int *LB_2, int *YE_2)
{
	int LB_R[101];
	int YE_R[100];
	for (int i = 0; i < 100;i++) {
		YE_R[i] = 0;
	}

	int no = 0;
	LB_R[0] = -1;

	for (int i = 0; LB_1[i] != -1; i++) {
		for (int k = 0; LB_2[k] != -1; k++) {
			if (LB_1[i] % N_1 == LB_1[k] / N_2) {
				no = 0;
				for (int l = 0; LB_R[l] != -1; l++) {
					if (LB_1[k] % N_2 + LB_1[i] / N_1 * N_2 == LB_R[l]) {
						break;
					}
					no++;
				}
				if (LB_R[no] == -1) {
					LB_R[no + 1] = -1;
				}
				LB_R[no] = LB_1[k] % N_2 + LB_1[i] / N_1 * N_2;
				YE_R[no] += YE_1[i] * YE_2[k];
			}
		}
	}

	for (int z = 0; LB_R[z] != -1; z++) {
		if (YE_R[z] == 0) {
			for (int z_2 = z; LB_R[z_2] != -1; z_2++) {
				LB_R[z_2] = LB_R[z_2 + 1];
				YE_R[z_2] = YE_R[z_2 + 1];
			}
		}
	}
	printVectorsOfMatrix(LB_R, YE_R);
	printNormalMatrix(M_1, N_2, LB_R, YE_R);
	
	if (isDiag(M_1, N_2, LB_R)) {
		printf("^Mairix is Diagonal^\n");
	} else {
		printf("^Mairix isn't Diagonal^\n");
	}
}


int main(void)
{
	int M_1;
	int N_1;
	int LB_1[101];
	int YE_1[100];

	int M_2;
	int N_2;
	int LB_2[101];
	int YE_2[100];
	
	readMatrix(&M_1, &N_1, LB_1, YE_1);
	readMatrix(&M_2, &N_2, LB_2, YE_2);

	printNormalMatrix(M_1, N_1, LB_1, YE_1);
	printVectorsOfMatrix(LB_1, YE_2);
	if (isDiag(M_1, N_1, LB_1)) {
		printf("^Mairix is Diagonal^\n");
	} else {
		printf("^Mairix isn't Diagonal^\n");
	}
	printNormalMatrix(M_2, N_2, LB_2, YE_2);
	printVectorsOfMatrix(LB_2, YE_2);
	if (isDiag(M_2, N_2, LB_2)) {
		printf("^Mairix is Diagonal^\n");
	} else {
		printf("^Mairix isn't Diagonal^\n");
	}

	multiplyMatrix(M_1, N_1, LB_1, YE_1, M_2, N_2, LB_2, YE_2);
	
	return 0;
}
