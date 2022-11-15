#include "censure.h"
// Function to censure the bad words who return a string with the bad words censured
char *censure(char *str, char *bad_words[], int nb_bad_words)
{
    char *censured_str = malloc(sizeof(char) * strlen(str));
    char *token = strtok(str, " ");
    int i = 0;
    while (token != NULL)
    {
        int is_bad_word = 0;
        for (int j = 0; j < nb_bad_words; j++)
        {
            if (strcmp(token, bad_words[j]) == 0)
            {
                is_bad_word = 1;
                break;
            }
        }
        if (is_bad_word)
        {
            for (int j = 0; j < strlen(token); j++)
            {
                censured_str[i] = '*';
                i++;
            }
        }
        else
        {
            for (int j = 0; j < strlen(token); j++)
            {
                censured_str[i] = token[j];
                i++;
            }
        }
        censured_str[i] = ' ';
        i++;
        token = strtok(NULL, " ");
    }
    censured_str[i] = '\0';
    return censured_str;
}
