#include <stdio.h>
int main(void)
{
    int n;
    printf("Number of scores: ");
    scanf("%d", &n);

    int scores[n];
    for(int i = 0; i < n; i++)
    {
        printf("Score: ");
        scanf("%d", &scores[i]);
    }

    //Print Average
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += scores[i];
    }
    printf("Average: %f\n", (float)sum / n);
}