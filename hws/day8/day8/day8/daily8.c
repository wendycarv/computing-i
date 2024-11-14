/*
    Author: Wendy Carvalho
    Date: 09/22/2022
 
    Purpose: The purpose of this program is to change the variable in memory that a user inputs depending on whether the number is even or odd.
 */
#include <stdio.h>

int main(int argc, char* argv[])

{
    int number;

    printf("Please enter a positive integer: ");

    scanf("%d", &number);
   
    if(number % 2 == 0)
    {
        printf("The next value of the number is: %d\n", number / 2);
    }
    else
    {
        printf("The next value of the number is: %d\n", number * 3 + 1);
    }
   
    return 0;
}

