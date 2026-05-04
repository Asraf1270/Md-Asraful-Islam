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
            return 1;
        }
        int number;
        printf("Number: ");
        scanf("%i", &number);
        n->data = number;
        n->next = NULL;

        n->next = list;
        list = n;
    }


    // Time passes
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->data);
        ptr = ptr->next;
    }
}
