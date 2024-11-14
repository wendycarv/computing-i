#include <stdio.h>

int joe(void)
{
    printf("Hello from joe\n");
    joe(); /* every time joe calls himself, it's a NEW joe. it isn't the same one. infinite recursion due to stack overflow (when a function calls itself*/
    return 0;
}

int main(int argc, char* argv [])
{
    joe();
    printf("Hello from main\n");
    return 0;
}
