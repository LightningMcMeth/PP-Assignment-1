#include <stdio.h>
#include <string.h>

int main() {

    int commandType;
    char userTextInput[100];
    int nullPointer = 0;
    //const int TextInputLimit;

    printf("Choose a command:\n");
    scanf_s("%i", &commandType);

    switch (commandType){
        case 1:

            printf("Enter text to append:");
            scanf_s("%99s", &userTextInput, sizeof(userTextInput));
            strcat(userTextInput, '\0');
            break;
        case 2:
            //untested
            for (int i = 0; i < sizeof(userTextInput); ++i)
            {
                if (userTextInput[i] == '\0')
                {
                    nullPointer = i;
                    break;
                }
            }

            userTextInput[nullPointer] = '\n';
            strcat(userTextInput, '\0');
        case 3:
            printf("Command not implemented yet.");
        case 4:
            printf("Command not implemented yet.");
        case 5:

            for (int i = 0; i < sizeof(userTextInput); ++i)
            {
                printf("%c", userTextInput[i]);

                if(userTextInput[i]=='\0')
                {
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
        default:
            printf("Yea no I don't know that command.\n");
            break;
    }

    return 0;
}
