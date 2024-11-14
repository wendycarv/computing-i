/*
 Author: Wendy Carvalho
 Date: 09/20/2022
 
 Purpose: The purpose of this program is to take positive integers in the print_binary function, divide it by 2, and find its remainder to then display its binary version. The function print_binary does this process recursively until the number can no longer be divided by two and the full binary number can be printed.
 */

#include <stdio.h>

void print_binary(int normal_number);

int main(int argc, char* argv[])
{
    print_binary(19);
    printf("\n");
    return 0;
}

void print_binary(int normal_number)
{
    if(normal_number > 1)
    {
        print_binary(normal_number / 2);
    }
        printf("%d", normal_number % 2);
}

