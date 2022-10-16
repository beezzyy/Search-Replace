#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "text.h"

void print_report(char *arg, char *dirname)
{
    printf("Target string: %s\n", arg);

    printf("\nSearch begins in current folder: %s\n", dirname);

    printf("\n** Search Report **\nUpdates \tFile name\n");

    print_sorted_data();
}

int sort_string(const void *string1, const void *string2)
{
    return atoi(*(const char **)string2) - atoi(*(const char **)string1);
}
