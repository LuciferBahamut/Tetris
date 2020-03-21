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
            tab[j][z] = '\0';
            i++;
            j++;
            z = 0;
        }
        if (str[i] >= '0' && str[i] <= '9')
            tab[j][z] = str[i];
        else {
            tab[j] = NULL;
            i++;
            j++;
            z = 0;
        }
<<<<<<< HEAD
        tab[j][z] = str[i];
=======
>>>>>>> 14b4189cbe83177d65f45dd2cad9d28324e4de0c
    }
    return (tab);
}
