#ifndef _LIN_2_LIST_BARRIER_H_
#define _LIN_2_LIST_BARRIER_H_

#include <stdlib.h>

typedef int data_type;

typedef struct List {
    data_type data;
    struct List *next;
    struct List *prev;
} List;

List* list_create(void);
void list_destroy(List **lst);
int list_remove(List *lst, int i);
int list_insert(List *lst, int i, data_type value);
void list_push(List *lst, data_type value);
void list_print(List *lst);
int list_size(List *lst);

#endif
