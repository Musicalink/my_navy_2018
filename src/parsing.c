/*
** EPITECH PROJECT, 2019
** parsing navy
** File description:
** paul bryche
*/

//#include "navy.h"                                                                           
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int check_pos_range(char *buffer)
{
    if (buffer[3] == buffer[6]) {
        if ((buffer[2] - buffer[5] + 1) == (buffer[0] - '0'))
            return (0);
        if ((buffer[2] - buffer[5] - 1) == -(buffer[0] - '0'))
            return (0);
    }
    if (buffer[2] == buffer[5]) {
        if ((buffer[3] - buffer[6] + 1) == (buffer[0] - '0'))
            return (0);
        if ((buffer[3] - buffer[6] - 1) == -(buffer[0] - '0'))
            return (0);
    }
    return (84);
}

int check_map_pos(char *buff)
{
    if ((buff[2] < 'A' && buff[2] > 'H') || (buff[5] < 'A' && buff[5] > 'H'))
        return (84);
    if ((buff[3] < '1' && buff[3] > '8') || (buff[6] < '1' && buff[6] > '8'))
        return (84);
    if (check_pos_range(buff) == 0)
        return (0);
    return (84);
}

int check_line(int check_val, char *buffer)
{
    if (buffer[0] > '5' || buffer[0] < '2')
        return (-84);
    check_val -= (buffer[0] - '0');
    if (buffer[1] != ':' && buffer[4] != ':' && buffer[7] != '\n')
        return (-84);
    if (check_map_pos(buffer) == 84)
        return (-84);
    return (check_val);
}

int check_map(char *path)
{
    int fd;
    char *buffer;
    int check_value = 14;
    int i = 0;

    if (fs_open_file(path) == 84)
        return (84);
    fd = open(path, O_RDONLY);
    buffer = malloc(sizeof(char) * 9);
    while (buffer != NULL && check_value >= 0 && i <= 4) {
        buffer[read(fd, buffer, 8)] = '\0';
        check_value = check_line(check_value, buffer);
        i++;
    }
    free(buffer);
    if (check_value != 0)
        return (84);
    return (0);
}

int parsing(int ac, char **av)
{
    if (ac == 2 && check_map(av[1]) == 0 /*&& check_pid(NULL) == 0*/)
        return (0);
    else if (ac == 3 && check_map(av[2]) == 0 /*&& check_pid(av[2]) == 0*/)
        return (0);
    return (84);
}
