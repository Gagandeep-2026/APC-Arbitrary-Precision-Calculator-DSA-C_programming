#include "apc.h"

int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int res = 0;
    int carry = 0;

    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

    while (temp1 != NULL || temp2 != NULL)
    {
        res = carry;
        if(temp1 !=NULL && temp2 !=NULL)
        {
            res=temp1->data + temp2->data + carry;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        else if (temp1 != NULL)
        {
            res = temp1->data + carry;
            temp1 = temp1->prev;
        }
        else if (temp2 != NULL)
        {
            res = temp2->data + carry;
            temp2 = temp2->prev;
        }

        carry= res / 10;
        res = res % 10;

        if (insert_at_first(headR, tailR, res) == FAILURE)
        {
            return FAILURE;
        }
    }

    if (carry != 0)
    {
        if (insert_at_first(headR, tailR, carry) == FAILURE)
        {
            return FAILURE;
        }
    }
    return SUCCESS;
    // printf("\n");
    // Dlist *temp=*headR;
    // while(temp)
    // {
    //     printf("%d",temp->data);
    //     temp=temp->next;
    // }
}
