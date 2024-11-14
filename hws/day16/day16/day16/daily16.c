 /*
    Program: Imperial System to Metric System and Vice-Versa
    Author: Wendy Carvalho
    Date: 11/02/2022
    Time Spent: 5 hours
    Sources of Help: Stackoverflow.com and classmates
    Purpose: This program asks whether the user would like to convert values that are lengths or weights. It also continues to ask until the user decides to quit. Once the user chooses an option, it asks from which measuring system the user would like to convert and continues to do so until they enter valid input. Then, it asks the users for the values in the system they're converting from (kilograms and grams or ounces and pounds), then uses functions to convert these values to the other system and prints them onto the screen. The program will continue to repeat until the user asks to quit.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int menu(void);
void convert_lengths(void);
void convert_weights(void);

/**/

//Precondition: None (nothing has to be true before calling this function)
//Postcondition: The user will have entered a value for feet and inches and the converted values in meters and cm will be displayed on the screen.
void length_to_metric(void);

//Precondition: None
//Postcondition: The user will be prompted to enter a value for feet and inches and those values will be stored at the addresses indicated by the respective formal parameters.
void input_length_to_metric(int* feet, double* inches);

//Precondition: Feet and inches are non-negative values.
//Postcondition: The equivalent converted values for meters and cm are stored back at the addresses indicated by the respective formal parameters.
void calculate_length_to_metric(int feet, double inches, int* pMeters, double* p_cm);

//Precondition: The given values for feet and inches represent a length that is equivalent to the values given in meters and cm.
//Postcondition: Prints out that the given number of feet and inches are equivalent to the given meters and cm.
void output_length_to_metric(int feet, double inches, int meters, double cm);

/**/

//Precondition: None (nothing has to be true before calling this function)
//Postcondition: The user will have entered a value for meters and cm and the converted values in feet and inches will be displayed on the screen.
void length_to_us(void);

//Precondition: None
//Postcondition: The user will be prompted to enter a value for meters and cm and those values will be stored at the addresses indicated by the respective formal parameters.
void input_length_to_us(int* meters, double* cm);

//Precondition: Meters and cm are non-negative values.
//Postcondition: The equivalent converted values for feet and inches stored back at the addresses indicated by the respective formal parameters.
void calculate_length_to_us(int meters, double cm, int* pFeet, double* pInches);

//Precondition: The given values for meters and cm represent a length that is equivalent to the values given in feet and inches.
//Postcondition: Prints out that the given number of meters and cm are equivalent to the given feet and inches.
void output_length_to_us(int meters, double cm, int feet, double inches);

/**/

//Precondition: None (nothing has to be true before calling this function)
//Postcondition: The user will have entered a value for pounds and ounces and the converted values in kilograms and grams will be displayed on the screen.
void weight_to_metric(void);

//Precondition: None
//Postcondition: The user will be prompted to enter a value for pounds and ounces and those values will be stored at the addresses indicated by the respective formal parameters.
void input_weight_to_metric(int* pounds, double* ounces);

//Precondition: Pounds and ounces are non-negative values.
//Postcondition: The equivalent converted values for kilograms and grams are stored back at the addresses indicated by the respective formal parameters.
void calculate_weight_to_metric(int pounds, double ounces, int* pKilograms, double* pGrams);

//Precondition: The given values for pounds and ounces represent a length that is equivalent to the values given in kilograms and grams.
//Postcondition: Prints out that the given number of pounds and ounces are equivalent to the given kilograms and grams.
void output_weight_to_metric(int feet, double inches, int meters, double cm);

/**/

//Precondition: None (nothing has to be true before calling this function)
//Postcondition: The user will have entered a value for kilograms and grams and the converted values in pounds and ounces will be displayed on the screen.
void weight_to_us(void);

//Precondition: None
//Postcondition: The user will be prompted to enter a value for kilograms and grams and those values will be stored at the addresses indicated by the respective formal parameters.
void input_weight_to_us(int* kilograms, double* grams);

//Precondition: Kilograms and grams are non-negative values.
//Postcondition: The equivalent converted values for pounds and ounces are stored back at the addresses indicated by the respective formal parameters.
void calculate_weight_to_us(int kilograms, double grams, int* pPounds, double* pOunces);

