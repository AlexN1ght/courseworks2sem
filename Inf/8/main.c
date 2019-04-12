#include<stdio.h>
#include "lin-2-list-barrier.h"

int main(void)
{
	char c;
	int st;
	int no;
	int val;
	List *A[10];
	for (int i = 0; i < 10; i++) {
		A[i] = NULL;
	}
	while (1){
		scanf("%c", &c);
		switch (c) {
			case 'c':
				scanf("%d", &st);
				A[st] = list_create();
				break;

            case 'd':
				scanf("%d", &st);
				if (A[st] != NULL) {
					list_destroy(&A[st]);
				} else {
					printf("List dose not exist\n");
				}
				break;
			case 'a':
				scanf("%d", &st);
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
				while (scanf("%d", &val) == 1) {
					list_push(A[st], val);
					if (getchar() == '\n') {
						break;
					}
				}
				break;
            case 'i':
				scanf("%d", &st);
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
				scanf("%d %d",&no , &val);
				if (list_insert(A[st], no, val)) {
					printf("?\n");
				}
				break;
			case 'r':
				scanf("%d", &st);
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
				scanf("%d",&no);
				if (list_remove(A[st], no)) {
					printf("?\n");
				}
				break;
			case 'p':
				scanf("%d", &st);
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
				getchar();
				list_print(A[st]);
				break;
			case 'q':
				for (int i = 0; i < 10; i++) {
					if (A[i] != NULL) {
						list_destroy(&A[i]);
					}
				}
				return 0;
				break;
			case ' ':
				break;
			case '\n':
				break;
			default:
				printf("Unknown command\n");
				break;
		}
	}	
}
