/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <stdlib.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] - s2[i] != 0)
            return (s1[i] - s2[i]);
    if (s1[i] == '\0')
        return (0 - s2[i]);
    else
        return (s1[i]);
}

int my_strncmp(char const *s1, char const *s2, int max)
{
    int i = 0;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && i < max; i++)
        if (s1[i] - s2[i] != 0)
            return (s1[i] - s2[i]);
    return (0);
}