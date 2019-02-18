/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"
#include <stdlib.h>

char **remove_i_line(char **tab, int i)
{
    int j = i;

    free(tab[i]);
    for (; tab[j] != NULL; j++)
        tab[j] = tab[j + 1];
    tab[j] = NULL;
    return (tab);
}