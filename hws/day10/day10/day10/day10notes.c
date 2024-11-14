
#include <stdio.h>

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
/*
{
    int x;
    int y;
    int noc; // number of (successful) conversions
    
    noc = scanf("%d, %d", &x, &y); // scanf is still doing its job, when it finishes, it's going to return the noc to us.
    
    printf("The value of x is %d\n", x);
    printf("The value of y is %d\n", y);
    printf("The value of noc is %d\n", noc);
    return 0;
}

 here's another!
 
{
    double x = 66.0;
    int noc;
    
    printf("Please enter the desired temperature :");
    scanf("%lf", &x); //lf = longfloat
    clear_keyboard_buffer();
    
    while (noc != 1 || x < 65.0 || x > 67.0)
    {
        printf("Temperature value is out of the accepted range.\n");
        printf("Please enter the desired temperature :");
        noc = scanf("%lf", &x);
        clear_keyboard_buffer();

    }
    
    return 0;
    
}

void clear_keyboard_buffer1(void)
{
    char c;
    scanf("%c", &c);
    while (c != 'n')
    {
        scanf("%c", &c);
    }
}


{
    char grade;
    printf("Please enter the letter grade that you made on the last quiz: ");
    scanf(" %c", &grade);
    
    if (grade == 'A' || grade == 'a') // need to put grade again to avoid a totology
    {
        printf("Good job!\n");
    }
    else if (grade == 'B')
    {
        printf("So close, but so far...\n");
    }
    else if (grade == 'C')
    {
        printf("Perfectly average.\n");
    }
    else if (grade == 'D')
    {
        printf("Oh no....\n");
    }
    else if (grade == 'F')
    { // you don't need the braces if there is only one statement in the body
        printf("Have you considered majoring in business?\n");
    }
    else
    {
        printf("Did you even read the questions?\n");
    }
        
            // cascading ifs
        
    
}
*/

{
    int x = 0;
    
    2 + 2;
    x = x + 1;
    x += 1; // take value on left add to thing on right then put it back to the value on the left; shorter way of writing first assignment
    x++; // post increment operator; evaluates as a copy of the value of x before we change it.
    ++x; // pre increment operator; evaluates as x.
    
    // assignment evaluates as whatever was assigned
}

