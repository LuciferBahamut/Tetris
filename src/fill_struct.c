/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** fill the structure
*/

#include "tetris.h"

void get_other_things(tetris_t *t)
{
    t->next = 1;
    t->level = 1;
    t->size_g[0] = 20;
    t->size_g[1] = 10;
}

void get_names(tetris_t *t)
{
    DIR *dir = opendir("tetriminos");
    struct dirent *read;
    char *before;

    for (int i = 0; (read = readdir(dir)) != 0; i++) {
        if (read->d_name[0] != '.') {
            before = get_full_names(read->d_name);
            t->names[i] = before;
            t->address[i] = t->names[i];
        }
        else
            i--;
    }
    closedir(dir);
    sort_names_alpha(t);
}

void get_address(tetris_t *t)
{
    for (int i = 0; i != t->nbr_t; i++) {
        t->address[i] = my_strcat("./tetriminos/", t->address[i]);
        t->address[i] = my_strcat(t->address[i], ".tetrimino");
    }
}

void get_stats(tetris_t *t)
{
    int fd = 0;
    int rd = 0;
    struct stat st;
    char *buff;

    for (int i = 0; i != t->nbr_t; i++) {
        stat(t->address[i], &st);
        fd = open(t->address[i], O_RDONLY);
        if (fd == -1) {
            t->valid[i] = 0;
            continue;
        }
        buff = malloc(sizeof(char) * st.st_size);
        rd = read(fd, buff, st.st_size);
        if (rd == -1) {
            t->valid[i] = 0;
            continue;
        }
        stock_stats(t, buff, st.st_size, i);
        free(buff);
    }
}

void fill_struct(tetris_t *t)
{
    t->nbr_t = nbr_tetriminos("./tetriminos");
    t->names = malloc(sizeof(char *) * t->nbr_t);
    t->address = malloc(sizeof(char *) * t->nbr_t);
    t->valid = malloc(sizeof(int) * t->nbr_t);
    t->color = malloc(sizeof(int) * t->nbr_t);
    t->size_t = malloc(sizeof(int *) * t->nbr_t);
    t->shapes = malloc(sizeof(char *) * t->nbr_t);
    t->size_g = malloc(sizeof(int) * 2);
    for (int i = 0; i != t->nbr_t; i++) {
        t->size_t[i] = malloc(sizeof(int) * 2);
        for (int j = 0; j != 2; j++)
            t->size_t[i][j] = 0;
        t->color[i] = 0;
        t->valid[i] = 1;
    }
    get_other_things(t);
    get_names(t);
    get_address(t);
    get_stats(t);
}
