#include "apc.h"

int insert_at_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *ptr = malloc(sizeof(Dlist));

    if (ptr == NULL)
        return FAILURE;

    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = NULL;

    if (*head == NULL)
    {
        *head = ptr;
        *tail = ptr;
    }
    else
    {
        (*head)->prev = ptr;
        ptr->next=*head;
        *head = ptr;

    }
    return SUCCESS;
}