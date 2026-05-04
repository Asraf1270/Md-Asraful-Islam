#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;

    for(int i = 0; i < 3; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // TODO : free any memory already malloced
            return 1;
        }
        int number;
        printf("Number: ");
        scanf("%i", &number);
        n->data = number;
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }

        //  if list has number already
        else
        {
            for (node *ptr  = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }
    }


    // Time passes
    
    for(node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->data);
    }

    // Time passes

    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = ptr->next;
    }


    return 0;
}
