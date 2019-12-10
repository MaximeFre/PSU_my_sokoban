/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** main sokoban
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void help()
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
    char *buf;
    info_t *info = malloc(sizeof(info_t));

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    }
    buf = open_file(av[1]);
    info->map = str_to_arr(buf);
    info = init_player(info);
    info = init_box(info);
    info = init_place(info);
    global_loop(info);
    if (info->end == 2)
        return (1);
    return (0);
}
