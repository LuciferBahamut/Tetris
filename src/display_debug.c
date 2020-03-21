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

int display_debug(tetris_t *t)
{
    if (t->nbr_t == ERROR)
        return(ERROR);
    my_putstr("*** DEBUG MODE ***\n");
/*    print_key("Key Left :  ", t->key->left);
    print_key("Key Right :  ", t->key->right);
    print_key("Key Turn :  ");
    print_key("Key Drop :  ");
    print_key("Key Quit :  ");
    print_key("Key Pause :  ");
*/
    put_next("Next :  ", t->next);
    put_tetriminos_and_level("Level :  ", t->level);
    put_size("Size :  ", t->size_g);
    put_tetriminos_and_level("Tetriminos :  ", t->nbr_t);
    for (int i = 0; i != t->nbr_t; i++) {
        if (t->valid[i] == 0)
            put_name_tetriminos_inv(t->names[i]);
        else
            put_name_tetriminos_val(t->names[i], t, i);
    }
    my_putstr("Press any key to start Tetris\n");
    return (SUCCESS);
}
