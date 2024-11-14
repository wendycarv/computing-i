#include <stdio.h>

int main (int argc, char* argv[])
{
    int x;
    /* three rules for making a valid identifier:
    1. the name must begin with a letter or an _ (but don't do that cause it's dumb)
    2. it can have any number of letters, underscores, or digits in it
    3. cannot be a keyword (int, return...)
     */
    x = 42;
    x = x + 1;
    
    scanf("%d", &x);
    /* if you put just "x", only the value of the COPY of x is going to be changed, nothing will happen to the actual x. when you put &, it puts the address of x
     scanf: changes the value of the variable because it knows its address
     */
    
    printf("%d\n", x);
    scanf("%d", &x);
    printf("%d\n", x);

    return 0;
}

/* number letter (37 J)
   number
   number
 
   letter number (J 37)
   
 */

