#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");  
    scanf("%i", &n);
    printf("n is %i\n", n);

    // char *s;
    // printf("s: ");
    // scanf("%s", s);  //This is dangerous because we are not allocating any memory for the string s, so it can cause a buffer overflow if the user enters a string that is too long. To fix this, we need to allocate memory for the string s using malloc or by declaring an array of characters with a fixed size.
    // printf("s is %s\n", s);

    char s[100];
    printf("s: ");
    scanf("%99s", s);  //This is safer because we are allocating memory for the string s by declaring an array of characters with a fixed size of 100. This way, we can prevent buffer overflow by limiting the number of characters that can be read into the string s to 99 (leaving space for the null terminator).
    printf("s is %s\n", s);
}