/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str, int i);

char *my_strcpy(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char **my_str_to_word_array(char *str, char separator);

void my_show_word_array(char *const *tab);

char *my_strdup(char const *src);

char *my_revstr(char *str);

char *my_itoa(int nb);

int my_intlen(int nb);

int my_tablen(char **tab);

void free_tab(char **tab);

char *remove_i_char(char *str, int i);

char **remove_i_line(char **tab, int i);

int my_atoi(char *array);

int my_natoi(char *array, int n);

int my_put_nbr(int nb);

int my_strncmp(char const *s1, char const *s2, int max);

char *my_strcat(char *dest, const char *src);

#endif