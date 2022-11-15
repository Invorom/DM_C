#include "censure.h"

// Function to censure the bad words who return a string with the bad words censured
char *censure(char *str, char *bad_words[], int nb_bad_words)
{
    char *censured_str = malloc(sizeof(char) * strlen(str));
    char *token = strtok(str, " ");
    char lower_token[25];

    int i = 0;
    while (token != NULL)
    {
        int is_bad_word = 0;

        // lowerToken
        strcpy(lower_token, token);
        for (int j = 0; lower_token[j] != '\0'; j++)
        {
            lower_token[j] = tolower(lower_token[j]);
        }

        // Check if the token is a bad word but works
        for (int j = 0; j < nb_bad_words; j++)
        {
            if (strcmp(lower_token, bad_words[j]) == 0)
            {
                is_bad_word = 1;
                break;
            }
        }

        // Censure the token
        if (is_bad_word == 1)
        {
            for (int j = 0; token[j] != '\0'; j++)
            {
                censured_str[i] = '*';
                i++;
            }
        }
        else
        {
            for (int j = 0; token[j] != '\0'; j++)
            {
                censured_str[i] = token[j];
                i++;
            }
        }

        // Add a space
        censured_str[i] = ' ';

        // Next token
        token = strtok(NULL, " ");
        i++;
    }
    censured_str[i] = '\0';
    return censured_str;
}
