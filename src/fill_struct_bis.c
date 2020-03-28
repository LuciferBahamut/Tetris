/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** fill key struct
*/

#include "tetris.h"

static char **add_text(char **score)
{
    char *text = "- Score";

    for (int i = 4, j = 0; text[j] != '\0'; j++, i++)
        score[3][i] = text[j];
    text = "- Level";
    for (int i = 4, j = 0; text[j] != '\0'; j++, i++)
        score[5][i] = text[j];
    text = "- Lines";
    for (int i = 4, j = 0; text[j] != '\0'; j++, i++)
        score[6][i] = text[j];
    text = "- Time";
    for (int i = 4, j = 0; text[j] != '\0'; j++, i++)
        score[8][i] = text[j];
    return (score);
}

static char **create_score(void)
{
    char **score = malloc(sizeof(char *) * 12);

    for (int i = 0; i != 12; i++)
        score[i] = malloc(sizeof(char) * 31);
    score[0] = "/--Score---------------------\\";
    score[10] = "\\----------------------------/";
    for (int i = 1; i != 10; i++) {
        for (int j = 0; j != 30; j++) {
            if (j == 0 || j == 29)
                score[i][j] = '|';
            else
                score[i][j] = ' ';
        }
        score[i][30] = '\0';
    }
    score = add_text(score);
    return (score);
}

static char **create_next(void)
{
    char **next = malloc(sizeof(char *) * 10);

    for (int i = 0; i != 10; i++)
        next[i] = malloc(sizeof(char) * 15);
    next[0] = "/--Next-------\\";
    next[9] = "\\-------------/";
    for (int i = 1; i != 9; i++) {
        for (int j = 0; j != 15; j++) {
            if (j == 0 || j == 14)
                next[i][j] = '|';
            else
                next[i][j] = ' ';
        }
        next[i][15] = '\0';
    }
    return (next);
}

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

void fill_keys_map(keys_t *key, map_t *m, tetris_t *t)
{
    key->left = 259;
    key->right = 258;
    key->turn = 260;
    key->drop = 261;
    key->quit = 'q';
    key->pause = ' ';
    m->map = create_map(t->size_g[0], (t->size_g[1] * 2));
    m->next = create_next();
    m->score = create_score();
    m->title = create_tetris_text();
}
