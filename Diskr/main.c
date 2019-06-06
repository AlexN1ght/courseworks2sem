#include <stdio.h>


void findInDN(int D[], int* Vc, int r, int n);
void findDN(int D[], int* Vc, int r, int n);

void findDN(int D[], int* Vc, int r, int n)
{
    int VcR[n];
    for(int i = 0; i < n; i++) {
        VcR[i] = 0;
        if (D[r * n + i] == 1 && VcR[i] != -1) {
            VcR[i] = -1;
            Vc[i] = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        if (VcR[i] == -1) {
            findInDN(D, Vc, i, n);
        }
    }
}

void findInDN(int D[], int* Vc, int r, int n)
{
    int VcR[n];
    for(int i = 0; i < n; i++){
        VcR[i] = 0;
        if (D[r * n + i] == 1 && Vc[i] != -1 && Vc[i] != 1) {
            VcR[i] = 1;
            Vc[i] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        if (VcR[i] == 1) {
            findDN(D, Vc, i, n);
        }
    }
}


int  main(void) {
    int n = 0;
    printf("Введите размер графа: ");
    scanf("%d", &n);
    int D[n][n];
    int V[n];
    int Vc[n];
    printf("Введите матрицу смежности: ");
    for(int i = 0; i < n; i++){
        Vc[i] = 0;
        V[i] = -1;
        for(int j = 0; j < n; j++){
            scanf("%d", &D[i][j]);
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(Vc[i] == 0 && V[i] == -1) {
                Vc[i] = 1;
                findDN(D, Vc, i, n);
            }
        }
        for(int i = 0; i < n; i++){
            if(Vc[i] == 1) {
                V[i] = k;
                for(int j = 0; j < n; j++)
                    D[i][j] = 0;
                for(int j = 0; j < n; j++)
                    D[j][i] = 0;
            }
        }
        for(int l = 0; l < n; l++){
            Vc[l] = 0;
        }
    }

    putchar('\n');
    puts("Функция Гранди графа имет фид:");
    for(int i = 0; i < n; i++){
        printf("V%d\t", i + 1);
    }
    putchar('\n');
    for(int i = 0; i < n; i++){
        printf("%d\t", V[i]);
    }
    putchar('\n');
    return 1;
}
