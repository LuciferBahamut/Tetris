/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** print the debug
*/

#include "tetris.h"

void put_tetriminos_and_level(char *str, int nbr)
{
    my_putstr(str);
    my_put_nbr(nbr);
    my_putchar('\n');
}

void put_name_tetriminos_val(char *name, tetris_t *t, int nbr)
{
    my_putstr("Tetriminos :  Name ");
    my_putstr(name);
    my_putstr("  :  Size ");
    my_put_nbr(t->size_t[nbr][0]);
    my_putchar('*');
    my_put_nbr(t->size_t[nbr][1]);
    my_putstr(" :  Color ");
    my_put_nbr(t->color[nbr]);
    my_putstr(" :");
    my_putstr(t->shapes[nbr]);
}

void put_name_tetriminos_inv(char *name)
{
    my_putstr("Tetriminos :  Name ");
    my_putstr(name);
    my_putstr("  :  Error\n");
}

void put_next(char *str, int next)
{
    my_putstr(str);
    if (next == 1)
        my_putstr("Yes\n");
    else
        my_putstr("No\n");
}

void put_size(char *str, int *size)
{
    my_putstr(str);
    my_put_nbr(size[0]);
    my_putchar('*');
    my_put_nbr(size[1]);
    my_putchar('\n');
}
