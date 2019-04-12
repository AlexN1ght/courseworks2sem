#include <stdio.h>
#include "lin-2-list-barrier.h"

List* list_create(void)
{
  List *lst;
  Node *nod;
  lst = (List*)malloc(sizeof(List));
  nod = (Node*)malloc(sizeof(Node));
  lst->size = 0;
  lst->barr = nod;
  nod->next = lst->barr;
  nod->prev = lst->barr;
  return(lst);
}

void list_push(List *lst, data_type value)
{
    Node *Next;
    Next = (Node*)malloc(sizeof(Node));
    Next->data = value;
    lst->size++;
    Next->prev = (lst->barr)->prev;
    (lst->barr)->prev = Next;
    Next->next = lst->barr;
    (Next->prev)->next = Next;
}

int list_insert(List *lst, int i, data_type value)
{
	if (i == 0 || i > lst->size + 1) {
		return 1;
	} else {
        lst->size++;
    }
	Node *Inter;
	Node *Tmp = lst->barr;
	Inter = (Node*)malloc(sizeof(Node));
	for (int k = 0; k < i; k++) {
		Tmp = Tmp->next;
	}
	Inter->data = value;
	Inter->next = Tmp;
	Inter->prev = Tmp->prev;
	(Tmp->prev)->next = Inter;
	Tmp->prev = Inter;
	return 0;
}

int list_remove(List *lst, int i)
{
	if (i == 0 || i > lst->size) {
		return 1;
	} else {
        lst->size--;
    }
	Node *Tmp = lst->barr;
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
    Node *tmp = (lst->barr)->next;
    for (int i = 0; i < lst->size; i++) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}


void list_destroy(List **lst) 
{
    Node *tmp = ((*lst)->barr)->next;
    Node *next = NULL;
    while (tmp != (*lst)->barr) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free((*lst)->barr);
    free(*lst);
    (*lst) = NULL;
}
