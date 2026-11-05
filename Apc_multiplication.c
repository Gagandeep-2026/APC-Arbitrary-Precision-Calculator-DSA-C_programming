#include "apc.h"

static void free_result(Dlist *head)
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

int multiplication(Dlist *tail1, Dlist *tail2, Dlist **head_R, Dlist **tail_R)
{
    Dlist *head_R1 = NULL;
    Dlist *tail_R1 = NULL;

    Dlist *temp2 = tail2;

    int count = 0;

    *head_R = NULL;
    *tail_R = NULL;

    if (tail1 == NULL || tail2 == NULL)
    {
        return FAILURE;
    }

    while (temp2 != NULL)
    {
        Dlist *head_R2 = NULL;
        Dlist *tail_R2 = NULL;

        Dlist *temp1 = tail1;

        int carry = 0;

        /* Multiplication of individual digits */
        while (temp1 != NULL)
        {
            int result = (temp1->data * temp2->data) + carry;

            if (insert_at_first(&head_R2, &tail_R2,
                                result % 10) == FAILURE)
            {
                free_result(head_R2);
                free_result(head_R1);
                return FAILURE;
            }

            carry = result / 10;
            temp1 = temp1->prev;
        }

        /* Store remaining carry */
        while (carry > 0)
        {
            if (insert_at_first(&head_R2, &tail_R2,
                                carry % 10) == FAILURE)
            {
                free_result(head_R2);
                free_result(head_R1);
                return FAILURE;
            }

            carry = carry / 10;
        }

        /* Add zeros according to place value */
        for (int i = 0; i < count; i++)
        {
            if (insert_at_last(&head_R2, &tail_R2, 0) == FAILURE)
            {
                free_result(head_R2);
                free_result(head_R1);
                return FAILURE;
            }
        }

        /* First partial product */
        if (head_R1 == NULL)
        {
            head_R1 = head_R2;
            tail_R1 = tail_R2;
        }
        else
        {
            Dlist *headSum = NULL;
            Dlist *tailSum = NULL;

            if (addition(tail_R1, tail_R2,
                         &headSum, &tailSum) == FAILURE)
            {
                free_result(head_R1);
                free_result(head_R2);
                return FAILURE;
            }

            free_result(head_R1);
            free_result(head_R2);

            head_R1 = headSum;
            tail_R1 = tailSum;
        }

        temp2 = temp2->prev;
        count++;
    }

    trim_zeros(&head_R1, &tail_R1);

    *head_R = head_R1;
    *tail_R = tail_R1;

    return SUCCESS;
}