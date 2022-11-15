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
    int censorChoice;   // Choice of the user in the censor menu
    int menu = 1;       // Menu loop
    int censorMenu;     // Censor menu loop
    char sentence[255]; // sentence of the user
    char username[25];  // Username of the user
    char badword[25];   // Bad word of the user
    char **list = NULL; // List of bad words
    int i = 0;          // Loop variable

    printf("____________________________________________\n");
    printf("|Welcome  to   the   chat  censor   program|\n");
    printf("|__________________________________________|\n");

    do // Do while the user don't want to exit
    {

        censorMenu = 1; // Reset the censorMenu loop

        // Display menu
        printf("\n--------------------MENU--------------------\n");
        printf("Please choose an option:\n");
        printf("1. Use the chat\n");
        printf("2. Censor a word\n");
        printf("3. Exit\n");
        scanf("%d", &choice);
        fflush(stdin);
        printf("--------------------------------------------\n");

        // Switch case to choose the option
        switch (choice)
        {
        case 1: // Use the chat
            printf("\n--------------------CHAT--------------------\n");
            printf("Please enter your username:\n");
            scanf("%s", &username);
            fflush(stdin);

            printf("____________________________________________\n");
            printf("|   /!\\ Use \"exit\" to leave the chat /!\\   |\n");
            printf("|__________________________________________|\n");
            do // Loop for write into the chat
            {
                printf("\n");
                printf("\nWrite here: "), gets(sentence);
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
            do
            {
                // Choose if the user want to add or remove a bad word
                printf("\n-------------------CENSOR-------------------\n");
                printf("Please choose an option:\n");
                printf("1. Add a bad word\n");
                printf("2. Remove a bad word\n");
                printf("3. See the list of bad words\n");
                printf("4. Back to the menu\n");
                scanf("%d", &censorChoice);
                fflush(stdin);
                printf("--------------------------------------------\n");

                // Switch case to choose the option
                switch (censorChoice)
                {
                case 1: // Add a bad word
                        // Add a word to a censored list
                    printf("Please enter the word you want to censor:\n");
                    scanf("%s", &badword);
                    fflush(stdin);
                    list = realloc(list, (i + 1) * sizeof(char *));
                    list[i] = malloc(strlen(badword) + 1);
                    strcpy(list[i], badword);
                    printf("\nThe word \"%s\" is now censored\n", badword);
                    i++;
                    censorChoice = 0; // Reset the censorChoice
                    break;

                case 2: // Remove a bad word
                        // Remove a word from a censored list
                    printf("Please enter the word you want to uncensor:\n");
                    scanf("%s", &badword);
                    fflush(stdin);
                    for (int j = 0; j < i; j++)
                    {
                        if (strcmp(list[j], badword) == 0)
                        {
                            free(list[j]);
                            list[j] = list[i - 1];
                            i--;
                            printf("\nThe word \"%s\" is now uncensored\n", badword);
                        }
                    }
                    censorChoice = 0; // Reset the censorChoice
                    break;

                case 3: // See the list of bad words
                    // Display the list of bad words
                    if (list == NULL)
                    {
                        printf("Sorry, it's empty here\n");
                    }
                    else
                    {
                        printf("The list of bad words is:\n");
                        for (int j = 0; j < i; j++)
                        {
                            printf("%d. %s\n", j + 1, list[j]);
                        }
                    }
                    censorChoice = 0; // Reset the censorChoice
                    break;

                case 4: // Back to the menu
                    censorMenu = 0;
                    break;

                default: // If the user enter a wrong censorChoice
                    printf("Please enter a valid number\n");
                    censorChoice = 0; // Reset the censorChoice
                    break;
                }
            } while (censorMenu != 0);

            choice = 0; // Reset the choice
            break;

        case 3: // Exit
            printf("\nYou have exited the program\n");
            menu = 0; // Exit the menu loop
            break;

        default: // If the user enter a wrong number
            printf("Please enter a valid number\n");
            choice = 0; // Reset the choice
            break;
        }
    } while (menu != 0); // Exit the loop if the user choose the option 3

    return 0;
}
