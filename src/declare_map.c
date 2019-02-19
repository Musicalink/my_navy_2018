/*
** EPITECH PROJECT, 2019
** declare map
** File description:
** paul bryche
*/

#include <stdlib.h>
#include <stddef.h>
//#include "navy.h"

void try_map(char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        printf("%s\n", map[i]);
        i++;
    }
}

char **malloc_tab(int x, int y)
{
    char **tab = malloc(sizeof(char*) * (y + 1));
    int i = 0;

    if (tab == NULL)
        return (NULL);
    while (i < y) {
        tab[i] = malloc(sizeof(char) * (x + 1));
        if (tab[i] == NULL)
            return (NULL);
        i++;
    }
    tab[i] = NULL;
    return (tab);
}

char **declare_map(void)
{
    char **map = malloc_tab(8, 8);
    int y = 0;
    int x = 0;

    if (map == NULL)
        return (NULL);
    while (map[y] != NULL) {
        while (x < 8) {
            map[y][x] = '.';
            x++;
        }
        map[y][x] = '\0';
        y++;
        x = 0;
    }
    return (map);
}
