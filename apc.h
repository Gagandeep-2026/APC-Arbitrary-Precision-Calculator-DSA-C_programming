#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define LIST_EMPTY -2
#define DATA_NOT_FOUND -3

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
} Dlist;

/* Arithmetic functions: four arguments each */
int addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

int Asubtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);

int multiplication(Dlist *tail1, Dlist *tail2,Dlist **head_R, Dlist **tail_R);

int division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headR, Dlist **tailR);

/* Doubly linked list functions */

int Compare_list(Dlist *head1,Dlist *head2);

int insert_at_last(Dlist **head, Dlist **tail, int data);
int insert_at_first(Dlist **head, Dlist **tail, int data);

void print_list(Dlist *head);

#endif