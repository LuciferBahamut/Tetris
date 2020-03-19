/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** split the string
*/

#include "tetris.h"

char **split_str(char *str, char **tab)
{
    for (int i = 0, j = 0, z = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            i++;
            j++;
            z = 0;
        }
        tab[j][z] = str[i];
    }
    for (int i = 0; i != 3; i++)
        printf("%s\n", tab[i]);
    return (tab);
}
