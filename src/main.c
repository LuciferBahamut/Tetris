/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "tetris.h"

struct option op_l[] =
{
    {"help", 0, 0, 1},
    {"level=", 0, 0, 2},
    {"key-left=", 0, 0, 3},
    {"key-right=", 0, 0, 4},
    {"key-turn=", 0, 0, 5},
    {"key-drop=", 0, 0, 6},
    {"key-quit=", 0, 0, 7},
    {"key-pause=", 0, 0, 8},
    {"map-size=", 0, 0, 9},
    {"without-next", 0, 0, 10},
    {"debug", 0, 0, 11},
    {0, 0, 0, 0}
};

void free_struct(tetris_t *t)
{
    for (int i = 0; i != t->nbr_t; i++) {
        free(t->shapes[i]);
        free(t->address[i]);
        free(t->names[i]);
        free(t->size_t[i]);
    }
    free(t->color);
    free(t->names);
    free(t->address);
    free(t->valid);
    free(t->shapes);
    free(t);
}

int main(int ac, char **av)
{
    tetris_t *t = malloc(sizeof(tetris_t));

    fill_struct(t);
    switch (getopt_long(ac, av, "", op_l, NULL)) {
    case 1 : return (display_help());
    case 11 : display_debug(t);
        free_struct(t);
        return (0);
    }
    free_struct(t);
    return (0);
}
