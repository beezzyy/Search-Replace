#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>
#include <string.h>
#include "text.h"

char *getcwd(char *buffer, size_t size);

void print_report(char *arg)
{
    char cwd[200];

    printf("Target string: %s\n", arg);

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("\nSearch begins in current folder: %s\n", cwd);
    }

    printf("\n** Search Report **\nUpdates \tFile name\n");

    print_sorted_data();
}

int sort_string(const void *string1, const void *string2)
{
    return atoi(*(const char **)string2) - atoi(*(const char **)string1);
}
