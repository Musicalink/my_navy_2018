/*
** EPITECH PROJECT, 2019
** declare map
** File description:
** paul bryche
*/

#include <stdlib.h>
#include <stddef.h>
#include "navy.h"
#include "my.h"

char **declare_map(void)
{
    char **tab = malloc(sizeof(char *) * 11);
    tab[0] = my_strdup(" |A B C D E F G H");
    tab[1] = my_strdup("-+---------------");
    tab[2] = my_strdup("1|. . . . . . . .");
    tab[3] = my_strdup("2|. . . . . . . .");
    tab[4] = my_strdup("3|. . . . . . . .");
    tab[5] = my_strdup("4|. . . . . . . .");
    tab[6] = my_strdup("5|. . . . . . . .");
    tab[7] = my_strdup("6|. . . . . . . .");
    tab[8] = my_strdup("7|. . . . . . . .");
    tab[9] = my_strdup("8|. . . . . . . .");
    tab[10] = NULL;
    return (tab);
}
