/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** ncurse
*/

#include "tetris.h"

void init_pair_color(void)
{
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

static void display_title(char **title)
{
    attron(COLOR_PAIR(1));
    mvprintw(5, 10, title[0]);
    attron(COLOR_PAIR(3));
    mvprintw(6, 10, title[1]);
    attron(COLOR_PAIR(2));
    mvprintw(7, 10, title[2]);
    attron(COLOR_PAIR(6));
    mvprintw(8, 10, title[3]);
    attron(COLOR_PAIR(4));
    mvprintw(9, 10, title[4]);
    attroff(COLOR_PAIR(4));
}

static void print_next_tetri(tetris_t *t)
{
    int rdm = rand() % t->nbr_t;

    while (t->valid[rdm] != 1)
        rdm = rand() % t->nbr_t;
    attron(COLOR_PAIR(t->color[rdm]));
//    for (int i = 0; i !=)
    mvprintw(35, 35, t->shapes[rdm]);
    attroff(COLOR_PAIR(t->color[rdm]));
}

static void window(map_t *m, tetris_t *t, keys_t *key)
{
    int g;
    int x = t->size_g[0];
    int y = t->size_g[1] / 2;

    while (1) {
        clear();
        print_next_tetri(t);
        display_title(m->title);
        for (int i = 0; i < t->size_g[0]; i++)
            mvprintw((LINES / 2) - x + i, (COLS / 2) - y, m->map[i]);
        for (int i = 0; i < 10; i++)
            mvprintw(6 + i, ((COLS / 2) - y) + (t->size_g[1] + 4), m->next[i]);
        for (int i = 0; i < 15; i++)
            mvprintw((LINES / 4) + i, 10, m->score[i]);
        refresh();
        g = getch();
        if (g == 32)
            break;
    }
}

void split_tetri(tetris_t *t)
{
    for (int i = 0; i != t->nbr_t; i++)
        if (t->shapes[i][0] == '\n') {
            for (int j = 1; t->shapes[i][j] != '\0'; j++)
                t->shapes[i][j - 1] = t->shapes[i][j];
        }
}

void game(tetris_t *t, keys_t *key, map_t *m)
{
    t->size_g[1] = t->size_g[1] * 2;
    srand(time(0));
    initscr();
    curs_set(0);
    init_pair_color();
    keypad(stdscr, TRUE);
    window(m, t, key);
    endwin();
}
