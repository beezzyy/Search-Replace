#include <stdio.h>
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

int sort_string(const void *str1, const void *str2)
{
    char *const *pp1 = str1;
    char *const *pp2 = str2;
    return strcmp(*pp2, *pp1);
}
