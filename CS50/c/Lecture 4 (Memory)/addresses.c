#include <stdio.h>

int main(void)

{
    /*
    int n = 50;
    printf("%i\n", n);
    printf("%p\n", &n);
    */

    char *s = "HI!";
    printf("%s\n", s);
    printf("%p\n", &s);
    /*To print the addresses of each character in the string */
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}