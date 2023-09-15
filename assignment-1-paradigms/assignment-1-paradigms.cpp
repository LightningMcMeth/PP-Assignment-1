#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO:

/*
1. Append user text input properly
2. Add newline command
3. 

https://www.youtube.com/watch?v=wL2FHiBSh2E&ab_channel=UBCECESS
*/

int main() {

    int commandType = 0;
    int* pcommandType = &commandType;

    char userInput[100] = "";
    char userText[100] = "";

    int textLength = 0;

    while (1)
    {
        printf("\nChoose a command:\n");
        scanf_s("%d", &commandType);

        switch (*pcommandType){
        case 1:

            printf("Enter text to append:");
            fgets(userInput, sizeof(userInput), stdin);



            if (textLength + atoi(userInput) <= 100) {
                strcat_s(userText, userInput);
                textLength += strlen(userInput);
            }
            else {
                printf("\ncringe\n");
            }

            printf("\nText appended successfully: ");
            printf("%s", userInput);

            break;
        case 2:
            printf("Command not implemented yet.");
            break;
        case 3:
            printf("Command not implemented yet.");
            break;
        case 4:
            printf("Command not implemented yet.");
            break;
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