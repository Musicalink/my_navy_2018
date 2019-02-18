/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"
#include <stdlib.h>

int my_tablen(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}