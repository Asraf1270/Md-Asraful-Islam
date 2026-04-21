#include <stdio.h>

int get_int(char *prompt);

int main(void)
{
    int A = get_int("Enter an integer: ");
    int B = get_int("Enter another integer: ");
    printf("%d + %d = %d\n", A, B, A + B);

    printf("Wow!, Finally, I can make functions in C! :D\n");
}

int get_int(char *prompt)
{
    int n;

    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}