/*
** EPITECH PROJECT, 2019
** parsing navy
** File description:
** paul bryche
*/

#include "navy.h"
#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>

int check_pos_range(char *buffer)
{
    int error = 0;

    if (buffer[3] == buffer[6]) {
        if ((buffer[2] - buffer[5] + 1) == (buffer[0] - '0'))
            return (0);
        else if ((buffer[2] - buffer[5] - 1) == -(buffer[0] - '0'))
            return (0);
    } else if (buffer[2] == buffer[5]) {
        if ((buffer[3] - buffer[6] + 1) == (buffer[0] - '0'))
            return (0);
        else if ((buffer[3] - buffer[6] - 1) == -(buffer[0] - '0'))
            return (0);
    }
    return (84);
}

int check_map_pos(char *buff)
{
    int error = 0;

    error += (buff[2] < 'A' && buff[2] > 'H') ? 1 : 0;
    error += (buff[5] < 'A' && buff[5] > 'H') ? 1 : 0;
    error += (buff[3] < '1' && buff[3] > '8') ? 1 : 0;
    error += (buff[6] < '1' && buff[6] > '8') ? 1 : 0;
    error += (check_pos_range(buff) != 0) ? 1 : 0;
    return ((error != 0) ? 84 : 0);
}

int check_line(int check_val, char *buf)
{
    int error = 0;

    error += (buf[0] > '5' || buf[0] < '2') ? 1 : 0;
    check_val -= (buf[0] - '0');
    error += (buf[1] != ':' && buf[4] != ':' && buf[7] != '\n') ? 1 : 0;
    error += (check_map_pos(buf) == 84) ? 1 : 0;
    return ((error != 0) ? -84 : check_val);
}

int check_map(char *path)
{
    int fd;
    char *buffer;
    int check_value = 14;
    int i = 0;
    int ret_value = 0;

    if (fs_open_file(path) == 84)
        return (84);
    fd = open(path, O_RDONLY);
    buffer = malloc(sizeof(char) * 9);
    while (buffer != NULL && check_value >= 0 && i <= 3) {
        buffer[read(fd, buffer, 8)] = '\0';
        check_value = check_line(check_value, buffer);
        i++;
    }
    if (check_value != 0 || read(fd, buffer, 8) != 0)
        ret_value = 84;
    close(fd);
    free(buffer);
    return (ret_value);
}

int parsing(int ac, char **av)
{
    if (ac == 2 && check_map(av[1]) == 0)
        return (0);
    else if (ac == 3 && check_map(av[2]) == 0)
        return (0);
    else
        return (84);
}
