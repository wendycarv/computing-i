#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* read_string(FILE* fp, char word[], int size);
char* combine_names(char first[], char last[], char full[], int size); // every array in this has the size 21

#define SIZE (21) // allows you to have 20 characters + the null terminator

int main(int argc, char* argv[])
{
    FILE* fp;
    char file_name[] = "/Users/wendylima/Documents/school/uml fall 2022/comp1010/day19/day19/day19/names.txt";
    char first_name[SIZE];
    char last_name[SIZE];
    char full_name[SIZE];
    
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf("Failed to open file %s\n", file_name);
        exit(1);
    }
    
    while(read_string(fp, first_name, SIZE))
    {
        read_string(fp, last_name, SIZE);
        printf("%-20s ****\n", combine_names(first_name, last_name, full_name, SIZE));
    }
    
    printf("%s\n", first_name);
    
    return 0;
}

char* read_string(FILE* fp, char word[], int size)
{
    int noc;
    char c;
    int i = 0;
    
    //ignore leading whitespace
    noc = fscanf(fp, " %c", &c); //by putting a space before %c, he'll skip over all leading blanks. noc will either get something or not. it will only fail if it finds the EOF
    if (noc != 1 || size < 2) //if the size is less than two, it can't hold a string (user has given us buffer that is too small)
    {
        if (noc == 1) //if it failed because of the size
        {
            ungetc(c, fp); //let that shit go
        }
        return NULL;
    }
    
    //if you got past the if statement, then you did get something you want to put
    word[i] = c;
    i++;
    
    //keep reading characters until we encounter a whitespace character or we hit end of file
    noc = fscanf(fp, "%c", &c);
    while (noc == 1 && !isspace(c) && i < size - 1) //i picked up something. if i want it and i have space for it in the buffer then.....
    {
        word[i] = c;
        i++;
        noc = fscanf(fp, "%c", &c);
    }
    
    if (noc == 1)
    {
        ungetc(c, fp);
    }
    
    word[i] = '\0';
    return word;
}

char* combine_names(char first[], char last[], char full[], int size)
{
    int i = 0;
    int j = 0;
    while(first[i] != '\0' && i < size - 1)
    {
        full[i] = first[i];
        i++;
    }
    
    if (i < size -1)
    {
        full[i] = ' ';
        i++;
    }
    
    while(last[j] != '\0' && i < size - 1)
    {
        full[i] = last[j];
        i++;
        j++;
    }
 
    full[i] = '\0';
    return full;
}
