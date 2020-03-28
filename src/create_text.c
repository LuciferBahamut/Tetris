/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** create teh TETRIS text
*/

#include "tetris.h"

char **create_tetris_text(void)
{
    char **tetris = malloc(sizeof(char *) * 5);

    for (int i = 0; i != 5; i++)
        tetris[i] = malloc(sizeof(char) * 32);
    tetris[0] = "OOOOO OOOOO OOOOO OOOOO O OOOOO\0";
    tetris[1] = "  O   O       O   O   O   O    \0";
    tetris[2] = "  O   OOO     O   OOOOO O OOOOO\0";
    tetris[3] = "  O   O       O   O  O  O     O\0";
    tetris[4] = "  O   OOOOO   O   O   O O OOOOO\0";
    return (tetris);
}
