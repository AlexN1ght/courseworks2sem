#include<stdio.h>
#include "lin-2-list-barrier.h"

#define LISTS_NUM 10

int list_no(int *st);

int main(void)
{
	char c;
    char fb;
	int st;
	int no;
	int val;
	List *A[LISTS_NUM];
	for (int i = 0; i < LISTS_NUM; i++) {
		A[i] = NULL;
	}
	while (1){
		scanf("%c", &c);
		switch (c) {
			case 'c':
				if (list_no(&st)) {printf("?\n");break;}
                if (A[st] == NULL) {
                    A[st] = list_create();
                } else {
                    printf("?\n");
                }
				break;

            case 'd':
				if (list_no(&st)) {printf("?\n");break;}
				if (A[st] != NULL) {
					list_destroy(&A[st]);
				} else {
					printf("List dose not exist\n");
				}
				break;
			case 'a':
				if (list_no(&st)) {printf("?\n");break;}
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
                if (scanf(" %c", &fb) != 1) {printf("?\n");;break;}
                switch (fb) {
                    case 'f':
                        while (scanf("%d", &val) == 1) {
                            list_push_front(A[st], val);
                            if (getchar() == '\n') {
                                break;
                            }
                        }
                        break;
                    case 'b':
                        while (scanf("%d", &val) == 1) {
                            list_push_back(A[st], val);
                            if (getchar() == '\n') {
                                break;
                            }
                        }
                        break;
                    case 'i':
                        if (scanf("%d %d",&no , &val) != 2) {printf("?\n");break;}
                        if (list_insert(A[st], no, val)) {
                            printf("?\n");
                        }
				        break;
                    default:
                        printf("?\n");
                        break;
                }
				break;
            case 'o':
				if (list_no(&st)) {printf("?\n");break;}
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
                if (scanf(" %c", &fb) != 1) {printf("?\n");break;}
                if (list_size(A[st]) == 0) {printf("?\n");break;}
                switch (fb) {
                    case 'f':
                        printf("%d\n", list_pop_front(A[st]));
                        break;
                    case 'b':
                        printf("%d\n", list_pop_back(A[st]));
                        break;
                    case 'i':
                        if (scanf("%d",&no) != 1) {printf("?\n");break;}
                        if (abs(no) > list_size(A[st]) || no == 0) {
                            printf("?\n");
                        } else {
                            printf("%d\n", list_get_out(A[st], no));
                        }
                        break;
                    case 'p':
                        if (scanf("%d",&no) != 1) {printf("?\n");break;}
                        if (abs(no) > list_size(A[st]) || no == 0) {
                            printf("?\n");
                        } else {
                            printf("%d\n", list_peak(A[st], no));
                        }
                        break;
                    default:
                        printf("?\n");
                        break;
                }
				break;
			case 'r':
				if (list_no(&st)) {printf("?\n");break;}
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
				if (scanf("%d",&no) != 1) {printf("?\n");break;}
				if (list_remove(A[st], no)) {
					printf("?\n");
				}
				break;
            case 'k':
				if (list_no(&st)) {printf("?\n");break;}
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
				if (scanf("%d",&no) != 1) {printf("?\n");break;}
				if (list_remove_k(A[st], no)) {
					printf("?\n");
				}
				break;
			case 'p':
				if (list_no(&st)) {printf("?\n");break;}
				if (A[st] == NULL) {
					printf("?\n");
					break;
				}
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
            case 's':
                if (list_no(&st)) {printf("?\n");break;}
                if (A[st] == NULL) {
					printf("?\n");
					break;
				}
                printf("%d\n", list_size(A[st]));
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

int list_no(int *st)
{
    if (scanf("%d", st) != 1) {return 1;}
    return *st > LISTS_NUM ? 1 : 0;
}
