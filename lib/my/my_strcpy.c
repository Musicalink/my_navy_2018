/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    if (str == NULL) {
        dest[0] = '\0';
        return (NULL);
    }
    for (i = 0; str[i] != '\0'; i++)
        dest[i] = str[i];
    dest[i] = '\0';
    return (dest);
}