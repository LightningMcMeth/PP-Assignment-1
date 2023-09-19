#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//TODO:

/*
https://www.youtube.com/watch?v=wL2FHiBSh2E&ab_channel=UBCECESS
*/

int main() {

    int commandType = 0;
    int* pcommandType = &commandType;

    char userInput[100] = "";
    char userText[100] = "";

    int arrRows = 3;
    char** userTextD = (char**)calloc(arrRows, sizeof(char*));    //rows
    for (int i = 0; i < arrRows; i++) //columns 
    {
        userTextD[i] = (char*)calloc(100, sizeof(char));
    }

    int textLength = 0;
    int textRow = 0;


    while (1)
    {
        printf("\nChoose a command:\n");
        scanf_s("%d", &commandType);

        getchar();

        switch (*pcommandType){
        case 1:
            
            printf("Enter text to append:");
            fgets(userInput, sizeof(userInput), stdin);
            userInput[strlen(userInput) - 1] = '\0';

            if (textLength + atoi(userInput) <= 100) {

                textLength += strlen(userInput);

                userInput[textLength - 1] = '\0';

                //strcpy_s(userTextD[textRow], sizeof(userInput), userInput);
                strcat_s(userTextD[textRow], sizeof(userInput), userInput);
            }
            else if (textRow < arrRows - 1 || textLength + atoi(userInput) >= 100){

                textLength = strlen(userInput);
                textRow += 1;

                //strcpy_s(userTextD[textRow], sizeof(userInput), userInput);
                strcat_s(userTextD[textRow], sizeof(userInput), userInput);

            }
            else if (strlen(userInput) >= 100)
            {
                printf("reallocate some memory or something.\n");
                break;
            }

            //strcpy_s(userTextD[textRow], sizeof(userInput), userInput);

            printf("\nText appended successfully: ");
            printf("%s", userInput);

            break;
        case 2:


            for (int i = 0; i < arrRows; i++)
            {
                for (int j = 0; j < 100; j++)
                {
                    printf("%c", userTextD[i][j]);
                }
            }

            break;
        case 3:
            
            if (textLength < 100) {
                userTextD[textRow][textLength - 1] = '\n';
            }

            printf("Newline added successfully.\n");

            break;
        case 4:
        {
            FILE* file;
            char fileName[25];
            
            printf("Enter the file name: ");
            fgets(fileName, sizeof(fileName), stdin);

            if (strlen(fileName) > 0 && fileName[strlen(fileName) - 1] == '\n') {
                fileName[strlen(fileName) - 1] = '\0';
            }

            errno_t fileErr = fopen_s(&file, fileName, "w");

            if (fileErr == 0) {
                for (int i = 0; i < arrRows; i++)
                {
                    fputs(userTextD[textRow], file);
                    fclose(file);
                }
            }

            printf("Text written to file successfully.\n");            
            break;
        }
        case 5:
        {
            FILE* file;
            char fileName[25];

            printf("Enter the file name: ");
            fgets(fileName, sizeof(fileName), stdin);

            if (strlen(fileName) > 0 && fileName[strlen(fileName) - 1] == '\n') {
                fileName[strlen(fileName) - 1] = '\0';
            }

            printf("Enter the file name: ");
            fgets(userInput, sizeof(userInput), stdin);

            errno_t fileErr = fopen_s(&file, fileName, "r");

            if (fileErr == 1) {
                printf("Error opening file, or the file is empty.\n");
                break;
            }

            /*
            while (fgets(userInput, sizeof(userText), file) != NULL) {
                printf("%s", userInput);
            }*/

            for (int i = 0; i < arrRows; i++)
            {
                if (fgets(userInput, sizeof(userText), file) == NULL)
                {
                    break;
                }

                for (int j = 0; j < 100; j++)
                {
                    userTextD[i][j] = userInput[j];
                }
                printf("%s", userInput);
            }

            printf("File read successfully.\n");
            break;
        }
        case 6:
            printf("Command not implemented yet.");
            break;
        case 7:
            printf("Command not implemented yet.");
            break;
        case 8:
            system("cls");
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


/*
{
            FILE* file;

            //printf("Enter the file name: ");
            //fgets(fileName, sizeof(fileName), stdin);

            file = fopen("myfile.txt", "w");
            for (int i = 0; i < textRow; i++)
            {
                fputs(userTextD[i], file);
            }

            if (fgets(userInput, sizeof(userInput), file) != NULL)
            {
                printf("%s", userInput);
            }
            fclose(file);

            break;
        }*/