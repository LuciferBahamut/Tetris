/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** split the string
*/

#include "tetris.h"

int count_lines(char *tetri)
{
    int count = 0;

    for (int i = 0; tetri[i] != '\0'; i++)
        if (tetri[i] == '\n')
            count++;
    return (count);
}

void free_split(char **split, char *tetri)
{
    int count = count_lines(tetri);

    for (int i = 0; i != count; i++)
        free(split[i]);
    free(split);
}

char **clean_str(tetris_t *t)
{
    for (int i = 0; i != t->nbr_t; i++) {
        if (t->shapes[i] == NULL)
            continue;
        else if (t->shapes[i][0] == '\n') {
            for (int j = 1; t->shapes[i][j] != '\0'; j++)
                t->shapes[i][j - 1] = t->shapes[i][j];
        }
    }
    return (t->shapes);
}

char **split_tetri(tetris_t *t, int nbr)
{
    char **split = malloc(sizeof(char *) * count_lines(t->shapes[nbr]));
    int count = count_lines(t->shapes[nbr]);

    for (int i = 0; i != count; i++)
        split[i] = malloc(sizeof(char) * my_strlen(t->shapes[nbr]));
    for (int i = 0, j = 0, z = 0; t->shapes[nbr][i] != '\0'; i++, z++) {
        if (t->shapes[nbr][i] == '\n') {
            split[j][z + 1] = '\0';
            i++;
            j++;
            z = 0;
        }
        split[j][z] = t->shapes[nbr][i];
    }
    return (split);
}

char **split_str(char *str, char **tabb)
{
    int j = 0;

    for (int i = 0, z = 0; str[i] != '\0'; i++, z++) {
        if (str[i] == ' ') {
            tabb[j][z] = '\0';
            i++;
            j++;
            z = 0;
        }
        tabb[j][z] = str[i];
    }
    return (tabb);
}
