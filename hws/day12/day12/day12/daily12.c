/*
 
 Author: Wendy Carvalho
 Date: 10/04/2022
 
 Purpose: This program runs a game of rock, paper, scissors and takes input from the two players.
 Time Spent: About a day.
 
 */

#include <stdio.h>

void player2_turn(char player_2);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[])
{

    char player_1;
    char player_2;
    char choice;
    
    do {
        printf("Player 1 it is your turn!\n");
        printf("Please choose (r)ock, (p)aper, or (s)cissors: \n");
        scanf(" %c", &player_1);
        clear_keyboard_buffer();

        while (player_1 != 's' && player_1 != 'S' && player_1 != 'p' && player_1 != 'P' && player_1 != 'r' && player_1 != 'R')
        {
            printf("I'm sorry, but you must enter 'r', 'p', or 's'\n");
            printf("Please choose (r)ock, (p)aper, or (s)cissors: \n");
            scanf(" %c", &player_1);
            clear_keyboard_buffer();

        }
    
        printf("Player 2 it is your turn!\n");
        printf("Please choose (r)ock, (p)aper, or (s)cissors: \n");
        scanf(" %c", &player_2);
        clear_keyboard_buffer();
        
        while (player_2 != 's' && player_2 != 'S' && player_2 != 'p' && player_2 != 'P' && player_2 != 'r' && player_2 != 'R')
        {
            printf("I'm sorry, but you must enter 'r', 'p', or 's'\n");
            printf("Please choose (r)ock, (p)aper, or (s)cissors: \n");
            scanf(" %c", &player_2);
            clear_keyboard_buffer();
        }
        
        switch (player_1)
        {
            case 'r':
            case 'R':
                if (player_2 == 's' || player_2 == 'S')
                {
                    printf("Rock breaks scissors. Player 1 wins!\n");
                }
                else if (player_2 == 'r' || player_2 == 'R')
                {
                    printf("Draw, nobody wins.\n");
                }
                else if (player_2 == 'p' || player_2 == 'P')
                {
                    printf("Paper covers rock. Player 1 wins!\n");
                }
                break;
            case 'p':
            case 'P':
                if (player_2 == 's' || player_2 == 'S')
                {
                    printf("Scissors cut paper. Player 2 wins!\n");
                }
                else if (player_2 == 'r' || player_2 == 'R')
                {
                    printf("Paper covers rock. Player 1 wins!\n");
                }
                else if (player_2 == 'p' || player_2 == 'P')
                {
                    printf("Draw, nobody wins.\n");
                }
                else
                {
                    printf("I'm sorry, but you must enter 'r', 'p', or 's'\n");
                    printf("Please choose (r)ock, (p)aper, or (s)cissors: \n");
                    scanf(" %c", &player_2);
                    clear_keyboard_buffer();
                }
                break;
            case 's':
            case 'S':
                if (player_2 == 's' || player_2 == 'S')
                {
                    printf("Draw, nobody wins.\n");
                }
                else if (player_2 == 'r' || player_2 == 'R')
                {
                    printf("Rock breaks scissors. Player 2 wins!\n");
                }
                else if (player_2 == 'p' || player_2 == 'P')
                {
                    printf("Scissors cut paper. Player 1 wins!\n");
                }
                else
                {
                    printf("I'm sorry, but you must enter 'r', 'p', or 's'\n");
                    printf("Please choose (r)ock, (p)aper, or (s)cissors: \n");
                    scanf(" %c", &player_2);
                    clear_keyboard_buffer();

                }
                break;
        }
        printf("Do you wish to continue? (y/n):\n");
        scanf(" %c", &choice);
        clear_keyboard_buffer();

        while (choice != 'Y' && choice != 'y' && choice != 'n' && choice != 'N')
                {
                    printf("I'm sorry but I do not understand. Please choose y/n.\n");
                    scanf(" %c", &choice);
                    clear_keyboard_buffer();
                }
                
                if (choice == 'n'|| choice == 'N')
                {
                    return 1;
                }

    } while (choice == 'y' || choice == 'Y');
    
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
