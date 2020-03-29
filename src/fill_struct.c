/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** fill the structure
*/

#include "tetris.h"

static void get_other_things(tetris_t *t)
{
    for (int i = 0; i != t->nbr_t; i++) {
        t->size_t[i] = malloc(sizeof(int) * 2);
        for (int j = 0; j != 2; j++)
            t->size_t[i][j] = 0;
        t->color[i] = 0;
        t->valid[i] = 1;
    }
    t->next = 1;
    t->level = 1;
    t->size_g[0] = 20;
    t->size_g[1] = 10;
    t->debug = 0;
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
    int op[2] = {0, 0};
    struct stat st;
    char *buff;

    for (int i = 0; i != t->nbr_t; i++) {
        stat(t->address[i], &st);
        op[0] = open(t->address[i], O_RDONLY);
        if (op[0] == -1) {
            t->valid[i] = 0;
            continue;
        }
        buff = malloc(sizeof(char) * st.st_size);
        op[1] = read(op[0], buff, st.st_size);
        if (op[1] == -1 || op[1] == 0) {
            t->valid[i] = 0;
            continue;
        }
        if (t->valid[i] != 0)
            stock_stats(t, buff, st.st_size, i);
        free(buff);
    }
}

int fill_struct(tetris_t *t, keys_t *key, map_t *m)
{
    t->nbr_t = nbr_tetriminos("./tetriminos");
    if (t->nbr_t == 84 || t->nbr_t == 0)
        return (ERROR);
    t->names = malloc(sizeof(char *) * t->nbr_t);
    t->address = malloc(sizeof(char *) * t->nbr_t);
    t->valid = malloc(sizeof(int) * t->nbr_t);
    t->color = malloc(sizeof(int) * t->nbr_t);
    t->size_t = malloc(sizeof(int *) * t->nbr_t);
    t->shapes = malloc(sizeof(char *) * t->nbr_t);
    t->size_g = malloc(sizeof(int) * 2);
    get_other_things(t);
    get_names(t);
    get_address(t);
    get_stats(t);
    fill_keys_map(key, m, t);
    return (SUCCESS);
}
