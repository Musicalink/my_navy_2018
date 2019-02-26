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

void host(int sig, siginfo_t *siginfo, void *context)
{
    my_putstr("\nenemy connected\n\n");
    kill((int)siginfo->si_pid, SIGUSR1);
    game(0, siginfo->si_pid, NULL);
}

void guest(int sig, siginfo_t *siginfo, void *context)
{
    my_putstr("successfully connected\n");
    print_maps();
    game(1, siginfo->si_pid, NULL);
}

void print_pid(pid_t pid)
{
    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
}

int launch_game(int ac, char **av)
{
    struct sigaction act;
    pid_t pid = getpid();

    print_pid(pid);
    if (ac == 3) {
        def_pos_map(av[2]);
        act.sa_sigaction = &guest;
        act.sa_flags = SA_SIGINFO;
        kill(my_atoi(av[1]), SIGUSR1);
        if (sigaction(SIGUSR1, &act, NULL) < 0)
            my_putstr("ouhlala\n");
    } else {
        def_pos_map(av[1]);
        my_putstr("waiting for enemy connection...\n");
        act.sa_sigaction = &host;
        act.sa_flags = SA_SIGINFO;
        if (sigaction(SIGUSR1, &act, NULL) < 0)
            my_putstr("ouhlala\n");
    }
    while (42)
        pause();
    return (0);
}