/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** split the string
*/

#include "tetris.h"

char **split_str(char *str, char **tabb)
{
    for (int i = 0, j = 0, z = 0; str[i] != '\0'; i++, z++) {
        if (str[i + 1] == ' ')
            tabb[j][z + 1] = '\0';
        if (str[i] == ' ') {
            tabb[j][z + 1] = '\0';
            i++;
            j++;
            z = 0;
        }
        tabb[j][z] = str[i];
    }
    return (tabb);
}
