#include <stdio.h>
#include <string.h>

int main(void)
{
    char names[5][20] = {"Asraful", "Saidor", "Zayed", "Safi", "Ahad"};
    char numbers[5][20] = {"01712345678", "01812345678", "01912345678", "01612345678", "01512345678"};
    char s[20];
    printf("Name: ");
    scanf("%s", s);
    for(int i = 0; i < 5; i++)
    {
        if (strcmp(names[i], s) == 0)
        {
            printf("Number: %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}