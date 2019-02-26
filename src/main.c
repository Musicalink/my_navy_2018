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

void print_maps(void)
{
    char **enemy_map = static_map(0);

    my_putstr("my positions:\n");
    for (int i = 0; table[i] != NULL; i++) {
        my_putstr(table[i]);
        my_putchar('\n');
    }
    my_putstr("\nenemy's positions:\n");
    for (int i = 0; enemy_map[i] != NULL; i++) {
        my_putstr(enemy_map[i]);
        my_putchar('\n');
    }
}

int is_the_tir_plutot_bon(char *s)
{
    int error = 0;

    if (s == NULL)
        return (0);
    else if (my_strlen(s) != 2)
        return (0);
    error += (s[0] >= 'A' && s[0] <= 'H') ? 0 : 1;
    error += (s[1] >= '1' && s[1] <= '8') ? 0 : 1;
    return ((error == 0) ? 1 : 0);
}

char *get_next_entry(void)
{
    char *s = NULL;

    my_putstr("\nattack: ");
    s = get_next_line(0);

    if (s == NULL)
        return (NULL);
    while (is_the_tir_plutot_bon(s) != 1) {
        my_putstr("wrong position\nattack: ");
        s = get_next_line(0);
        if (s == NULL)
            return (NULL);
    }
    return (s);
}

int game(int status, pid_t enemy, char **enemy_map)
{
    char *s;

    if (status == 0) {
        print_maps();
        s = get_next_entry();
        if (s == NULL)
            return (84);
        static_pid(enemy);
        send_packet(s, enemy);
    } else {
        my_putstr("waiting for enemy's attack...\n");
        static_char('A');
        static_int(0);
        static_pid(enemy);
        signal(SIGUSR1, receive_packet);
        signal(SIGUSR2, receive_packet);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (parsing(ac, av) == 84) {
        return (84);
    }
    table = declare_map();
    static_map(declare_map());
    return (launch_game(ac, av));
}
