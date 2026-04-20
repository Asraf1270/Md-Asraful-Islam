#include <stdio.h>

int main(void)
{
    int x, y;
    char op;

    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y);

    printf("operator: ");
    scanf(" %c", &op);

    if (op == '+')
    {
        printf("%d %c %d = %d\n", x, op, y, x + y);
    }
    else if (op == '-')
    {
        printf("%d %c %d = %d\n", x, op, y, x - y);
    }
    else if (op == '*')
    {
        printf("%d %c %d = %d\n", x, op, y, x * y);
    }
    else if (op == '/')
    {
        printf("%d %c %d = %f\n", x, op, y, (float)x / y);
    }
    else if (op == '%')
    {
        printf("%d %c %d = %d\n", x, op, y, x % y); 
    }
    else
    {
        printf("Invalid operator.\n");
    }
}