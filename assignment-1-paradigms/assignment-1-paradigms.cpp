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

        getchar();

        switch (*pcommandType){
        case 1:
            
            printf("Enter text to append:");
            fgets(userInput, sizeof(userInput), stdin);

            if (textLength + atoi(userInput) <= 100) {
                textLength += strlen(userInput);

                userInput[textLength - 1] = '\0';

                strcat_s(userText, userInput);
            }
            else {
                printf("\ncringe\n");
                break;
            }

            printf("\nText appended successfully: ");
            printf("%s", userInput);

            break;
        case 2:

            for (int i = 0; i < sizeof(userText); ++i) {
                printf("%c", userText[i]);
            }

            break;
        case 3:
            
            if (textLength < 100) {
                userText[textLength - 1] = '\n';
            }

            printf("Newline added successfully.\n");

            break;
        case 4:
            
            FILE* file;
            file = fopen("userText.txt", "w");

            if (file != NULL) {
                fputs(userText, file);
                fclose(file);
            }
            printf("Text written to file successfully.\n");

            break;
        case 5:
            
            FILE* file;
            file = fopen("userText.txt", "r");

            if (file == NULL) {
                printf("Error opening file, or the file is empty.\n");
                break;
            }

            while (fgets(userInput, sizeof(userText), file) != NULL) {
                printf("%s", userInput);
            }
            printf("File read successfully.\n");

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
            printf("I don't know that command.\n");
            printf("List of valid commands:\n");
            printf(" 1. Append text.\n2.Print text.\n3.Add newline.\n4.Write to file.\n5.Read from file.")
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