/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** main sokoban
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

int error_handling(info_t *info)
{
    int count_p = 0;
    char *str = info->buf;

    if (info->nb_o != info->nb_x)
        return (84);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '#' && str[i] != ' ' && str[i] != '\n' && str[i] != 'P'
        && str[i] != 'X' && str[i] != 'O')
            return (84);
        if (str[i] == 'P')
            count_p++;
    }
    if (count_p != 1)
        return (84);
    return (0);
}

void help(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map  file representing the warehouse map, containing ");
    my_putstr("‘#’ for walls,\n");
    my_putstr("          ‘P’ for the player, ‘X’ for boxes and ‘O’");
    my_putstr(" for storage locations.\n");
}

int main(int ac, char const *av[])
{
    info_t *info = malloc(sizeof(info_t));
    char *error = "error";

    if (ac != 2) {return (84);}
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    }
    info->buf = open_file(av[1]);
    if (info->buf == error) {return (84);}
    info->map = str_to_arr(info->buf);
    init_player(info);
    init_box(info);
    init_place(info);
    if (error_handling(info) == 84)
        return (84);
    global_loop(info);
    if (info->end == 2)
        return (1);
    return (0);
}
