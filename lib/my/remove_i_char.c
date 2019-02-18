/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"

char *remove_i_char(char *str, int i)
{
    for (; str[i] != '\0'; i++)
        str[i] = str[i + 1];
    str[i] = '\0';
    return (str);
}