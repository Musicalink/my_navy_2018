/*
** EPITECH PROJECT, 2019
** check_map
** File description:
** paul bryche
*/

#include <navy.h>

int check_map_positions(int value)
{
    int x = 2;
    int y = 2;
    char c = value + 30;

    while (table[y] != NULL) {
        while (tabl[y][x] != '\0') {
            if (tabl[y][x] == c)
                value--;
            x++;
        }
        y++;
        x = 2;
    }
    if (value != 0)
        return (84);
    return (0);
}

int check_map(void)
{
    int counter = 2;

    while (counter <= 5) {
        if (check_map_positions(counter) == 0)
            counter++;
        else
            return (84);
    }
    return (0);
}
