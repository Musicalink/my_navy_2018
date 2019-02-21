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

void get_touch(int signb)
{
    my_putstr("-> 6\n");
    int letter = static_char(0) - 'A';
    int number = static_int(-1) - 1;
    char **enemy_map = static_map(0);

    if (signb == SIGUSR1)
        enemy_map[2 + number][2 + (letter * 2)] = 'X';
    else
        enemy_map[2 + number][2 + (letter * 2)] = 'O';
    static_map(enemy_map);
    signal(SIGUSR1, NULL);
    signal(SIGUSR2, NULL);
    my_putstr("-> 7\n");
    game(1, static_pid(-1), enemy_map);
}

int send_packet(char *s, pid_t enemy)
{
    int count = s[0] - 'A';

    my_putstr("-> 1\n");
    static_char(s[0]);
    static_int(s[1] - '0');
    my_putstr("-> 2\n");
    if (my_strlen(s) < 2)
        return (84);
    for (; count > 0; count--) {
        kill(enemy, SIGUSR1);
        usleep(10000);
    }
    my_putstr("-> 3\n");
    kill(enemy, SIGUSR2);
    usleep(10000);
    count = s[1] - '0';
    my_putstr("-> 4\n");
    for (; count > 0; count--) {
        kill(enemy, SIGUSR1);
        usleep(10000);
    }
    kill(enemy, SIGUSR2);
    signal(SIGUSR1, get_touch);
    signal(SIGUSR2, get_touch);
    return (0);
}

int is_it_touched(void)
{
    int letter = static_char(0) - 'A';
    int number = static_int(-1) - 1;

    return ((table[2 + number][2 + (letter * 2)] != '.') ? 1 : 0);
}

void receive_packet(int signb)
{
    static int counter = 0;
    char c = static_char(0);
    int i = static_int(-1);
    char **enemy_map = static_map(0);

    if (signb == SIGUSR1) {
        if (counter == 0)
            c = static_char((char)(static_char(0) + 1));
        else if (counter == 1)
            i = static_int(static_int(-1) + 1);
    } else if (signb == SIGUSR2)
        counter++;
    if (counter == 2) {
        usleep(30000);
        kill(static_pid(-1), (is_it_touched() == 1 ? SIGUSR1 : SIGUSR2));
        signal(SIGUSR1, NULL);
        signal(SIGUSR2, NULL);
        counter = 0;
        game(0, static_pid(-1), enemy_map);
    }
}