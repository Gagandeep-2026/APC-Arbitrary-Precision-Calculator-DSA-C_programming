
#include "apc.h"

void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    Dlist *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");
}
