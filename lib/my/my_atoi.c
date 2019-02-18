/*
** EPITECH PROJECT, 2018
** Project By Maxence Carpentier
** File description:
** A Epitech Project
*/

int my_atoi(char *array)
{
    int nb = 0;
    int tempo = 0;

    while (*array == '-' || *array == '+') {
        if (*array == '-')
            tempo++;
        (array)++;
    }
    while (*array >= '0' && *array <= '9') {
        nb = nb * 10 + (*array - '0');
        (array)++;
    }
    if (tempo % 2 != 0)
        nb *= -1;
    return (nb);
}

int my_natoi(char *array, int n)
{
    int nb = 0;
    int tempo = 0;

    for (int i = 0; i < n; i++)
        (array)++;
    while (*array == '-' || *array == '+') {
        if (*array == '-')
            tempo++;
        (array)++;
    }
    while (*array >= '0' && *array <= '9') {
        nb = nb * 10 + (*array - '0');
        (array)++;
    }
    if (tempo % 2 != 0)
        nb *= -1;
    return (nb);
}