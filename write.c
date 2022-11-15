#include "write.h"

// Function to write a sentence into the chat
void writeSentence(char *sentence, char *username, char **list, int i, int test)
{
    printf("\n");
    if (test != 0)
        printf("\nWrite here: ");

    fgets(sentence, 255, stdin);
    sentence[strlen(sentence) - 1] = '\0';
    if (strcmp(sentence, "exit") == 0)
        return;
    printf("%s: %s", username, censure(sentence, list, i));
}
