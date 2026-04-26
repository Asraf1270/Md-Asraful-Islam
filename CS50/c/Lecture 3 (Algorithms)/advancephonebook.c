#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char number[20];
} person;

int main(void)
{
    person people[3];

    strcpy(people[0].name, "Asraful");
    strcpy(people[0].number, "01712345678");

    strcpy(people[1].name, "Saidor");
    strcpy(people[1].number, "01812345678");

    strcpy(people[2].name, "Zayed");
    strcpy(people[2].number, "01912345678");

    char s[20];
    printf("Name: ");
    scanf("%s", s);

    for( int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, s) == 0)
        {
            printf("Number: %s\n", people[i].number);
            return 0;
        }
    }

    printf("Name not found.\n");
    return 1;
}