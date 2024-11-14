/*
    Author: Wendy Carvalho
    Date: 10/30/2022
 
    Purpose: This program asks whether the user would like to convert values that are lengths or weights. It also continues to ask until the user decides to quit. Once the user chooses an option, it asks from which measuring system the user would like to convert and continues to do so until they enter valid inpute
 
    Sources of Help: Stackoverflow.com
 
    Time Spent: 45 minutes
 */

#include <stdio.h>

int ask(void);
void convert_lengths(double length_value);
void convert_weights(double weight_value);

void length_to_metric(void);
void length_to_us(void);

void weight_to_metric(void);
void weight_to_us(void);

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    int output;
    do
    {
       output = ask();
        
        if (output == 1)
        {
            int value = 0;
            convert_lengths(value);
        }
        else if (output == 2)
        {
            int value2 = 0;
            convert_weights(value2);

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

void convert_lengths(double length_value)
{
    int length_choice;
    printf("You have chosen lengths. Do you want to convert lengths (1) from feet/inches to meters/centimeters, (2) from meters/centimeters to feet/inches, or (0) quit? \n");
    scanf("%d", &length_choice);
    clear_keyboard_buffer();
    
    while (length_choice != 0 && length_choice != 1 && length_choice != 2)
    {
        printf("Please choose 1 for lengths, 2 for weights, or 0 if you wish to quit.\n");
        scanf("%d", &length_choice);
        clear_keyboard_buffer();
    }
    
    if (length_choice == 1)
    {
        length_to_metric();
    }
    else if (length_choice == 2)
    {
        length_to_us();
    }
    else if (length_choice == 0)
    {
        return;
    }
}

void convert_weights(double weight_value)
{
    int weight_choice;
    printf("You have chosen weights. Do you want to convert lengths (1) from pounds/ounces to kilograms/grams, (2) from kilograms/grams to pounds/ounces, or (0) quit? \n");
    scanf("%d", &weight_choice);
    clear_keyboard_buffer();
    
    while (weight_choice != 0 && weight_choice != 1 && weight_choice != 2)
    {
        printf("Please choose 1 for lengths, 2 for weights, or 0 if you wish to quit.\n");
        scanf("%d", & weight_choice);
        clear_keyboard_buffer();
    }
    
    if (weight_choice == 1)
    {
        weight_to_metric();
    }
    else if (weight_choice == 2)
    {
        weight_to_us();
    }
    else if (weight_choice == 0)
    {
        return;
    }
}

void length_to_metric(void)
{
    printf("Converting lengths from us to metric.\n");
}

void length_to_us(void)
{
    printf("Converting lengths from metric to us.\n");
}


void weight_to_metric(void)
{
    printf("Converting weights from us to metric.\n");
}

void weight_to_us(void)
{
    printf("Converting weights from metric to us.\n");
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
