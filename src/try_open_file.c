/*
** EPITECH PROJECT, 2019
** paul bryche
** File description:
** try open file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
//#include "navy.h"

int is_a_file(char const *filepath)
{
    struct stat path_stat;

    stat(filepath, &path_stat);
    return (S_ISREG(path_stat.st_mode));
}

int fs_open_file(char const *filepath)
{
    int fd;

    if (is_a_file(filepath) == 0) {
        return (84);
    }
    fd = open(filepath, O_RDONLY);
    if (fd < 0) {
        return (84);
    } else {
        close(fd);
	return (0);
    }
}
