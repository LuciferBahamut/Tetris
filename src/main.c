/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "tetris.h"

static void free_key(keys_t *key)
{
    free(key->left);
    free(key->right);
    free(key->turn);
    free(key->drop);
    free(key->quit);
    free(key->pause);
    free(key);
}

static void free_struct(tetris_t *t, keys_t *key)
{
    for (int i = 0; i != t->nbr_t; i++) {
        free(t->shapes[i]);
        free(t->address[i]);
        free(t->names[i]);
        free(t->size_t[i]);
    }
    free(t->color);
    free(t->names);
    free(t->address);
    free(t->valid);
    free(t->shapes);
    free(t->size_t);
    free(t->size_g);
    free(t);
//    free_key(key);
}

static void init_read(void)
{
    char *buffer = malloc(sizeof(char) * 2);
    static struct termios old;
    static struct termios new;

    ioctl(0, TCGETS, &old);
    ioctl(0, TCGETS, &new);
    new.c_lflag &= ~ECHO;
    new.c_lflag &= ~ICANON;
    new.c_cc[VMIN] = 1;
    new.c_cc[VTIME] = 0;
    ioctl(0, TCSETS, &new);
    read(0, buffer, 1);
    free(buffer);
    ioctl(0, TCSETS, &old);
}

int main(int ac, char **av)
{
    tetris_t *t = malloc(sizeof(tetris_t));
    keys_t *key = malloc(sizeof(keys_t));

    fill_struct(t, key);
    gest_arg_long(ac, av, key, t);
    if (t->debug != 0) {
        display_debug(t, key);
        init_read();
    }
    free_struct(t, key);
    return (0);
}
