/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** count the number of tetriminos files
*/

#include "tetris.h"

char *get_after_point(char *name)
{
    int point = 0;
    char *after = malloc(sizeof(char) * my_strlen(name));

    for (int i = 0, j = 0; name[i] != '\0'; i++) {
        if (name[i] == '.')
            point++;
        if (point >= 1)
            for (; name[i] != '\0'; j++, i++)
                after[j] = name[i];
        else
            continue;
    }
    return (after);
}

void get_full_names(tetris_t *t, char *str)
{
    DIR *dir = opendir(str);
    struct dirent *read;
    char *after;

    for (int i = 0; (read = readdir(dir)) != 0;) {
        after = get_after_point(read->d_name);
        if (my_strcmp(after, ".tetrimino")) {
            t->names[i] = read->d_name;
            i++;
        }
        free(after);
    }
//    for (int i = 0; i != t->nbr_t; i++)
//        printf("%s\n", t->names[i]);
    closedir(dir);
}

void get_names(tetris_t *t)
{
    int point = 0;

    get_full_names(t, "./tetriminos");
}

int nbr_tetriminos(char *str)
{
    DIR *dir = opendir(str);
    struct dirent *read;
    int nbr = 0;
    char *after;

    if (dir == NULL) {
        write_error(STR_ERROR_DIR);
        return (ERROR);
    }
    while ((read = readdir(dir)) != 0) {
        after = get_after_point(read->d_name);
        if (my_strcmp(after, ".tetrimino"))
            nbr = nbr + 1;
        free(after);
    }
    closedir(dir);
    return (nbr + 1);
}
