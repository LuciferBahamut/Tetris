/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** debug mode
*/

#include "tetris.h"

void put_stats_in_struct(char **split, tetris_t *t, int nbr)
{
    for (int i = 0; i != 2; i++)
        t->size_t[nbr][i] = atoi(split[i]);
    t->color[nbr] = atoi(split[2]);
}

void get_tetriminos_shape(char *buff, tetris_t *t, int nbr)
{
    int i = 0;
    int j = 0;

    t->shapes[nbr] = malloc(sizeof(char) * my_strlen(buff));
    for (; buff[i] != '\n'; i++);
    for (; buff[i] != '\0'; i++)
        if ((buff[i] >= ' ' && buff[i] <= '~') || buff[i] == '\n') {
            t->shapes[nbr][j] = buff[i];
            j++;
        }
    t->shapes[nbr][j] = '\0';
}

void stock_stats(tetris_t *t, char *buff, long int size, int nbr)
{
    int i = 0;
    char *stat = malloc(sizeof(char *) * size);
    char **split = malloc(sizeof(char *) * 3);

    for (;buff[i] != '\n' || buff[i] == '\0'; i++)
        stat[i] = buff[i];
    stat[i] = '\0';
    if (get_space(stat) != 2)
        t->valid[nbr] = 0;
    for (int j = 0; j != 3; j++)
<<<<<<< HEAD
        split[j] = malloc(sizeof(char) * my_strlen(stat));
    split = split_str(stat, split);
    put_stats_in_struct(split, t, nbr);
    get_tetriminos_shape(buff, t, nbr);
=======
        split[j] = malloc(sizeof(char) * 2);
    split = split_str(stat, split);
>>>>>>> 14b4189cbe83177d65f45dd2cad9d28324e4de0c
    for (int j = 0; j != 3; j++)
        free(split[j]);
    free(split);
    free(stat);
}

