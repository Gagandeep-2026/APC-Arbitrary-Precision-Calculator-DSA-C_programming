#include "apc.h"

static void free_list(Dlist *head)
{
    Dlist *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

static void trim_zeros(Dlist **head, Dlist **tail)
{
    while (*head != NULL && *head != *tail &&
           (*head)->data == 0)
    {
        Dlist *temp = *head;
        *head = temp->next;
        (*head)->prev = NULL;
        free(temp);
    }
}

int division(Dlist *head1, Dlist *tail1,
             Dlist *head2, Dlist *tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp = head1;

    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;

    int count = 0;

    *headR = NULL;
    *tailR = NULL;

    /* Check division by zero */
    Dlist *check = head2;

    while (check != NULL && check->data == 0)
    {
        check = check->next;
    }

    if (head1 == NULL || head2 == NULL || check == NULL)
    {
        printf("Invalid division\n");
        return FAILURE;
    }

    /* Process dividend digits */
    while (temp != NULL)
    {
        /* Bring down one digit into List 3 */
        if (insert_at_last(&head3, &tail3, temp->data) == FAILURE)
            goto error;

        trim_zeros(&head3, &tail3);

        count = 0;

        /* Repeated subtraction */
        while (Compare_list(head3, head2) == 1)
        {
            Dlist *headSub = NULL;
            Dlist *tailSub = NULL;

            if (Asubtraction(tail3, tail2,
                             &headSub, &tailSub) == FAILURE)
            {
                free_list(headSub);
                goto error;
            }

            /* Replace List 3 with subtraction result */
            free_list(head3);

            head3 = headSub;
            tail3 = tailSub;

            trim_zeros(&head3, &tail3);

            count++;
        }

        /* Store quotient digit */
        if (insert_at_last(headR, tailR, count) == FAILURE)
            goto error;

        temp = temp->next;
    }

    trim_zeros(headR, tailR);

    free_list(head3);

    return SUCCESS;

error:
    free_list(head3);
    free_list(*headR);

    *headR = NULL;
    *tailR = NULL;

    return FAILURE;
}