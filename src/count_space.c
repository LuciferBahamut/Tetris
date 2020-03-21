/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** count the spaces
*/

#include "tetris.h"

int get_space(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            space++;
    return (space);
}
