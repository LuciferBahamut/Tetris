/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** debug mode
*/

#include "tetris.h"

void get_address(tetris_t *t)
{
    for (int i = 0; i != t->nbr_t; i++)
        t->address[i] = my_strcat("./tetriminos/", t->address[i]);
}

int get_space(char *str)
{
    int space = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            space++;
    return (space);
}

void stock_stats(tetris_t *t, char *buff, long int size, int nbr)
{
    int i = 0;
    char *stat = malloc(sizeof(char) * size);
    char **split = malloc(sizeof(char *) * 3);

    for (;buff[i] != '\n' || buff[i] == '\0'; i++)
        stat[i] = buff[i];
    buff[i] = '\0';
    printf("%s\n", stat);
    if (get_space(stat) != 2)
        t->valid[nbr] = 0;
    for (int j = 0; j != 3; j++)
        split[i] = malloc(sizeof(char) * my_strlen(stat));
    split = split_str(stat, split);    
    for (int j = 0; j != 3; j++)
        free(split[j]);
    free(split);
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
//        printf("%s %ld\n", buff, st.st_size, i);
        stock_stats(t, buff, st.st_size, i);
//        printf("\n");
        free(buff);
    }
}
