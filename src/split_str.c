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
        if (str[i + 1] == ' ')
            tab[j][z + 1] = '\0';
        if (str[i] == ' ') {
            tab[j][z + 1] = '\0';
            i++;
            j++;
            z = 0;
        }
        tab[j][z] = str[i];
    }
    for (int i = 0, len = 0; i != 3; i++) {
        len = my_strlen(tab[i]);
        printf("%s %d\n", tab[i], len);
    }
    return (tab);
}
