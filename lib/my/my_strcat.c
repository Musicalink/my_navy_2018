/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(dest) + my_strlen(src) + 1;
    char *result = malloc(sizeof(char) * (size_t)size);

    for (; dest[i] != '\0'; i++)
        result[i] = dest[i];
    for (; src[j] != '\0'; j++) {
        result[i] = src[j];
        i++;
    }
    result[i] = '\0';
    return (result);
}