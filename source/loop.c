/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** game loop
*/

#include <stdlib.h>
#include <ncurses.h>
#include <fcntl.h>
#include "../include/my.h"

void print_o(info_t *info)
{
    for (int i = 0; i < info->nb_o; i++) {
        if (info->map[info->place[i].y][info->place[i].x] == ' ')
            info->map[info->place[i].y][info->place[i].x] = 'O';
    }
}

void events(info_t *info)
{
    int c = getch();

    if (c == KEY_UP)
        move_up(info);
    if (c == KEY_DOWN)
        move_down(info);
    if (c == KEY_RIGHT)
        move_right(info);
    if (c == KEY_LEFT)
        move_left(info);
    print_o(info);
}

void global_loop(info_t *info)
{


    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    while (info->end == 1) {
        for (int i = 0; info->map[i] != NULL; i++) {
            mvprintw((LINES / 2) - (info->nbline / 2) + i, (COLS / 2) - (info->nbcols[0] / 2),info->map[i]);
        }
        events(info);
        check_win(info);
        check_lose(info);
        refresh();
    }
    endwin();
}
