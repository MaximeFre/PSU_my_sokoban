/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** init struct
*/

#include <stdlib.h>
#include "../include/my.h"

info_t *init_player(info_t *info)
{
    for (int i = 0; info->map[i]; i++) {
        for (int j = 0; info->map[i][j]; j++) {
            if (info->map[i][j] == 'P') {
                info->player.x = j;
                info->player.y = i;
            }
        }
    }
    info->end = 1;
    return (info);
}

int count(char **map, char c)
{
    int count = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == c) {
                count++;
            }
        }
    }
    return (count);
}

info_t *init_box(info_t *info)
{
    int nb = count(info->map, 'X');
    int a = 0;
    int i = 0;
    int j = 0;
    info->box = malloc(sizeof(box_t) * nb);

    for (; info->map[i]; i++) {
        for (j = 0; info->map[i][j]; j++) {
            if (info->map[i][j] == 'X') {
                info->box[a].x = j;
                info->box[a].y = i;
                a++;
            }
        }
    }
    info->nb_x = nb;
    info->nbline = i;
    return (info);
}

info_t *init_place(info_t *info)
{
    int nb = count(info->map, 'O');
    int a = 0;
    int j = 0;
    info->nbcols = malloc(sizeof(int) * info->nbline);
    info->place = malloc(sizeof(place_t) * nb);

    for (int i = 0; info->map[i]; i++) {
        for (j = 0; info->map[i][j]; j++) {
            if (info->map[i][j] == 'O') {
                info->place[a].x = j;
                info->place[a].y = i;
                a++;
            }
        }
        info->nbcols[i] = j;
    }
    info->nb_o = nb;
    return (info);
}
