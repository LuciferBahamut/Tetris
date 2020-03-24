/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** display the debug menu
*/

#include "tetris.h"

void my_special_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\033')
            my_putstr("^E");
        else
            my_putchar(str[i]);
    }
}

void my_putstr_key(char *key)
{
    if (key[0] == ' ')
        my_putstr("(space)");
    else
        my_putstr(key);
}

void print_key(char *str, char *key)
{
    my_putstr(str);
    if (my_strlen(key) != 1)
        my_special_putstr(key);
    else
        my_putstr_key(key);
    my_putchar('\n');
}

int display_debug(tetris_t *t, keys_t *key)
{
    if (t->nbr_t == ERROR)
        return (ERROR);
    my_putstr("*** DEBUG MODE ***\n");
    print_key("Key Left :  ", key->left);
    print_key("Key Right :  ", key->right);
    print_key("Key Turn :  ", key->turn);
    print_key("Key Drop :  ", key->drop);
    print_key("Key Quit :  ", key->quit);
    print_key("Key Pause :  ", key->pause);
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
