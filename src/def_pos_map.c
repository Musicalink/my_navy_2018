/*
** EPITECH PROJECT, 2019
** def_pos_map
** File description:
** paul bryche
*/

#include <stdlib.h>
#include <stddef.h>
#include "navy.h"
#include "my.h"
#include <fcntl.h>

void put_boat(int static_pos, int movable_one, int movable_two, int boolean)
{
    char to_put = (movable_two + 1 - movable_one) + '0';

    for (int i = 0; movable_one + i <= movable_two; i++)
        if (boolean == 1)
            table[static_pos + 2][(movable_one + i) * 2 + 2] = to_put;
        else
            table[movable_one + 2 + i][static_pos * 2 + 2] = to_put;
}

void write_pos(char **pos)
{
    int static_pos;
    int one;
    int two;

    for (int i = 0; pos[i] != NULL; i++) {
        if (pos[i][2] == pos[i][5]) {
            static_pos = pos[i][2] - 'A';
            one = pos[i][3] - '1';
            two = pos[i][6] - '1';
        } else {
            static_pos = pos[i][3] - '1';
            one = pos[i][2] - 'A';
            two = pos[i][5] - 'A';
        }
        put_boat(static_pos, one, two, (pos[i][2] == pos[i][5]) ? 0 : 1);
    }
}

void def_pos_map(char *path)
{
    int fd = open(path, O_RDONLY);
    char *str = malloc(sizeof(char) * 4096);
    char **pos;

    read(fd, str, 4096);
    pos = my_str_to_word_array(str, '\n');
    free(str);
    write_pos(pos);
}