/*
 * Write a C program including necessary functions to change the
 * bytes in a binary file. The file name and a number between
 * 0 and 255 will be entered from keyboard. Your program will
 * modify the file by substracting the number from each byte of
 * this file. Show also decryption process.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxSize 255


int decryptedTextFile(char *, char *);

char *getChar(char *c);

int main() {
    FILE *f;
    char sourceFile[maxSize];
    char targetFile[maxSize];
    char *getStr;
    getStr = (char *) malloc(sizeof(char *));

    printf("Enter characters between 0 and 255:");
    fflush(stdin);
    fgets(getStr, maxSize, stdin);
    printf("\nEnter source file name:");
    scanf("%s", sourceFile);
    printf("\nEnter target file name:");
    scanf("%s", targetFile);

    f = fopen(sourceFile, "w");
    fprintf(f, "%s", getStr);
    fclose(f);

    if (decryptedTextFile(sourceFile, targetFile)) {
        printf("The text has been encrypt.!\n");
    }
    system("Pause");
    return 0;
}

int decryptedTextFile(char *sourcefile, char *targetfile) {
    FILE *fptr, *fptr2;
    char line[100];
    int i;
    fptr = fopen(sourcefile, "r");
    fptr2 = fopen(targetfile, "w");
    while (!feof(fptr)) {
        fgets(line, 100, fptr);
        strcpy(line, getChar(line));

        for (i = 0; i < strlen(line); i++) {

            if (line[i] >= 0 && line[i] <= maxSize) {
                printf("Source character:%c\n", line[i]);
                line[i] = line[i] - 3;
                printf("After decrypt character:%c\n", line[i] - 3);

            }

        }

        fprintf(fptr2, "%s", line);
        break;
    }
    fclose(fptr);
    fclose(fptr2);
    return 1;
}

char *getChar(char *c) {
    int lenght = strlen(c);
    while (lenght--) {
        if (c[lenght] == '\n')
            c[lenght] = '\0';
    }
    return c;
}