#include "write.h"

// Function to write a sentence into the chat
void writeSentence(char *sentence, char *username, char **list, int i)
{
    printf("\n");
    printf("\nWrite here: ");
    fgets(sentence, 255, stdin);
    sentence[strlen(sentence) - 1] = '\0';
    for (int j = 0; sentence[j] != '\0'; j++)
    {
        sentence[j] = tolower(sentence[j]);
    }
    if (strcmp(sentence, "exit") == 0)
        return;
    printf("%s: %s", username, censure(sentence, list, i));
}
