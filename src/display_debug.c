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
    my_putstr("Tetrimnos :  ");
    my_put_nbr(nbr);
    my_putchar('\n');
}

void put_name_tetriminos(tetris_t *t)
{
}

int display_debug(tetris_t *t)
{
    t->nbr_t = nbr_tetriminos("./tetriminos");
    t->names = malloc(sizeof(char *) * t->nbr_t + 1);
    t->temp = malloc(sizeof(char *) * t->nbr_t + 1);
    get_names(t);
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
    put_name_tetriminos(t);
    my_putstr("Press any key to start Tetris\n");
    return (SUCCESS);
}