//Precondition: The given values for kilograms and grams represent a length that is equivalent to the values given in pounds and ounces.
//Postcondition: Prints out that the given number of kilograms and grams are equivalent to the given pounds and ounces.
void output_weight_to_us(int pounds, double ounces, int kilograms, double grams);

/**/

double INCHES_TO_FEET = 1/12.0;
double FEET_TO_METERS = 0.3048;
double METERS_TO_CM = 100;

double OUNCES_TO_POUNDS = 1/16.0;
double POUNDS_TO_KILOGRAMS = 2.2046;
double KILOGRAMS_TO_GRAMS = 1000;

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    menu();
    return 0;
}

int menu(void)
{
    int choice;
    char ask;
    
    printf("Do you wish to convert any weights or lengths? y/n\n");
    scanf(" %c", &ask);
    clear_keyboard_buffer();
    
    while (ask != 'y' && ask != 'n' && ask != 'Y' && ask != 'N')
    {
        printf("Sorry, I don't understand. Do you wish to convert another value? y/n\n");
        scanf(" %c", &ask);
        clear_keyboard_buffer();
    }
    
    if (ask == 'y' || ask == 'Y')
    {
        printf("Do you want to convert values that are lengths (1) or weights (2)? Please choose 1, 2, or 0 if you wish to quit.\n");
        scanf("%d", &choice);
        clear_keyboard_buffer();

        while (choice != 0 && choice != 1 && choice != 2)
        {
            printf("Please choose 1 for lengths, 2 for weights, or 0 if you wish to quit.\n");
            scanf("%d", &choice);
            clear_keyboard_buffer();
        }

    
        if (choice == 1)
        {
            convert_lengths();
        }
        else if (choice == 2)
        {
            convert_weights();
        }
        else if (choice == 0)
        {
            return 0;
        }
    }
    
    if (ask == 'n' || ask == 'N')
    {
        return 0;
    }
    return 0;
}

void convert_lengths(void)
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
        exit(1);
    }
}

void length_to_metric(void)
{
    int feet, meters;
    double inches, cm;
    
    input_length_to_metric(&feet, &inches);
    calculate_length_to_metric(feet, inches, &meters, &cm);
    output_length_to_metric(feet, inches, meters, cm);
}

void input_length_to_metric(int* feet, double* inches)
{
    int noc;
    printf("Feet: ");
    noc = scanf("%d", feet);
    clear_keyboard_buffer();

    while (noc != 1 || feet < 0)
    {
        printf("Please enter a valid amount for feet: ");
        noc = scanf("%d", feet);
        clear_keyboard_buffer();
    }

    printf("Inches: ");
    noc = scanf("%lf", inches);
    clear_keyboard_buffer();

    while (noc != 1 || inches < 0)
    {
        printf("Please enter a valid amount for inches: ");
        noc = scanf("%lf", inches);
        clear_keyboard_buffer();
    }
}

void calculate_length_to_metric(int feet, double inches, int* pMeters, double* p_cm)
{
    double total_feet = feet + inches * INCHES_TO_FEET;
    double total_meters = total_feet * FEET_TO_METERS;
    
    *pMeters = floor(total_meters);
    *p_cm = (total_meters - *pMeters) * METERS_TO_CM;
}

void output_length_to_metric(int feet, double inches, int meters, double cm)
{
    printf("The value %d feet and %.2f inches in the metric system is %d meters and %.2f centimeters.\n", feet, inches, meters, cm);
    menu();
}

void length_to_us(void)
{
    int feet, meters;
    double inches, cm;
    
    input_length_to_us(&meters, &cm);
    calculate_length_to_us(meters, cm, &feet, &inches);
    output_length_to_us(meters, cm, feet, inches);
}

void input_length_to_us(int* meters, double* cm)
{
    int noc;
    
    printf("Meters: ");
    noc = scanf("%d", meters);
    clear_keyboard_buffer();

    while (noc != 1 || meters < 0)
    {
        printf("Please enter a valid amount for meters: ");
        noc = scanf("%d", meters);
        clear_keyboard_buffer();
    }

    printf("Centimeters: ");
    noc = scanf("%lf", cm);
    clear_keyboard_buffer();

    while (noc != 1 || cm < 0)
    {
        printf("Please enter a valid amount for centimeters: ");
        noc = scanf("%lf", cm);
        clear_keyboard_buffer();
    }
}

