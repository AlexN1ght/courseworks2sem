#include <stdio.h>
#include "lin-2-list-barrier.h"

List* list_create(void)
{
  List *lst;
  lst = (List*)malloc(sizeof(List));
  lst->data = 0;
  lst->next = lst;
  lst->prev = lst;
  return(lst);
}

void list_push(List *lst, data_type value)
{
    List *Next;
    Next = (List*)malloc(sizeof(List));
    Next->data = value;
    lst->data++;
    Next->prev = lst->prev;
    lst->prev = Next;
    Next->next = lst;
    (Next->prev)->next = Next;
}

int list_insert(List *lst, int i, data_type value)
{
	if (i == 0 || i > lst->data + 1) {
		return 1;
	}
	List *Inter;
	List *Tmp = lst;
	Inter = (List*)malloc(sizeof(List));
	for (int k = 0; k < i; k++) {
		Tmp = Tmp->next;
	}
	lst->data++;
	Inter->data = value;
	Inter->next = Tmp;
	Inter->prev = Tmp->prev;
	(Tmp->prev)->next = Inter;
	Tmp->prev = Inter;
	return 0;
}

int list_remove(List *lst, int i)
{
	if (i == 0 || i > lst->data) {
		return 1;
	}
	List *Tmp = lst;
	for (int k = 0; k < i; k++) {
		Tmp = Tmp->next;
	}
	(Tmp->prev)->next = Tmp->next;
	(Tmp->next)->prev = Tmp->prev;
	free(Tmp);
	return 0;
}

void list_print(List *lst)
{
    List *tmp = lst->next;
    for (int i = 0; i < lst->data; i++) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}


void list_destroy(List **lst) 
{
    List *tmp = (*lst)->next;
    List *next = NULL;
    while (tmp != *lst) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*lst);
    (*lst) = NULL;
}
