/*
** EPITECH PROJECT, 2019
** shot_validation
** File description:
** paul bryche
*/

#include "my.h"
#include "navy.h"

int shot_validation(int i, char x, int y)
{
    char **map = static_map(0);
    int xbis = x - 39;

    y = y + 1;
    if (i == 1) {
        map[y][xbis] = 'x';
        static_map(map);
        return (1);
    } else {
        map[y][xbis] = 'o';
        static_map(map);
        return (0);
    }
}
