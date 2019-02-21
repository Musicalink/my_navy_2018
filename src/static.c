/*
** EPITECH PROJECT, 2018
** navy_2018
** File description:
** Maxence Carpentier
*/

#include <unistd.h>
#include "navy.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

char static_char(char c)
{
    static char letter;

    if (c != 0)
        letter = c;
    return (letter);
}

int static_int(int i)
{
    static int nb;

    if (i != -1)
        nb = i;
    return (nb);
}

pid_t static_pid(pid_t i)
{
    static pid_t pid;

    if (i != -1)
        pid = i;
    return (pid);
}

char **static_map(char **map)
{
    static char **static_map;

    if (map != 0)
        static_map = map;
    return (static_map);
}