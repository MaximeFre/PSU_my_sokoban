/*
** EPITECH PROJECT, 2019
** Epitech
** File description:
** struct define
*/

#ifndef STRUCT_H
    #define STRUCT_H

typedef struct player_s {
    int x;
    int y;
} player_t;

typedef struct box_s {
    int x;
    int y;
} box_t;

typedef struct place_s {
    int x;
    int y;
} place_t;

typedef struct info_s {
    player_t player;
    box_t *box;
    place_t *place;
    char** map;
    int nbline;
    int *nbcols;
    int nb_o;
    int nb_x;
    int end;
} info_t;

#endif /* STRUCT_H_ */
