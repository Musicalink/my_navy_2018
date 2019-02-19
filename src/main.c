/*
** EPITECH PROJECT, 2018
** navy_2018
** File description:
** Maxence Carpentier
*/

int main(int ac, char **av)
{
    char **my_map;
    char **nmy_map;

    if (parsing(ac, av) == 84)
        return (84);
    my_map = declare_map();
    nmy_map = declare_map();
    try_map(my_map);
    printf("\n\n");
    try_map(nmy_map);
//    def_pos_map(&my_map, av, ac);
//    game();
//    free(my_map);
//    free(nmy_map);
    return (0);
}
