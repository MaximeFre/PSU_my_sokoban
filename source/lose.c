/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** check if lose
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void update_coor(info_t *info)
{
    int a = 0;

    for (int i = 0; info->map[i]; i++) {
        for (int j = 0; info->map[i][j]; j++) {
            if (info->map[i][j] == 'X') {
                info->box[a].x = j;
                info->box[a].y = i;
                a++;
            }
        }
    }
}

int check_corner(info_t *info, int i)
{
    char **map = info->map;
    int x = info->box[i].x;
    int y = info->box[i].y;

    if (map[y - 1][x] == '#' && map[y][x - 1] == '#')
        return (1);
    if (map[y - 1][x] == '#' && map[y][x + 1] == '#')
        return (1);
    if (map[y + 1][x] == '#' && map[y][x - 1] == '#')
        return (1);
    if (map[y + 1][x] == '#' && map[y][x + 1] == '#')
        return (1);
    return (0);
}

void check_lose(info_t *info)
{
    int count = 0;

    update_coor(info);
    for (int i = 0; i < info->nb_x; i++) {
        if (check_corner(info, i) != 0)
            count++;
    }
    if (count == info->nb_x)
        info->end = 0;
}