void calculate_length_to_us(int meters, double cm, int* pFeet, double* pInches)
{
    double total_meters = meters + cm / METERS_TO_CM;
    double total_feet = total_meters / FEET_TO_METERS;
    
    *pFeet = floor(total_feet);
    *pInches = (total_feet - *pFeet) / INCHES_TO_FEET;
}

void output_length_to_us(int meters, double cm, int feet, double inches)
{
    printf("The value %d meters and %.2f centimeters in the imperial system is %d feet and %.2f inches.\n", meters, cm, feet, inches);
    menu();
}

void convert_weights(void)
{
    int weight_choice;
    printf("You have chosen weights. Do you want to convert weights (1) from pounds/ounces to kilograms/grams, (2) from kilograms/grams to pounds/ounces, or (0) quit? \n");
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
        exit(1);
    }
}

void weight_to_metric(void)
{
    int pounds, kilograms;
    double ounces, grams;
    
    input_weight_to_metric(&pounds, &ounces);
    calculate_weight_to_metric(pounds, ounces, &kilograms, &grams);
    output_weight_to_metric(pounds, ounces, kilograms, grams);
}

void input_weight_to_metric(int* pounds, double* ounces)
{
    int noc;
    
    printf("Pounds: ");
    noc = scanf("%d", pounds);
    clear_keyboard_buffer();

    while (noc != 1 || pounds < 0)
    {
        printf("Please enter a valid amount for pounds: ");
        noc = scanf("%d", pounds);
        clear_keyboard_buffer();
    }

    printf("Ounces: ");
    noc = scanf("%lf", ounces);
    clear_keyboard_buffer();

    while (noc != 1 || ounces < 0)
    {
        printf("Please enter a valid amount for ounces: ");
        noc = scanf("%lf", ounces);
        clear_keyboard_buffer();
    }

}

void calculate_weight_to_metric(int pounds, double ounces, int* pKilograms, double* pGrams)
{
    double total_pounds = pounds + ounces * OUNCES_TO_POUNDS;
    double total_kilograms = total_pounds / POUNDS_TO_KILOGRAMS;
    
    *pKilograms = floor(total_kilograms);
    *pGrams = (total_kilograms - *pKilograms) * KILOGRAMS_TO_GRAMS;
}

void output_weight_to_metric(int pounds, double ounces, int kilograms, double grams)
{
    printf("The value %d pounds and %.2f ounces in the metric system is %d kilograms and %.2f grams.\n", pounds, ounces, kilograms, grams);
    menu();
}

void weight_to_us(void)
{
    int pounds, kilograms;
    double ounces, grams;
    
    input_weight_to_us(&kilograms, &grams);
    calculate_weight_to_us(kilograms, grams, &pounds, &ounces);
    output_weight_to_us(kilograms, grams, pounds, ounces);
}

void input_weight_to_us(int* kilograms, double* grams)
{
    int noc;
    printf("Kilograms: ");
    noc = scanf("%d", kilograms);
    clear_keyboard_buffer();
    
    while (noc != 1 || kilograms < 0)
    {
        printf("Please enter a valid amount for kilograms: ");
        noc = scanf("%d", kilograms);
        clear_keyboard_buffer();
    }
    
    printf("Grams: ");
    noc = scanf("%lf", grams);
    clear_keyboard_buffer();
    
    while (noc != 1 || grams < 0)
    {
        printf("Please enter a valid amount for grams: ");
        noc = scanf("%lf", grams);
        clear_keyboard_buffer();
    }
    
}

void calculate_weight_to_us(int kilograms, double grams, int* pPounds, double* pOunces)
{
    double total_kilograms = kilograms + grams / KILOGRAMS_TO_GRAMS;
    double total_pounds = total_kilograms * POUNDS_TO_KILOGRAMS;
    
    *pPounds = floor(total_pounds);
    *pOunces = (total_pounds - *pPounds) / OUNCES_TO_POUNDS;
}

void output_weight_to_us(int kilograms, double grams, int pounds, double ounces)
{
    printf("The value %d kilograms and %.2f grams in the metric system is %d pounds and %.2f ounces.\n", kilograms, grams, pounds, ounces);
    menu();
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

