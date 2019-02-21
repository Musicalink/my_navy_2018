/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** paul bryche
*/

#ifndef READ_SIZE
#define READ_SIZE (4096)
#endif

#ifndef MY_H_
#define MY_H_

int main(int, char **);

void try_free(char **);
int my_str(char *, char);
char *my_strcat(char *, char *);
char *get_result(char *, char **, int, char *);
char *get_next_line(int);

#endif
