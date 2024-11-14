/*
    Author: Wendy Carvalho
    Date: 09/19/2022
 
    Answer to question: When using the argument 500000, the program stops running at 238045. So when œthe number is too big, the computer just stops running at some point because of its memory.
 
*/


#include <stdio.h>

void recursive_down_to_zero(int n)
{
    if(n >= 0)
    {
        printf("%d\n", n);
        recursive_down_to_zero(n-1);
    }

    return;
}

void recursive_up_to_int(int n)
{
    if(n >= 0)
    {
        recursive_up_to_int(n-1);
        printf("%d\n", n);
        
    }
    return;
}

int main(int argc, char* argv[])

{
    recursive_down_to_zero(10);
    printf("****\n");
    recursive_up_to_int(10);
    return 0;
}
