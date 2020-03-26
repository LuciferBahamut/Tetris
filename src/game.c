/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** ncurse
*/

#include "tetris.h"

static char **create_map(int nbl, int nbc)
{
    char **map = malloc(sizeof(char *) * nbl);

    for (int i = 0; i != nbl; i++) {
        map[i] = malloc(sizeof(char) * nbc + 1);
        for (int j = 0; j != nbc; j++) {
            if (j == 0 || j == nbc - 1)
                map[i][j] = '|';
            else if (i == 0 || i == nbl - 1) {
                if (j != 0 && j != nbc - 1)
                    map[i][j] = '-';
            }
            else
                map[i][j] = ' ';
        }
        map[i][nbc] = '\0';
    }
    map[0][0] = '/';
    map[nbl - 1][0] = '\\';
    map[nbl - 1][nbc - 1] = '/';
    map[0][nbc - 1] = '\\';
    return (map);
}

static void window(int *nb, char **map, tetris_t *t, keys_t *key)
{
    int g;

    while (1) {
        clear();
        for (int i = 0; i < nb[0]; i++)
            mvprintw((LINES / 2) - nb[0] + i, (COLS / 2) - (nb[1] / 2), map[i]);
        refresh();
        g = getch();
        if (g == 32)
            break;
    }
}

void game(tetris_t *t, keys_t *key)
{
    char **map = create_map(t->size_g[0], (t->size_g[1] * 2));

    t->size_g[1] = t->size_g[1] * 2;
    initscr();
    keypad(stdscr, TRUE);
    window(t->size_g, map, t, key);
    endwin();
    free(map);
}
