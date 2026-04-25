#include <stdio.h>
int main(int argc, char *argv[])
{
    // printf("Hello, %s\n", argv[1]);

    /* // check if user input is correct
     if (argc == 2)
     {
         printf("Hello, %s\n", argv[1]);
     }
     else
     {
         printf("Usage: ./greet name\n");
     }
    */

    // for (int i = 0; i < argc; i++)
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%i]: %s\n", i, argv[i]);
    }
}