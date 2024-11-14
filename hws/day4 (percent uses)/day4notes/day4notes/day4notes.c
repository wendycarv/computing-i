#include <stdio.h>

int main(int argc, char* argv[])

{
    printf("Hello %d World!\n", "hello!");
    
    /* %d (d for decimal) is a placeholder for the number or expression (an address) within parentheses after the comma */
    
    printf("Hello %d World!\n", 0);
    printf("Hello %c %c World\n", 'a', 'a' + 1);
    
    /* %c (c for character?). make sure you always use single quotes for single characters*/
    
    printf("Hello %f World\n", 6.02e23);
    
    /* %f (fixed notation - when you print it, i want to see the decimal places and 6 decimal places by default and not in scientific notation) e23 means exponent 23 */
    
    /* double percentage (%%) to display a single one*/
    /* if you want to see only a certain amount of decimal places, you can put %.xf:*/
    printf("Hello %.2f World\n", 0.1);
    
    /* since 0.1 is an infinitely repeating decimal #, computers don't have enough memory to keep going, has to stop number, so with fixed point notations for a floating point number you have to assume the #s are merely approximations. for example, the following # is wrong:*/
    
    printf("Hello %.20f World\n", 0.1);
    
    printf("Hello %e World\n", 0.1e23);
    
    /* Here you have another floating point # but in exponential form*/
    
    printf("Hello %g class\n", 0.023e23);
    
    /* Here you have a general placeholder that will cut off trailing zeros */
    printf("%d is an integer and should be printed using %%c", 42, 'd');
    
    printf("The character '%c' can be printed using %%c", 'J', 'd');
    return 0;
}

