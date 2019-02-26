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
    int letter = static_char(0) - 'A';
    int number = static_int(-1) - 1;
    char **enemy_map = static_map(0);

    enemy_map[2 + number][2 + (letter * 2)] = (signb == SIGUSR1) ? 'x' : 'o';
    my_putchar(letter + 'A');
    my_put_nbr(number + 1);
    my_putstr((signb == SIGUSR1) ? ": hit\n\n" : ": missed\n\n");
    static_map(enemy_map);
    signal(SIGUSR1, NULL);
    signal(SIGUSR2, NULL);
    game(1, static_pid(-1), enemy_map);
}

int send_packet(char *s, pid_t enemy)
{
    int count = s[0] - 'A';

    static_char(s[0]);
    static_int(s[1] - '0');
    for (; count > 0; count--) {
        kill(enemy, SIGUSR1);
        usleep(5000);
    }
    kill(enemy, SIGUSR2);
    usleep(5000);
    count = s[1] - '0';
    for (; count > 0; count--) {
        kill(enemy, SIGUSR1);
        usleep(5000);
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
    char tmp = table[2 + number][2 + (letter * 2)];

    table[2 + number][2 + (letter * 2)] = (tmp == '.') ? 'o' : 'x';
    return ((tmp != '.') ? 1 : 0);
}

void end_receiver_turn(char c, int i, int value, char **enemy_map)
{
    value = is_it_touched();
    kill(static_pid(-1), (value == 1 ? SIGUSR1 : SIGUSR2));
    my_putchar(c);
    my_put_nbr(i);
    my_putstr((value == 1) ? ": hit\n\n" : ": missed\n\n");
    game(0, static_pid(-1), enemy_map);
}

void receive_packet(int signb)
{
    static int counter = 0;
    char c = static_char(0);
    int i = static_int(-1);
    char **enemy_map = static_map(0);
    int value = 0;

    if (signb == SIGUSR1) {
        if (counter == 0)
            c = static_char((char)(static_char(0) + 1));
        else if (counter == 1)
            i = static_int(static_int(-1) + 1);
    } else if (signb == SIGUSR2)
        counter++;
    if (counter == 2) {
        counter = 0;
        end_receiver_turn(c, i, value, enemy_map);
    }
}