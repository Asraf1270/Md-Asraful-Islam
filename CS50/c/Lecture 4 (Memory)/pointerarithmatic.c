#include <stdio.h>
int main(void)
{
    char *s = "HI!";
    printf("%c\n", *s);
    printf("%c\n", *(s + 1));
    printf("%c\n", *(s + 2));
    printf("%c\n", *(s + 3));

    /*print the strings */
    printf("%s\n", s);
    printf("%s\n", s + 1);
    printf("%s\n", s + 2);

    /**/

}