/*
Author: NEROT Romain
Date: 01/11/2022
Description: This program is a chat who censure the bad words
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censure.h"

int main(int argc, char const *argv[])
{
    // Initialize variables
    int choice;         // Choice of the user in the menu
    int menu = 1;       // Menu loop
    char sentence[255]; // sentence of the user
    char username[25];  // Username of the user
    char badword[25];   // Bad word of the user
    char **list = NULL; // List of bad words
    int i = 0;          // Loop variable

    do // Do while the user don't want to exit
    {

        // Display menu
        printf("\n\nWelcome to the chat censor program\n\n");
        printf("Please choose an option:\n");
        printf("1. Use the chat\n");
        printf("2. Censor a word\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        fflush(stdin);

        // Switch case to choose the option
        switch (choice)
        {
        case 1: // Use the chat
            printf("\nYou choose to use the chat\n");
            printf("Please enter your username:\n");
            scanf("%s", &username);
            fflush(stdin);

            printf("\nUse \"exit\" to leave the chat\n");
            printf("Please enter your message:\n");
            do // Loop for write into the chat
            {
                printf("\n");
                gets(sentence);
                fflush(stdin);
                if (sentence != "exit")
                {
                    printf("%s: %s", username, censure(sentence, list, i));
                }
            } while (strcmp(sentence, "exit") != 0); // Exit the loop if the user write "exit"
            printf("\n%s left the chat\n", username);
            choice = 0; // Reset the choice
            break;

        case 2: // Censor a word
            printf("You choose to censor a word\n");

            // Add a word to a censored list
            printf("Please enter the word you want to censor:\n");
            scanf("%s", &badword);
            fflush(stdin);
            list = realloc(list, (i + 1) * sizeof(char *));
            list[i] = malloc(strlen(badword) + 1);
            strcpy(list[i], badword);
            printf("The word \"%s\" is now censored\n", badword);
            i++;
            choice = 0; // Reset the choice
            break;

        case 3: // Exit
            printf("You have exited the program\n");
            // display the censored list
            printf("The censored list is:\n");
            for (int j = 0; j < i; j++)
            {
                printf("%s\n", list[j]);
            }
            menu = 0; // Exit the menu loop
            break;

        default: // If the user enter a wrong number
            printf("Please enter a valid number\n");
            break;
        }
    } while (menu != 0); // Exit the loop if the user choose the option 3

    return 0;
}
