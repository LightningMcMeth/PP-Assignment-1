#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//https://www.youtube.com/watch?v=wL2FHiBSh2E&ab_channel=UBCECESS

char** resizeArray(char** userTextArr, int arrRows, int newArrRows) {

    char** newUserTextArr = (char**)malloc(newArrRows * sizeof(char*));
    for (int i = 0; i < newArrRows; i++) {
        newUserTextArr[i] = (char*)malloc(100 * sizeof(char));
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

void cleanRow(char** userTextArr, int row) {

    for (int i = 0; i < 100; i++)
    {
        userTextArr[row][i] = '\0';
    }
}

void cleanArray(char** userTextArr, int row) {
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            userTextArr[i][j] = '\0';
        }
    }
}

int main() {
    int commandType = 0;
    int* pcommandType = &commandType;

    char userInput[100] = "";

    int arrRows = 3;
    char** userTextD = (char**)malloc(arrRows * sizeof(char*));
    for (int i = 0; i < arrRows; i++)
    {
        userTextD[i] = (char*)malloc(sizeof(userInput) * sizeof(char));
        userTextD[i][0] = '\0';
    }

    /*
    for (int i = 0; i < arrRows; i++)
    {
        
        for (int j = 0; j < 100; j++)
        {
            userTextD[i][j] = '\0';
        }
    }*/

    int textLength = 0;
    int textRow = 0;

    int rowLen = 98; //if there are issues, revert to 98

    while (1)
    {
        printf("\nChoose a command:\n");
        scanf_s("%d", &commandType);

        getchar();

        switch (*pcommandType) {
        case 1:

            printf("Enter text to append:");
            fgets(userInput, sizeof(userInput), stdin);
            userInput[strlen(userInput) - 1] = '\0';

            textLength += strlen(userInput);

            if (textLength < 100) {

                userInput[textLength] = '\0';

                strcat_s(userTextD[textRow], sizeof(userInput), userInput);
            }
            else if (textRow < arrRows - 1 && textLength >= rowLen) {

                textLength = strlen(userInput);
                textRow += 1;

                cleanRow(userTextD, textRow);

                strcat_s(userTextD[textRow], sizeof(userInput), userInput);
                //try accessing index 101, try to break the program on purpose

            }
            else if (textLength >= rowLen && textRow == arrRows - 1)
            {
                printf("\n\n       ---=== Allocating more memory ===---\n\n");

                userTextD = resizeArray(userTextD, arrRows, arrRows + 3);
                arrRows += 3;
                textRow += 1;   //added this at 23:29. Maybe it will fix da program
                textLength = strlen(userInput);
                //after reaching this part of the program, when writing to the newly created lines, I get an error saying the string is not null-terminated

                //cleanRow(userTextD, textRow);

                strcat_s(userTextD[textRow], sizeof(userInput), userInput);
                //userTextD[textRow][100] = '\0';

                break;
            }


            printf("\nText appended successfully: ");
            printf("%s", userInput);

            break;
        case 2:

            for (int i = 0; i < arrRows; i++) {
                printf("%s", userTextD[i]);
            }

            break;
        case 3:
            
            if (textLength < rowLen) {
                //if textLength = 97 and rowLen = 98, the code still proceeds, which results in a crash
                //messing around with the value of rowLen and maybe adding a - 1 to rowLen would help fix the issue.
                //adding -1 will account for extra space for the null-terminator
                strcat_s(userTextD[textRow], rowLen, "\n");
            }
            else if (textRow < arrRows - 1) {

                textRow += 1;
                textLength = 1; //because newline is 1 space

                cleanRow(userTextD, textRow);
                strcat_s(userTextD[textRow], sizeof(userInput), "\n");

                printf("Newline added successfully.\n");
            }
            else {
                printf("\n\n       ---=== Allocating more memory ===---\n\n");

                userTextD = resizeArray(userTextD, arrRows, arrRows + 3);

                arrRows += 3;
                textRow += 1;
                textLength = 1;

                cleanRow(userTextD, textRow);
                strcat_s(userTextD[textRow], sizeof(userInput), "\n");

                printf("Newline added successfully.\n");
            }

            break;
        case 4:
        {
            FILE* file;
            char fileName[25] = "";

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
            char fileName[25] = "";

            printf("Enter the file name: ");
            fgets(fileName, sizeof(fileName), stdin);

            if (strlen(fileName) > 0 && fileName[strlen(fileName) - 1] == '\n') {
                fileName[strlen(fileName) - 1] = '\0';
            }

            errno_t fileErr = fopen_s(&file, fileName, "r");
            if (fileErr != 0 || file == NULL) {
                printf("Error opening file. File either empty or doesn't exist.\n");
                break;
            }

            while (fgets(userInput, sizeof(userInput), file) != NULL) {
                printf("%s", userInput);
            }

            printf("\nFile read successfully.\n");
            break;
        }
        case 6:
        {
            printf("%s", userTextD[1]);
            break;
        }
        case 7:
            break;
        case 8:
            system("cls");
            break;
        default:
            printf("I don't know that command.\n");
            printf("List of valid commands:\n");
            printf(" 1. Append text.\n2.Print text.\n3.Add newline.\n4.Write to file.\n5.Read from file.\n8. Clear console");
            break;
        }
    }

    return 0;
}