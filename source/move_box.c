/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** move box
*/

#include <stdlib.h>
#include "../include/my.h"

void move_boxup(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y - 1][x] == 'X' && map[y - 2][x] == ' ') {
        info->map[y][x] = ' ';
        info->map[y - 1][x] = 'P';
        info->map[y - 2][x] = 'X';
        info->player.y -= 1;
    }
    if (map[y - 1][x] == 'X' && map[y - 2][x] == 'O') {
        info->map[y][x] = ' ';
        info->map[y - 1][x] = 'P';
        info->map[y - 2][x] = 'X';
        info->player.y -= 1;
    }
}

void move_boxdown(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y + 1][x] == 'X' && map[y + 2][x] == ' ') {
        info->map[y][x] = ' ';
        info->map[y + 1][x] = 'P';
        info->map[y + 2][x] = 'X';
        info->player.y += 1;
    }
    if (map[y + 1][x] == 'X' && map[y + 2][x] == 'O') {
        info->map[y][x] = ' ';
        info->map[y + 1][x] = 'P';
        info->map[y + 2][x] = 'X';
        info->player.y += 1;
    }
}

void move_boxright(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y][x + 1] == 'X' && map[y][x + 2] == ' ') {
        info->map[y][x] = ' ';
        info->map[y][x + 1] = 'P';
        info->map[y][x + 2] = 'X';
        info->player.x += 1;
    }
    if (map[y][x + 1] == 'X' && map[y][x + 2] == 'O') {
        info->map[y][x] = ' ';
        info->map[y][x + 1] = 'P';
        info->map[y][x + 2] = 'X';
        info->player.x += 1;
    }
}

void move_boxleft(info_t *info)
{
    char **map = info->map;
    int x = info->player.x;
    int y = info->player.y;

    if (map[y][x - 1] == 'X' && map[y][x - 2] == ' ') {
        info->map[y][x] = ' ';
        info->map[y][x - 1] = 'P';
        info->map[y][x - 2] = 'X';
        info->player.x -= 1;
    }
    if (map[y][x - 1] == 'X' && map[y][x - 2] == 'O') {
        info->map[y][x] = ' ';
        info->map[y][x - 1] = 'P';
        info->map[y][x - 2] = 'X';
        info->player.x -= 1;
    }
}
