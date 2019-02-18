/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_revstr(char *str)
{
    int i2 = my_strlen(str) - 1;
    char c;

    for (int i = 0; i < i2; i++) {
        c = str[i];
        str[i] = str[i2];
        str[i2] = c;
        i2--;
    }
    return (str);
}