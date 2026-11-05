#include <stdio.h>
#include "apc.h"
int Compare_list(Dlist *head1,Dlist *head2)
{
	int len1 = 0;
	int len2 =0;
	Dlist *temp  = head1;
	while(temp)
	{
		len1++;
		temp= temp->next;
	}
	temp = head2;
	while(temp)
	{
		len2++;
		temp = temp->next;
	}
	if( len1>len2)
	{
		return 1;
	}
	else if(len2>len1)
	{
		return 0;
	}
	else
	{
		while(head1 != NULL || head2 != NULL)
		{
			if(head1->data == head2->data)
			{
				head1= head1->next;
				head2 = head2->next;
			}
			else if(head1->data > head2->data)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	return 1;
}
int Asubtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
	int borrow =0;
	int result =0;

	while(tail1 != NULL || tail2 != NULL)
	{
		if(borrow==1)
		{
			tail1->data = tail1->data-1;
		}
		if( tail1 != NULL  && tail2 != NULL)
		{
			if( tail1->data >= tail2->data)
			{
				result = tail1->data -tail2->data;
				borrow = 0;
			}
			else
			{
				result = (tail1->data +10)-tail2->data;
				borrow =1;
			}	
			tail1  = tail1 ->prev;
			tail2  = tail2 ->prev;
		}
		else if(tail1 != NULL && tail2 == NULL)
		{
			if(tail1->data != -1)
			{
				result = tail1->data;
			}
			else
			{
				result = tail1->data +10;
			}
			tail1 = tail1->prev;
		}
		insert_at_first(headR,tailR,result);
	}
    return SUCCESS;
	printf("\n");
	// Dlist*temp  = *headR;
	// while(temp)
	// {
	// 	printf("%d",temp->data);
	// 	temp = temp->next;
	// }
	printf("\n");
}
