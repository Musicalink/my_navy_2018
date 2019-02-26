/*
** EPITECH PROJECT, 2018
** Navy_2018
** File description:
** Maxence Carpentier
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <unistd.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

char **table;

char static_char(char c);

int static_int(int i);

pid_t static_pid(pid_t i);

char **static_map(char **map);

void host(int sig, siginfo_t *siginfo, void *context);

void guest(int sig, siginfo_t *siginfo, void *context);

void print_pid(pid_t pid);

int send_packet(char *s, pid_t enemy);

void receive_packet(int signb);

int launch_game(int ac, char **av);

int check_pos_range(char *buffer);

int check_map_pos(char *buff);

int check_line(int check_val, char *buf);

int check_map(char *path);

int parsing(int ac, char **av);

void put_boat(int static_pos, int movable_one, int movable_two, int boolean);

void write_pos(char **pos);

void def_pos_map(char *path);

char **declare_map(void);

int is_a_file(char const *filepath);

int fs_open_file(char const *filepath);

int game(int status, pid_t enemy, char **enemy_map);

int my_char_cmp(char c, char *check);

int shot_gestionnary(int y, char x);

int shot_validation(int i, char x, int y);

void print_maps(void);

void try_free(char **str);

int my_str(char *str, char c);

char *get_result(char *str, char **save, int size, char *buffer);

char *get_next_line(int fd);

void end_receiver_turn(char c, int i, int value, char **enemy_map);

#endif
