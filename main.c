#include "apc.h"

int main(int argc, char *argv[])
{
    Dlist *head1=NULL, *tail1 = NULL;
    Dlist *head2=NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;

    /* Check command-line arguments */
    if (argc != 4)
    {
        printf("ERROR: Argument count is not maching ! ");
        return FAILURE;
    }

    /* Check operator */
    if (argv[2][0] != '+' && argv[2][0] != '-' && argv[2][0] != 'x' && argv[2][0] != 'X' && argv[2][0] != '*' && argv[2][0]!='%')
    {
        printf("Invalid operator\n");
        return FAILURE;
    }

    /*
     * Convert operand1 string into linked list
     */
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (argv[1][i] >= '0' && argv[1][i] <= '9')
        {
            insert_at_last(&head1, &tail1, argv[1][i] - '0');
        }
        else
        {
            printf("Invalid operand 1\n");
            return FAILURE;
        }
    }

    /*
     * Convert operand2 string into linked list
     */
    for (int i = 0; argv[3][i] != '\0'; i++)
    {
        if (argv[3][i] >= '0' && argv[3][i] <= '9')
        {
            insert_at_last(&head2, &tail2, argv[3][i] - '0');
        }
        else
        {
            printf("Invalid operand 2\n");
            return FAILURE;
        }
    }

    /*
     * Select operation
     */
    switch (argv[2][0])
    {
        case '+':
            addition(tail1, tail2, &headR, &tailR);
            break;

        case '-':
            if(Compare_list(head1, head2) == 1)
            {
                Asubtraction(tail1, tail2, &headR, &tailR);
            }
            else
            {
                printf("-");
                Asubtraction(tail2, tail1, &headR, &tailR);
            }
            break;

        case 'x':
        case 'X':
            multiplication(tail1, tail2, &headR, &tailR);
            break;

        case '%':
            if (division(head1, tail1, head2, tail2, &headR, &tailR) == FAILURE)
            {
                return FAILURE;
            }
            break;
    }

    /*
     * Print result
     */
    printf("Result = ");
    print_list(headR);
    printf("\n");

    return SUCCESS;
}