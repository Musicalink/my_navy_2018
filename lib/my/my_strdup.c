/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int length_src = my_strlen(src);
    char *dest = malloc(sizeof(char) * length_src + 1);
    int i = 0;

    for (; i < length_src; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}