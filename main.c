/*
Author: NEROT Romain
Date: 01/11/2022
Description: This program is a chat who censure the bad words
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "censure.h"
#include "write.h"

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
    char *p, s[100];    // Variables for the fgets

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
        while (fgets(s, sizeof(s), stdin))
        {
            choice = strtol(s, &p, 4);
            if (p == s || *p != '\n')
            {
                printf("Please enter a number between 1 and 3: ");
            }
            else
                break;
        }
        fflush(stdin);
        printf("--------------------------------------------\n");

        // Switch case to choose the option
        switch (choice)
        {
        case 1: // Use the chat
            printf("\n--------------------CHAT--------------------\n");
            printf("Please enter your username:\n");
            scanf("%s", username);
            fflush(stdin);

            printf("____________________________________________\n");
            printf("|   /!\\ Use \"exit\" to leave the chat /!\\   |\n");
            printf("|__________________________________________|\n");
            do // Loop for write into the chat
            {
                writeSentence(sentence, username, list, i);
            } while (strcmp(sentence, "exit") != 0); // Exit the loop if the user write "exit"
            printf("\n\n%s left the chat\n", username);
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
                while (fgets(s, sizeof(s), stdin))
                {
                    censorChoice = strtol(s, &p, 5);
                    if (p == s || *p != '\n')
                    {
                        printf("Please enter a number between 1 and 4: ");
                    }
                    else
                        break;
                }
                printf("--------------------------------------------\n");

                // Switch case to choose the option
                switch (censorChoice)
                {
                case 1: // Add a bad word
                    // Ask the user to enter a bad word
                    printf("Please enter the word you want to censor:\n");
                    fgets(badword, 25, stdin);
                    badword[strlen(badword) - 1] = '\0';
                    fflush(stdin);

                    // Keep only the first word of badword
                    char *token = strtok(badword, " ");
                    strcpy(badword, token);

                    // Transform the badword in lower case
                    for (int j = 0; badword[j] != '\0'; j++)
                    {
                        badword[j] = tolower(badword[j]);
                    }

                    // Add the bad word to the list if it's not already in the list without function
                    if (i == 0)
                    {
                        list = malloc(sizeof(char *));
                        list[i] = malloc(sizeof(char) * strlen(badword));
                        strcpy(list[i], badword);
                        printf("\nThe word \"%s\" has been censored\n", badword);
                        i++;
                    }
                    else
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if (strcmp(list[j], badword) == 0 || strcmp(badword, "exit") == 0)
                            {
                                printf("\nThe word \"%s\" is already censored\n", badword);
                                break;
                            }
                            else if (j == i - 1)
                            {
                                list = realloc(list, sizeof(char *) * (i + 1));
                                list[i] = malloc(sizeof(char) * strlen(badword));
                                strcpy(list[i], badword);
                                printf("\nThe word \"%s\" has been censored\n", badword);
                                i++;
                                break;
                            }
                        }
                    }
                    censorChoice = 0; // Reset the censorChoice
                    break;

                case 2: // Remove a bad word
                    // Remove a word from a censored list
                    if (list == NULL || i == 0)
                    {
                        printf("Sorry, you can't delete the void\n");
                    }
                    else
                    {
                        printf("Please enter the word you want to uncensor:\n");
                        fgets(badword, 25, stdin);
                        badword[strlen(badword) - 1] = '\0';
                        fflush(stdin);

                        // Keep only the first word of badword
                        char *token = strtok(badword, " ");
                        strcpy(badword, token);

                        // Transform the badword in lower case
                        for (int j = 0; badword[j] != '\0'; j++)
                        {
                            badword[j] = tolower(badword[j]);
                        }

                        // Check if the word is'nt already in the list
                        for (int j = 0; j < i; j++)
                        {
                            if (strcmp(list[j], badword) == 0)
                            {
                                free(list[j]);
                                list[j] = list[i - 1];
                                i--;
                                printf("\nThe word \"%s\" is now uncensored\n", badword);
                                break;
                            }
                            else if (j == i - 1)
                            {
                                printf("\nSorry, the word \"%s\" is not in the list\n", badword);
                            }
                        }
                    }
                    censorChoice = 0; // Reset the censorChoice
                    break;

                case 3: // See the list of bad words
                    // Display the list of bad words
                    if (list == NULL || i == 0)
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
                    choice = 0; // Reset the choice
                    break;

                default: // If the user enter a wrong censorChoice
                    printf("Please enter a number between 1 and 4: ");
                    censorChoice = 0; // Reset the censorChoice
                    break;
                }
            } while (censorMenu != 0);

            choice = 0; // Reset the choice
            break;

        case 3: // Exit
            printf("\nYou left the program\n");
            menu = 0; // Exit the menu loop
            break;

        default: // If the user enter a wrong number
            printf("Please enter a number between 1 and 3: ");
            choice = 0; // Reset the choice
            break;
        }
    } while (menu != 0); // Exit the loop if the user choose the option 3

    return 0;
}
