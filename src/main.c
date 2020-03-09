/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "tetris.h"

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "--help") == 1) {
        display_help();
        return (0);
    }
    return (0);
}
