/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** split the string
*/

#include "tetris.h"

char **split_str(char *str, char **tab)
{
    for (int i = 0, j = 0, z = 0; str[i] != '\0'; i++, z++) {
        if (str[i] == ' ') {
            i++;
            j++;
            z = 0;
        }
        printf("%d, %c\n", j, str[i]);
        tab[j][z] = str[i];
    }
    for (int u = 0; u != 3; u++)
        printf("%s", tab[u]);
    return (tab);
}
