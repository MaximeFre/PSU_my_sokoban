/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** move player
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void move_up(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y - 1][x] == ' ') {
        info->map[y][x] = ' ';
        info->map[y - 1][x] = 'P';
        info->player.y -= 1;
    }
    else if (map[y - 1][x] == 'O') {
        info->map[y][x] = ' ';
        info->map[y - 1][x] = 'P';
        info->player.y -= 1;
    }
    else
        move_boxup(info);
}

void move_down(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y + 1][x] == ' ') {
        info->map[y][x] = ' ';
        info->map[y + 1][x] = 'P';
        info->player.y += 1;
    }
    else if (map[y + 1][x] == 'O') {
        info->map[y][x] = ' ';
        info->map[y + 1][x] = 'P';
        info->player.y += 1;
    }
    else
        move_boxdown(info);
}

void move_right(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y][x + 1] == ' ') {
        info->map[y][x] = ' ';
        info->map[y][x + 1] = 'P';
        info->player.x += 1;
    }
    else if (map[y][x + 1] == 'O') {
        info->map[y][x] = ' ';
        info->map[y][x + 1] = 'P';
        info->player.x += 1;
    }
    else
        move_boxright(info);
}

void move_left(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y][x - 1] == ' ') {
        info->map[y][x] = ' ';
        info->map[y][x - 1] = 'P';
        info->player.x -= 1;
    }
    else if (map[y][x - 1] == 'O') {
        info->map[y][x] = ' ';
        info->map[y][x - 1] = 'P';
        info->player.x -= 1;
    }
    else
        move_boxleft(info);
}
