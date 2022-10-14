#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "text.h"
#include "traversal.h"
#include "report.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Argument not found. Please try again\n");
        exit(0);
    }

    char arg[strlen(argv[1])];
    strcpy(arg, argv[1]);
    char *dirname = ".";
    traversing_files(dirname, arg);
    print_report(arg, dirname);

    return 0;
}