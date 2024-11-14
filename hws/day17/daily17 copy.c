/*
    Author: Wendy Carvalho
    Date: 11/14/2022
 
    Purpose: The purpose of this program is to create three files with numbers, the third one being a combination of the first one, creating a list of the numbers in ascending order and no repeats.
 
    Sources of help: Stackoverflow.com, Geeksforgeeks.com, and classmates
 
    Time spent: 4 hours

 */

#include <stdio.h>
#include <stdlib.h>

// Precondition: The files need to exist and not be null.
// Postconditon: Numbers in the files will be evaluated and be printed in order from least to greatest.
void output(FILE* a, FILE* b, FILE* c);

int main(int argc, char* argv[])
{
    FILE* fp;
    int x = 1;
    
    fp = fopen("numbers1.txt", "w");
    
    if (fp == NULL)
    {
        printf("Failed to open file numbers1.txt\n");
        exit(1);
    }
 
    while (x < 10)
    {
        fprintf(fp, "%d\n", x);
        x+= 2;
    }
    
    fclose(fp);
    
    /*/*/
    
    FILE* fp2;
    int y = 0;
    
    fp2 = fopen("numbers2.txt", "w");
    if (fp2 == NULL)
    {
        printf("Failed to open file numbers2.txt\n");
        exit(1);
    }
 
    while (y < 10)
    {
        fprintf(fp2, "%d\n", y);
        y += 2;
    }
    
    fclose(fp2);
    
    /*/*/
    
    FILE* fp3 = fopen("output.txt", "w");;
    
    fclose(fp3);

    output(fp, fp2, fp3);
    return 0;
}

void output(FILE* a, FILE* b, FILE* c)
{
    int number_a;
    int number_b;
    int noc_a = 1;
    int noc_b = 1;
    
    a = fopen("numbers1.txt", "r");
    b = fopen("numbers2.txt", "r");
    c = fopen("output.txt", "w");
  
    if (a == NULL || b == NULL || c == NULL)
    {
        printf("Failed to open numbers1.txt, numbers2.txt, or outputs.txt\n");
        exit (1);
    }
    
    noc_a = fscanf(a, "%d", &number_a);
    noc_b = fscanf(b, "%d", &number_b);

    if (feof(a))
    {
        while(noc_b == 1)
        {
            fprintf(c, "%d\n", number_b);
            noc_b = fscanf(b, "%d", &number_b);
        }
    }
    
    if (feof(b))
    {
        while(noc_a == 1)
        {
            fprintf(c, "%d\n", number_a);
            noc_a = fscanf(a, "%d", &number_a);
        }
    }
    
    while (noc_a == 1 && noc_b == 1)
    {
        if (number_b > number_a)
        {
            fprintf(c, "%d\n", number_a);
            noc_a = fscanf(a, "%d", &number_a);
        }
        
        if (feof(a))
        {
            while(noc_b == 1)
            {
                fprintf(c, "%d\n", number_b);
                noc_b = fscanf(b, "%d", &number_b);
            }
        }
        
        if (number_a > number_b)
        {
            fprintf(c, "%d\n", number_b);
            noc_b = fscanf(b, "%d", &number_b);
        }
        
        if (feof(b))
        {
            while(noc_a == 1)
            {
                fprintf(c, "%d\n", number_a);
                noc_a = fscanf(a, "%d", &number_a);
            }
        }
        
        if (number_a == number_b)
        {
            fprintf(c, "%d\n", number_a);
        }
        
    }
    
    fclose(a);
    fclose(b);
    fclose(c);
}
