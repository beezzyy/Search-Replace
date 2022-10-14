#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include "text.h"
#include "report.h"

void traversing_files(char *dirname, char *arg)
{
    DIR *directory = opendir(dirname);

    if (directory == NULL)
    {
        return;
    }
    struct dirent *dir = NULL;
    dir = readdir(directory);

    while (dir != NULL)
    {

        if (dir->d_type == DT_REG && strncmp(dir->d_name + strlen(dir->d_name) - 4, ".txt", 4) == 0)
        {

            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, dir->d_name);

            read_file(path, arg);
        }

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
