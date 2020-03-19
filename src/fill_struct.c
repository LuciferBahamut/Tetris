/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** fill the structure
*/

#include "tetris.h"

void fill_struct(tetris_t *t)
{
    t->nbr_t = nbr_tetriminos("./tetriminos");
    t->names = malloc(sizeof(char *) * t->nbr_t);
    t->address = malloc(sizeof(char *) * t->nbr_t);
    t->valid = malloc(sizeof(int) * t->nbr_t);
    t->size_t = malloc(sizeof(int *) * t->nbr_t);
    for (int i = 0; i != t->nbr_t; i++) {
        t->size_t[i] = malloc(sizeof(int) * 2);
        for (int j = 0; j != 2; j++)
            t->size_t[i][j] = 0;
        t->valid[i] = 1;
    }
    get_names(t);
    get_address(t);
    get_stats(t);
}
