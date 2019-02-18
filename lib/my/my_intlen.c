/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"

int my_intlen(int nb)
{
    int intlen = 1;

    for (; nb >= 10; intlen++)
        nb /= 10;
    return (intlen);
}