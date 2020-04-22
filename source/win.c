/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** check if game win
*/

#include <stdlib.h>
#include "../include/my.h"

void check_win(info_t *info)
{
    int count = 0;

    for (int i = 0; i < info->nb_o; i++) {
        if (info->map[info->place[i].y][info->place[i].x] == 'X')
            count++;
    }
    if (count == info->nb_o)
        info->end = 0;
}
