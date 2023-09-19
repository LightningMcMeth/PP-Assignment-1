#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO:

/*
1. Test r/w
2. Add dynamic 2d array
3. insertion mechanism
4. substring search
https://www.youtube.com/watch?v=wL2FHiBSh2E&ab_channel=UBCECESS
*/

int main() {

    int commandType = 0;
    int* pcommandType = &commandType;

    char userInput[100] = "";
    char userText[100] = "";

    char** userTextD = (char**)calloc(1, sizeof(char*));    //rows
    for (int i = 0; i < 3; i++) //columns 
    {
        userTextD[i] = (char*)calloc(100, sizeof(char));
    }

    int textLength = 0;
    int textRow = 0;

    errno_t fileErr = 1;
    bool endOfName = false;
    char fileName[100];
    FILE* file;



    while (1)
    {
        printf("\nChoose a command:\n");
        scanf_s("%d", &commandType);

        getchar();

        switch (*pcommandType){
        case 1:
            
            printf("Enter text to append:");
            fgets(userInput, sizeof(userInput), stdin);

            /*
            if (textLength + atoi(userInput) <= 100) {
                textLength += strlen(userInput);

                userInput[textLength - 1] = '\0';

                strcat_s(userText, userInput);
            }
            else {
                printf("\ncringe\n");
                break;
            }
            */

            strcpy_s(userTextD[textRow], sizeof(userInput), userInput);

            printf("\nText appended successfully: ");
            printf("%s", userTextD[textRow]);

            break;
        case 2:

            for (int i = 0; i < sizeof(userText); ++i) 
            {
                printf("%c", userText[i]);
            }

            for (int i = 0; i < textRow + 1; i++)
            {
                for (int j = 0; j < 100; j++)
                {
                    printf("%c", userTextD[i][j]);
                }
            }

            break;
        case 3:
            
            if (textLength < 100) {
                userText[textLength - 1] = '\n';
            }

            printf("Newline added successfully.\n");

            break;
        case 4:

            printf("Enter the file name: ");
            fgets(fileName, sizeof(fileName), stdin);

            if (strlen(fileName) > 0 && fileName[strlen(fileName) - 1] == '\n') {
                fileName[strlen(fileName) - 1] = '\0';
            }
            /*
            printf("Enter the file name: ");
            fgets(userInput, sizeof(userInput), stdin);

            for (int i = 0; i < sizeof(userInput); i++)
            {
                if(userInput[i] == '\n') {
                    endOfName = true;
                    userInput[i] = '\0';
                }

                if (endOfName) {
                    userInput[i] = '\0';
                }
            }
            */

            fileErr = fopen_s(&file, fileName, "w");

            if (fileErr == 0) {
                fputs(userText, file);
                fclose(file);
            }

            printf("Text written to file successfully.\n");

            break;
        case 5:

            printf("Enter the file name: ");
            fgets(fileName, sizeof(fileName), stdin);

            if (strlen(fileName) > 0 && fileName[strlen(fileName) - 1] == '\n') {
                fileName[strlen(fileName) - 1] = '\0';
            }

            //printf("Enter the file name: ");
            //fgets(userInput, sizeof(userInput), stdin);
            
            fileErr = fopen_s(&file, fileName, "r");

            if (fileErr == 1) {
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
            return 0;
            break;
        default:
            printf("I don't know that command.\n");
            printf("List of valid commands:\n");
            printf(" 1. Append text.\n2.Print text.\n3.Add newline.\n4.Write to file.\n5.Read from file.");
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