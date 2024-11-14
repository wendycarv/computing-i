/*
    Author: Wendy Carvalho
    Date: 09/24/2022
 
    Purpose: If the integer the user types in is big, the program still runs as normal. The behavior is different because this one actually runs while the program from daily6 stops at some point. 
 
 */
#include <stdio.h>

void loop_down_to_zero(int integer)
{
    while(integer >= 0)
    {
        printf("%d\n", integer);
        integer = integer - 1;
    }
    return;
}

void loop_up_to_int(int integer)
{
    int z = 0;
    while(integer >= z)
    {
        printf("%d\n", z);
        z = z + 1;
    }
    return;
}

int main(int argc, char* argv[])

{
    int integer;
    printf("Please enter a positive integer: ");
    scanf("%d", &integer);
    loop_down_to_zero(integer);
    printf("****\n");
    loop_up_to_int(integer);

    return 0;
}


