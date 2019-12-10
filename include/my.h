/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** c
*/

#ifndef MY_H_
    #define MY_H_

#include <ncurses.h>
#include "struct.h"

char *open_file(char const *filepath);
char **str_to_arr(char *file);
void my_putstr(char const *str);
info_t *init_player(info_t *info);
info_t *init_box(info_t *info);
info_t *init_place(info_t *info);
void global_loop(info_t *info);
void move_up(info_t *info);
void move_down(info_t *info);
void move_right(info_t *info);
void move_left(info_t *info);
void move_boxup(info_t *info);
void move_boxdown(info_t *info);
void move_boxright(info_t *info);
void move_boxleft(info_t *info);
void check_win(info_t *info);
void check_lose(info_t *info);

#endif /* MY_H_ */
