/*
    Author: Wendy Carvalho
    Date: 09/26/2022
 
    Purpose: This program asks the user to enter a negative number and traps the user in this loop until it receives one, then it prints it onto the screen.
 
    Time spent: 30 min.
 */

#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int x;
    int noc;
    
    printf("Please enter a negative integer: ");
    noc = scanf("%d", &x);
    clear_keyboard_buffer();
    
    while (noc != 1 || x >= 0)
    {
        printf("I'm sorry, you must enter a negative integer less than zero: ");
        noc = scanf("%d", &x);
        clear_keyboard_buffer();
    }
    printf("The negative integer was: %d\n", x);
    
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
}
