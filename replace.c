#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "text.h"
#include "traversal.h"
#include "report.h"

int main(int argc, char **argv)
{
    char arg[strlen(argv[1])];
    strcpy(arg, argv[1]);
    char *dirname = ".";
    traversing_files(dirname, arg);
    print_report(arg, dirname);

    return 0;
}