#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "text.h"
#include "report.h"

/*
This function iterates every .txt files in every directories
*/
void traversing_files(char *dirname, char *arg)
{
    DIR *directory = opendir(dirname);

    // check if directory is found
    if (directory == NULL)
    {
        printf("Directory not found!\n");
        exit(1);
        return;
    }
    struct dirent *dir = NULL;
    dir = readdir(directory);

    while (dir != NULL)
    {
        // verifies if it's .txt file
        if (dir->d_type == DT_REG && strncmp(dir->d_name + strlen(dir->d_name) - 4, ".txt", 4) == 0)
        {

            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, dir->d_name);

            read_file(path, arg);
        }
        // Goes through all directories except for the . and ..
        if (dir->d_type == DT_DIR && strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0)
        {
            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, dir->d_name);
            traversing_files(path, arg);
        }
        dir = readdir(directory);
    }

    closedir(directory);
}
