/*
    Author: Wendy Carvalho
    Date: 10/27/2022
 
    Purpose: This program asks whether the user would like to convert values that are lengths or weights and prints a message on the screen indicating what they chose. It also continues to ask until the user decides to quit.
 
    Sources of Help: Classmate
 
    Time Spent: 10 minutes
 */

#include <stdio.h>

int ask(void);
void lengths(double length_value);
void weights(double weight_value);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int output;
    do
    {
       output = ask();
        
        if (output == 1)
        {
            double value = 5.0;
            lengths(value);
            printf("%.2f\n", value);
        }
        else if (output == 2)
        {
            double value2 = 4.0;
            weights(value2);
            printf("%.2f\n", value2);

        } else if (output == 0)
        {
            break;
        }
    } while (output == 1 || output == 2);
    return 0;
}

int ask(void)
{
    int choice;
    printf("Do you want to convert values that are lengths (1) or weights (2)? Please choose 1, 2, or 0 if you wish to quit.\n");
    scanf("%d", &choice);
    clear_keyboard_buffer();
    
    while (choice != 0 && choice != 1 && choice != 2)
    {
        printf("Please choose 1 for lengths, 2 for weights, or 0 if you wish to quit.\n");
        scanf("%d", &choice);
        clear_keyboard_buffer();
    }
    return choice;
}

void lengths(double length_value)
{
    printf("You have chosen lengths.\n");
}

void weights(double weight_value)
{
    printf("You have chosen weights.\n");
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

