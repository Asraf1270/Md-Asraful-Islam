#include <stdio.h>
#include <string.h>

int main(void)
{
    char strings[5][20] = {"battleship", "cannon", "submarine", "destroyer", "carrier"};
    char s[20];
    printf("String: ");
    scanf("%s", s);
    for(int i = 0; i < 5; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}