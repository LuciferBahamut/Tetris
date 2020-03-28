/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** display the debug menu
*/

#include "tetris.h"

static void my_putstr_key_dir(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\033')
            my_putstr("^E");
        else
            my_putchar(str[i]);
    }
}

static void handle_other_key(int key, char *key_dir, int term)
{
    if (key == 260) {
        key_dir = my_strcpy(key_dir, tigetstr("kcuu1"));
        my_putstr_key_dir(key_dir);
    }
    if (key == 261) {
        key_dir = my_strcpy(key_dir, tigetstr("kcud1"));
        my_putstr_key_dir(key_dir);
    }
    term++;
}

static void my_special_putstr(int key)
{
    int term = setupterm(NULL, STDOUT_FILENO, NULL);
    char *key_dir = malloc(sizeof(char) * 10);

    if (key >= 258 && key <= 261) {
        if (key == 258) {
            key_dir = my_strcpy(key_dir, tigetstr("kcub1"));
            my_putstr_key_dir(key_dir);
        }
        if (key == 259) {
            key_dir = my_strcpy(key_dir, tigetstr("kcuf1"));
            my_putstr_key_dir(key_dir);
        } else {
            handle_other_key(key, key_dir, term);
            return;
        }
    }
    if (key == ' ')
        my_putstr("(space)");
    else
        my_putchar(key);
    free(key_dir);
}

static void print_key(char *str, int key)
{
    my_putstr(str);
    my_special_putstr(key);
    my_putchar('\n');
}

int display_debug(tetris_t *t, keys_t *key)
{
    if (t->nbr_t == ERROR)
        return (ERROR);
    my_putstr("*** DEBUG MODE ***\n");
    print_key("Key Left :  ", key->left);
    print_key("Key Right :  ", key->right);
    print_key("Key Turn :  ", key->turn);
    print_key("Key Drop :  ", key->drop);
    print_key("Key Quit :  ", key->quit);
    print_key("Key Pause :  ", key->pause);
    put_next("Next :  ", t->next);
    put_tetriminos_and_level("Level :  ", t->level);
    put_size("Size :  ", t->size_g);
    put_tetriminos_and_level("Tetriminos :  ", t->nbr_t);
    for (int i = 0; i != t->nbr_t; i++) {
        if (t->valid[i] == 0)
            put_name_tetriminos_inv(t->names[i]);
        else
            put_name_tetriminos_val(t->names[i], t, i);
    }
    my_putstr("Press any key to start Tetris\n");
    return (SUCCESS);
}
