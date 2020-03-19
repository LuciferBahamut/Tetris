/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** display the debug menu
*/

#include "tetris.h"

void print_key(char *str, char *key)
{
    my_putstr(str);
    my_putstr(key);
    my_putchar('\n');
}

void put_nbr_tetriminos(int nbr)
{
    my_putstr("Tetriminos :  ");
    my_put_nbr(nbr);
    my_putchar('\n');
}

void put_name_tetriminos_val(char *name)//, int *dim, int color)
{
    my_putstr("Tetriminos :  Name ");
    my_putstr(name);
    my_putstr("  :  \n");
}

void put_name_tetriminos_inv(char *name)//, int *dim, int color)
{
    my_putstr("Tetriminos :  Name ");
    my_putstr(name);
    my_putstr("  :  Error\n");
}

int display_debug(tetris_t *t)
{
    if (t->nbr_t == ERROR)
        return(ERROR);
    my_putstr("*** DEBUG MODE ***\n");
/*    print_key("Key Left :  ");
    print_key("Key Right :  ");
    print_key("Key Turn :  ");
    print_key("Key Drop :  ");
    print_key("Key Quit :  ");
    print_key("Key Pause :  ");
*/
//    my_putstr("Next :  ");
//    my_putstr("Level :  ");
//    my_putstr("Size :  ");
    put_nbr_tetriminos(t->nbr_t);
    for (int i = 0; i != t->nbr_t; i++) {
        if (t->valid[i] == 0)
            put_name_tetriminos_inv(t->names[i]);
        else
            put_name_tetriminos_val(t->names[i]);
    }
    my_putstr("Press any key to start Tetris\n");
    return (SUCCESS);
}
