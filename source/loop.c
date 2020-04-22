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

void print_map(info_t *info)
{
    if (LINES < info->nbline || COLS < info->nbcols[0])
        mvprintw((LINES / 2) - 10, (COLS / 2), "resize the terminal");
    else {
        for (int i = 0; info->map[i] != NULL; i++) {
            mvprintw((LINES / 2) - (info->nbline / 2) + i, (COLS / 2)
            - (info->nbcols[0] / 2),info->map[i]);
        }
    }
}

void print_o(info_t *info)
{
    for (int i = 0; i < info->nb_o; i++) {
        if (info->map[info->place[i].y][info->place[i].x] == ' ')
            info->map[info->place[i].y][info->place[i].x] = 'O';
    }
}

void check_restart(info_t *info)
{
    int i = 0;

    for (; info->map[i] != NULL; i++)
        free(info->map[i]);
    free(info->map[i]);
    free(info->box);
    free(info->place);
    info->map = str_to_arr(info->buf);
    init_player(info);
    init_box(info);
    init_place(info);
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
    if (c == ' ')
        check_restart(info);
    print_o(info);
}

void global_loop(info_t *info)
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(FALSE);
    while (info->end == 1) {
        print_map(info);
        events(info);
        check_win(info);
        check_lose(info);
        refresh();
    }
    print_map(info);
    refresh();
    endwin();
}
