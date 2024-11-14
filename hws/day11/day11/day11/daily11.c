/*
 Author: Wendy Carvalho
 Date: 09/29/2022
 
 Purpose: The program takes the user's input (a number) and prints that many asterisks.
 
 Time spent: Approximately 45 minutes.
 */

#include <stdio.h>

void clear_keyboard_buffer(void);

void draw_line(int integer);

int main(int argc, char* argv[])
{
    int integer;
    
    printf("Please enter the number of asterisks you want in your line: \n");
    scanf(" %d", &integer);
    clear_keyboard_buffer();
    
    while (integer < 1 || integer > 79)
    {
        printf("I'm sorry, that number is unrecognized or out of range, try [1-79]:\n");
        scanf(" %d", &integer);
        clear_keyboard_buffer();

    }
    
    draw_line(integer);
    printf("\n");
    
    return 0;
}

void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        scanf("%c", &c);
    }
    return;
}

void draw_line(int integer)
{
    
    while (integer > 0)
    {
        printf("*");
        integer = integer - 1;
    }
    return;
}

