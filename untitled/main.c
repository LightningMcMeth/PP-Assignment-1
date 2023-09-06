#include <stdio.h>

int main() {

    int commandType;
    char userTextInput[100];

    printf("Choose a command:\n");
    scanf_s("%i", &commandType);

    switch (commandType){
        case 1:
            printf("Enter text to append:");
            scanf_s("%99s", &userTextInput, sizeof(userTextInput));
            break;
        case 2:
            printf("Command not implemented yet.");
        case 3:
            printf("Command not implemented yet.");
        case 4:
            printf("Command not implemented yet.");
        case 5:
            for (int i = 0; i < sizeof(userTextInput); ++i) {
                printf("%c", userTextInput[i]);
                if(userTextInput[i]=='\0')
                {
                    break;
                }
            }
            break;
        case 6:
            printf("Command not implemented yet.");
        case 7:
            printf("Command not implemented yet.");
        default:
            printf("Yea no I don't know that command.\n");
    }

    return 0;
}
