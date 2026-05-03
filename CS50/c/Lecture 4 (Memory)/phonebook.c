#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "w");
    if (file == NULL)
    {
        return 1;
    }
    
    char name[100];
    char number[100];   
    printf("Name: ");
    scanf("%99s", name);
    printf("Number: ");
    scanf("%99s", number);

    fprintf(file, "%s, %s\n", name, number);
    fclose(file);
}
