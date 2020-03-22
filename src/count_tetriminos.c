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
    int j = 0;
    char *after = malloc(sizeof(char) * my_strlen(name));

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '.')
            point++;
        if (point >= 1)
            for (; name[i] != '\0'; j++, i++)
                after[j] = name[i];
        else
            continue;
    }
    for (j = 0; after[j] != 'o'; j++);
    after[j+1] = '\0';
    return (after);
}

char *get_full_names(char *name)
{
    char *before = malloc(sizeof(char) * my_strlen(name));

    for (int i = 0; name[i] != '\0'; i++) {
        if (name[i] == '.') {
            before[i] = '\0';
            break;
        }
        else
            before[i] = name[i];
    }
    return (before);
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
    while ((read = readdir(dir)) != 0)
        if (read->d_name[0] != '.') {
            after = get_after_point(read->d_name);
            if (my_strcmp_s(after, ".tetrimino"))
                nbr = nbr + 1;
            free(after);
        }
    closedir(dir);
    return (nbr);
}
