#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "report.h"

#define SIZE 1000
int count;
int i = 0;
char *copy[100];

void replace(char *line, char *oldWord, char *newWord);

char *upper_case(char str[])
{
    char *newString = str;
    for (int i = 0; i < strlen(str); i++)
    {
        newString[i] = toupper(str[i]);
    }
    return newString;
}

void read_file(char *file_name, char *argumentWord)

{
    FILE *fp = NULL;
    FILE *fp1 = NULL;

    char text[1000];
    char arg[50] = "";
    char *charCount;

    strcpy(arg, argumentWord);

    fp = fopen(file_name, "r");
    fp1 = fopen("temp.txt", "w");

    if (fp1 == NULL || fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    while ((fgets(text, SIZE, fp)) != NULL)
    {
        char newWord[strlen(arg)];
        strcpy(newWord, arg);
        upper_case(newWord);
        replace(text, arg, newWord);
        fputs(text, fp1);
    }

    charCount = (char *)malloc(sizeof(char) * 100);

    sprintf(charCount, "%d", count);

    strcat(charCount, "\t");
    strcat(charCount, file_name);
    strcat(charCount, "\n");

    copy[i] = charCount;
    i++;

    fclose(fp);
    fclose(fp1);

    remove(file_name);
    rename("temp.txt", file_name);
}

void print_data()
{
    for (int j = 0; j < i; j++)
    {
        printf("%s", copy[j]);
    }
}

void print_sorted_data()
{
    qsort(copy, i, sizeof(char *), sort_string);
    print_data();
}

void replace(char *line, char *argWord, char *upperCaseWord)
{
    char *position, temp[SIZE];
    int index = 0;
    int wordLength;
    count = 0;
    wordLength = strlen(argWord);

    while ((position = strstr(line, argWord)) != NULL)
    {
        count++;

        strcpy(temp, line);

        index = position - line;
        line[index] = '\0';

        strcat(line, upperCaseWord);
        strcat(line, temp + index + wordLength);
    }
}
