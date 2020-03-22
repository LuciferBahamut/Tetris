/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** sort the tetriminos names by alphabetical order
*/

#include "tetris.h"

void sort_names_alpha(tetris_t *t)
{
    int j = 0;
    char *temp;

    for (int i = 0; i != t->nbr_t; i++) {
        for (j = i + 1; j != t->nbr_t; j++) {
            if (my_strcmp(t->names[i], t->names[j]) > 0) {
                temp = malloc(sizeof(char) * (my_strlen(t->names[i]) + 1));
                my_strcpy(temp, t->names[i]);
                my_strcpy(t->names[i], t->names[j]);
                my_strcpy(t->names[j], temp);
                free(temp);
            }
        }
    }
}
