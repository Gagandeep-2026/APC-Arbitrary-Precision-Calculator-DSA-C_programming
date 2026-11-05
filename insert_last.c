#include "apc.h"
int insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *ptr = malloc(sizeof(Dlist));

    if (ptr == NULL)
    {
        return FAILURE;
    }

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    if (*tail == NULL)
    {
        *head = ptr;
        *tail = ptr;
        return SUCCESS;
    }

    ptr->prev = *tail;
    (*tail)->next = ptr;
    *tail = ptr;

    return SUCCESS;
}
