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
    
    char file_one[] = "numbers1.txt";
    char file_two[] = "numbers2.txt";
    char file_output[] = "output.txt";
    
    fp = fopen(file_one, "r");
    if (fp == NULL)
    {
        printf("Failed to open file numbers1.txt\n");
        exit(1);
    }
    
    FILE* fp2;
    fp2 = fopen(file_two, "r");
    if (fp2 == NULL)
    {
        printf("Failed to open file numbers2.txt\n");
        exit(1);
    }
    
    FILE* fp3;
    fp3 = fopen(file_output, "w");
    if (fp3 == NULL)
    {
        printf("Failed to open file output.txt\n");
        exit(1);
    }

    output(fp, fp2, fp3);
    
    fclose(fp);
    fclose(fp2);
    fclose(fp3);
    
    return 0;
}

void output(FILE* a, FILE* b, FILE* c)
{
    int number_a;
    int number_b;
    int noc_a = 1;
    int noc_b = 1;

    noc_a = fscanf(a, "%d", &number_a);
    noc_b = fscanf(b, "%d", &number_b);

    while (noc_a == 1 && noc_b == 1)
    {
        if (number_a >= number_b)
        {
            fprintf(c, "%d\n", number_b);
            noc_b = fscanf(b, "%d", &number_b);
        }
                
        else
        {
            fprintf(c, "%d\n", number_a);
            noc_a = fscanf(a, "%d", &number_a);
        }
    }
    
    if (noc_a != 1)
    {
        while(noc_b == 1)
        {
            fprintf(c, "%d\n", number_b);
            noc_b = fscanf(b, "%d", &number_b);
        }
    }
    
    if (noc_b != 1)
    {
        while(noc_a == 1)
        {
            fprintf(c, "%d\n", number_a);
            noc_a = fscanf(a, "%d", &number_a);
        }
    }
}
