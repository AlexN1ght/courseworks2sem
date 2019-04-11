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

void list_print(List *lst)
{
    List *tmp = lst->next;
    for (int i = 0; i < lst->data; i++) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
}
