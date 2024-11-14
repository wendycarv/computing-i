/*
    Author: Wendy Carvalho
    Date: 10/06/2022
 
    Purpose: This program is another version of rock, paper, scissors, but this time it uses a function to hold the value of the players' choices (rock, paper, or scissors).
 
    Time spent: About two hours.

 */


#include <stdio.h>

enum choice {ROCK, PAPER, SCISSORS};

typedef enum choice Choice;

Choice get_player_choice(void);

void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{
    Choice p1;
    Choice p2;
    char replay = 'y';
    
    while (replay == 'y' || replay == 'Y')
    {
        printf("Player 1, it is your turn\n");
        p1 = get_player_choice();
        
        printf("Player 2, it is your turn\n");
        p2 = get_player_choice();
        
        switch (p1)
        {
            case 0:
                switch (p2)
                {
                    case 0:
                    printf("Draw, nobody wins\n");
                    break;
                    case 1:
                    printf("Paper covers rock. Player 2 wins\n");
                    break;
                    case 2:
                    printf("Rock breaks scissors. Player 1 wins\n");
                    break;
                }
            break;
            case 1:
                switch (p2)
                {
                    case 0:
                    printf("Paper covers rock. Player 1 wins\n");
                    break;
                    case 1:
                    printf("Draw, nobody wins\n");
                    break;
                    case 2:
                    printf("Scissors cut paper. Player 2 wins\n");
                    break;
                }
                break;
            case 2:
                switch (p2)
                {
                    case 0:
                    printf("Rock breaks scissors. Player 2 wins\n");
                    break;
                    case 1:
                    printf("Scissors cut paper. Player 1 wins\n");
                    break;
                    case 2:
                    printf("Draw, nobody wins\n");
                    break;
                }
            break;
        }
        printf("Do you wish to continue? (y/n):\n");
        scanf(" %c", &replay);
        clear_keyboard_buffer();
        
        while (replay != 'y' && replay != 'Y' && replay != 'n' && replay != 'N')
        {
            printf("Please enter a valid answer (y/n): \n");
            scanf(" %c", &replay);
            clear_keyboard_buffer();
        }
    }
    return 0;
}

enum choice get_player_choice(void)
{
    char c;
    printf("Please enter your choice of (p)aper, (r)ock, or (s)cissors: \n");
    scanf(" %c", &c);
    clear_keyboard_buffer();
    
    while(c != 'r' && c != 'R' && c != 'p' && c != 'P' && c != 's'&& c != 'S')
    {
        printf("I'm sorry but I do not understand.\n");
        printf("Please enter your choice of (p)aper, (r)ock, or (s)cissors: \n");
        scanf(" %c", &c);
        clear_keyboard_buffer();

    }
    
    if (c == 'r' || c == 'R')
    {
        return ROCK;
    }
    
    if (c == 'p' || c == 'P')
    {
        return PAPER;
    }
    
    if (c == 's' || c == 'S')
    {
        return SCISSORS;
    }
    
    return 0;
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
