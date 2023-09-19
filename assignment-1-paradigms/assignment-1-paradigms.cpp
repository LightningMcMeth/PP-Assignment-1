#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//https://www.youtube.com/watch?v=wL2FHiBSh2E&ab_channel=UBCECESS

char** resizeArray(char** userTextArr, int arrRows, int newArrRows) {

    char** newUserTextArr = (char**)calloc(newArrRows, sizeof(char*));
    for (int i = 0; i < newArrRows; i++) {
        newUserTextArr[i] = (char*)calloc(100, sizeof(char));
    }

    for (int i = 0; i < arrRows; i++) {
        for (int j = 0; j < 100; j++) {
            newUserTextArr[i][j] = userTextArr[i][j];
        }
    }

    for (int i = 0; i < arrRows; i++) {
        free(userTextArr[i]);
    }
    free(userTextArr);

    return newUserTextArr;
}

int main() {

    int commandType = 0;
    int* pcommandType = &commandType;

    char userInput[100] = "";
    //char userText[100] = "";

    int arrRows = 3;
    char** userTextD = (char**)calloc(arrRows, sizeof(char*));    //rows
    for (int i = 0; i < arrRows; i++) //columns 
    {
        userTextD[i] = (char*)calloc(sizeof(userInput), sizeof(char));
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

            textLength += strlen(userInput);

            if (textLength <= 100) {

                userInput[textLength] = '\0';   //may need to bring back textLength - 1

                strcat_s(userTextD[textRow], sizeof(userInput), userInput);
            }
            else if (textRow < arrRows - 1 && textLength >= 100){

                textLength = strlen(userInput);
                textRow += 1;

                strcat_s(userTextD[textRow], sizeof(userInput), userInput);

            }
            else if (textLength >= 100 && textRow == arrRows - 1)
            {
                //printf("reallocate some memory or something.\n");


                userTextD = resizeArray(userTextD, arrRows, arrRows + 2);
                arrRows += 2;

                strcat_s(userTextD[textRow], sizeof(userInput), userInput);

                break;
            }


            printf("\nText appended successfully: ");
            printf("%s", userInput);

            break;
        case 2:


            for (int i = 0; i < arrRows; i++)
            {
                for (int j = 0; j < sizeof(userInput); j++)
                {
                    printf("%c", userTextD[i][j]);
                }
            }

            break;
        case 3:
            
            if (textLength < sizeof(userInput)) {
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

            errno_t fileErr = fopen_s(&file, fileName, "r");
            if (fileErr == 1) {
                printf("Error opening file, or the file is empty.\n");
                break;
            }

            for (int i = 0; i < arrRows; i++)
            {
                if (fgets(userInput, sizeof(userInput), file) == NULL)
                {
                    break;
                }

                for (int j = 0; j < 100; j++)
                {
                    userTextD[i][j] = userInput[j];
                }
                printf("%s", userInput);
            }

            printf("\nFile read successfully.\n");
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