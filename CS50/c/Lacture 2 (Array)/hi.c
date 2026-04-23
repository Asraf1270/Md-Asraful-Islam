#include <stdio.h>
int main(void)
{
    /*
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%c %c %c\n", c1, c2, c3);
    printf("%i %i %i\n", c1, c2, c3);

    */

    char s[] = "HI! ";
    char word[5];

    word[0] = 'A';
    word[1] = 'S';
    word[2] = 'R';
    word[3] = 'A';
    word[4] = 'F';

    printf("%s\n", s);
    printf("%s\n", word);
    // %c is for character and %i is for integer
    printf("%c %c %c %c\n", word[0], word[1], word[2], word[3]);
    printf("%i %i %i %i\n", word[0], word[1], word[2], word[3]);

    printf("%c %c %c %c\n", s[0], s[1], s[2], s[3]);
    printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);

}