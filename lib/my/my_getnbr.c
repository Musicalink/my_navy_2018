/*
** EPITECH PROJECT, 2018
** CPool_2018
** File description:
** Maxence Carpentier
*/

long int loop_add_nb(char const *str, long int result, int i, int counter)
{
    int nb_c = 0;

    while (str[i] >= '0' && str[i] <= '9') {
        nb_c++;
        if (nb_c > 9)
            return (0);
        result *= 10;
        result += (str[i] - '0');
        i++;
    }
    return (result);
}

long int search_for_operator(char const *str, long int result, int i)
{
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            result = -result;
        i--;
    }
    return (result);
}

int find_good_return(long int result)
{
    if (result < -2147483648 || result > 2147483647)
        return (0);
    return ((int)result);
}

int my_getnbr(char const *str, int i)
{
    long int result = 0;
    int saver = 0;
    int counter = 0;

    for (; str[i] != '\0'; i++) {
        while (str[i] == '+')
            i++;
        if (str[i] >= '0' && str[i] <= '9') {
            saver = i;
            result += (str[i] - '0');
            i++;
            counter++;
            result = loop_add_nb(str, result, i, counter);
            i = saver - 1;
            result = search_for_operator(str, result, i);
            break;
        }
    }
    return (find_good_return(result));
}
