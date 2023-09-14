#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO:

/*
1. Append user text input properly
2. Add newline command
3. 
*/

int main() {

    int commandType;

    char userInput[100];
    char userText[100];

    int textLength = 0;
    int nullPointer = 0;

    bool loopBreaker = true;
    while (loopBreaker)
    {
        printf("\nChoose a command:\n");
        scanf_s("%d", &commandType);

        switch (commandType) {
        case 1:

            printf("Enter text to append:");
            fgets(userInput, sizeof(userInput), stdin);

            if (textLength + strlen(userInput) <= 100) {
                strcat(userText, userInput);
                textLength += strlen(userInput);
            }

            //scanf_s("%99s", userInput, sizeof(userInput));

            printf("Text appended successfully: ");
            printf("%s", userInput);


            break;
        case 2:
            //untested
            for (int i = 0; i < sizeof(userInput); ++i) {
                if (userInput[i] == '\0') {
                    nullPointer = i;
                    break;
                }
            }

            userInput[nullPointer] = '\n';
            //strcat(userInput, '\0');

            break;
        case 3:
            printf("Command not implemented yet.");
        case 4:
            printf("Command not implemented yet.");
        case 5:

            for (int i = 0; i < sizeof(userInput); ++i) {
                printf("%c", userInput[i]);

                if (userInput[i] == '\0') {
                    break;
                }
            }
            break;
        case 6:
            printf("Command not implemented yet.");
            break;
        case 7:
            printf("Command not implemented yet.");
            break;
        case 8:
            loopBreaker = false;
            break;
        default:
            printf("Yea no I don't know that command.\n");
            break;
        }
    }

    return 0;
}

//char *userTextInput;
//char arrCapacity = 100;
//int arrSize = 0;
//userTextInput = (char *) malloc(arrCapacity * sizeof(char));


/*
            if (strlen(userTextInput) >= arrCapacity / 2) {
                arrCapacity *= 2;
                userTextInput = (char *) realloc(userTextInput, arrCapacity * sizeof(char));
            }

            scanf_s("%99s", &userTextInput, sizeof(userInput));
            //printf("Your text: ", userInput);

            //strcat(userTextInput, userInput);
            //arrSize = strlen(userTextInput); //don't know why this is flagged as a warning
            */