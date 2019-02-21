/*
** EPITECH PROJECT, 2019
** shot gestionnary
** File description:
** paul bryche
*/

int my_char_cmp(char c, char *check)
{
    int i = 0;

    while (check[i] != '\0') {
        if (c == check[i])
            return (0);
        i++;
    }
    return (84);
}

int shot_gestionnary(int y, char x)
{
    int xbis = x - 39;

    y = y + 1;
    if (my_char_cmp(table[y][xbis], "2345") == 0) {
        table[y][xbis] = 'x';
        return (1);
    } else {
        table[y][xbis] = 'o';
        return (0);
    }
    return (84);
}
