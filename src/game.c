/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** ncurse
*/

#include "tetris.h"

static void window(map_t *m, tetris_t *t, keys_t *key)
{
    int g;
    int x = t->size_g[0];
    int y = t->size_g[1] / 2;

    while (1) {
        clear();
        for (int i = 0; i < t->size_g[0]; i++)
            mvprintw((LINES / 2) - x + i, (COLS / 2) - y, m->map[i]);
        for (int i = 0; i < 10; i++)
            mvprintw(6 + i, ((COLS / 2) - y) + (t->size_g[1] + 4), m->next[i]);
        for (int i = 0; i < 20; i++)
            mvprintw((LINES / 4) + i, (COLS - (COLS / 2)) - t->size_g[1], m->score[i]);
        refresh();
        g = getch();
        if (g == 32)
            break;
    }
}

void game(tetris_t *t, keys_t *key, map_t *m)
{
    t->size_g[1] = t->size_g[1] * 2;
    initscr();
    keypad(stdscr, TRUE);
    window(m, t, key);
    endwin();
}
