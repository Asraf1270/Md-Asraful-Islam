#include <stdio.h>
int main(viod)
{
    /*
    int score1 = 90;
    int score2 = 80;
    int score3 = 70;

    //Print Agerage
    printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
    // If we divide by 3, it will be an integer division and the result will be an integer( or show error). 
    // To get a floating-point result, we need to divide by 3.0 (a floating-point number).*/


    // Using array
    int scores[3];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;

    //Print Average
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
}