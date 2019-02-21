/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** paul bryche
*/

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

void try_free(char **str)
{
    if (*str != NULL)
        free(*str);
}

int my_str(char *str, char c)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != c && str[i] != '\0')
        i++;
    return (i);
}

char *gnl_strcat(char *stra, char *strb)
{
    int size = my_str(stra, '\0') + my_str(strb, '\0');
    char *result = malloc(sizeof(char) * size + 1);

    if (stra == NULL && strb == NULL)
        return (NULL);
    else {
        size = 0;
        for (int j = 0; stra != NULL && stra[j] != '\0'; j++) {
            result[size] = stra[j];
            size++;
        }
        for (int j = 0; strb != NULL && strb[j] != '\0'; j++) {
            result[size] = strb[j];
            size++;
        }
        result[size] = '\0';
    }
    return (result);
}

char *get_result(char *str, char **save, int size, char *buffer)
{
    int pos = my_str(str, '\n');
    char *strfnl = malloc(sizeof(char) * pos + 1);

    try_free(&buffer);
    if ((str == NULL && strfnl == NULL) || size == 0)
        return (NULL);
    strfnl[pos] = '\0';
    for (int i = 0; i < pos; i++)
        strfnl[i] = str[i];
    *save = NULL;
    if (pos != size)
        *save = &str[pos + 1];
    return (strfnl);
}

char *get_next_line(int fd)
{
    static char *save = NULL;
    char *buffer = malloc(sizeof(char) * READ_SIZE + 1);
    char *strfnl = NULL;
    int read_size = 1;
    int size;

    if (fd < 0 || buffer == NULL)
        return (NULL);
    strfnl = gnl_strcat(save, "\0");
    size = my_str(strfnl, '\0');
    while (my_str(strfnl, '\n') == size && strfnl != NULL && read_size > 0) {
        read_size = read(fd, buffer, READ_SIZE);
        buffer[read_size] = '\0';
        strfnl = gnl_strcat(strfnl, buffer);
        size = my_str(strfnl, '\0');
    }
    strfnl = get_result(strfnl, &save, my_str(strfnl, '\0'), buffer);
    return (strfnl);
}
