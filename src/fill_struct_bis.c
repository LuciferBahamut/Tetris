/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** fill key struct
*/

#include "tetris.h"

void fill_keys(keys_t *key)
{
    int term = setupterm(NULL, STDOUT_FILENO, NULL);

    key->left = malloc(sizeof(char) * 10);
    key->left = tigetstr("kcub1");
    key->right = malloc(sizeof(char) * 10);
    key->right = tigetstr("kcuf1");
    key->turn = malloc(sizeof(char) * 10);
    key->turn = tigetstr("kcuu1");
    key->drop = malloc(sizeof(char) * 10);
    key->drop = tigetstr("kcud1");
    key->quit = malloc(sizeof(char) * 10);
    key->quit = "q";
    key->pause = malloc(sizeof(char) * 10);
    key->pause = " ";
    term = term + 1;
}
