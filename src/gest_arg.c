/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** gest arg
*/

#include "tetris.h"

struct option op_l[] =
{
    {"help", 0, NULL, 1},
    {"level", 1, NULL, 'L'},
    {"key-left", 1, NULL, 'l'},
    {"key-right", 1, NULL, 'r'},
    {"key-turn", 1, NULL, 't'},
    {"key-drop", 1, NULL, 'd'},
    {"key-quit", 1, NULL, 'q'},
    {"key-pause", 1, NULL, 'p'},
    {"map-size", 1, NULL, 2},
    {"without-next", 0, NULL, 'w'},
    {"debug", 0, NULL, 'D'},
    {0, 0, 0, 0}
};

static void verif_nbr(tetris_t *t, char *str)
{
    if (my_atoi(str) != 0)
        t->level = my_atoi(str);
}

static void get_size(tetris_t *t, char *str)
{
    int i = 0;
    int j = 0;
    char *strb = malloc(sizeof(char) * 3);

    if (my_atoi(str) != 0)
        t->size_g[0] = my_atoi(str);
    for (i = 0; str[i] != ','; i++);
    i++;
    for (j = 0; str[i] != '\0'; i++, j++)
        strb[j] = str[i];
    strb[j + 1] = '\0';
    if (my_atoi(strb) != 0)
        t->size_g[1] = my_atoi(strb);
    free(strb);
}

static void gest_arg_long_bis(char c, keys_t *key, tetris_t *t, char *str)
{
    switch (c) {
    case 'd' : key->drop = optarg;
        break;
    case 'q' : key->quit = str;
        break;
    case 'p' : key->pause = str;
        break;
    case 2 : get_size(t, str);
        break;
    case 'w' : t->next = 0;
        break;
    case 'D' : t->debug = 1;
        break;
    }
}

int gest_arg_long(int ac, char **av, keys_t *key, tetris_t *t)
{
    char c = 0;

    while (1) {
        c = getopt_long(ac, av, "1L:l:r:t:d:q:p:2:wD", op_l, NULL);
        switch (c) {
        case 1 : return (display_help(av[0]));
        case 'L' : verif_nbr(t, optarg);
            break;
        case 'l' : key->left = optarg;
            break;
        case 'r' : key->right = optarg;
            break;
        case 't' : key->turn = optarg;
            break;
        }
        gest_arg_long_bis(c, key, t, optarg);
        if (c == -1)
            break;
    }
    return (0);
}
