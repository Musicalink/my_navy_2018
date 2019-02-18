/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb >= 0) {
        if (nb >= 10)
            my_put_nbr(nb / 10);
        my_putchar(nb % 10 + '0');
    } else if (nb < 0) {
        if (nb == -2147483648) {
            my_put_nbr(-2147);
            my_put_nbr(483648);
            return (0);
        }
        my_putchar('-');
        my_put_nbr(nb * -1);
    }
    return (0);
}