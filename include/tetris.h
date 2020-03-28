/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** .h
*/

#ifndef __TETRIS_H__
#define __TETRIS_H__

#include <getopt.h>
#include <curses.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <time.h>

typedef struct keys_st
{
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
} keys_t;

typedef struct map_st
{
    char **map;
    char **next;
    char **score;
    char **title;
} map_t;

typedef struct tetris_st
{
    char **names;
    char **address;
    int *valid;
    int *color;
    int **size_t;
    char **shapes;
    int nbr_t;
    int level;
    int next;
    int *size_g;
    int debug;
} tetris_t;

int fill_struct(tetris_t *t, keys_t *key, map_t *m);
void fill_keys_map(keys_t *key, map_t *m, tetris_t *t);
void get_stats(tetris_t *t);
int get_space(char *str);
char **split_str(char *str, char **tabb);
void stock_stats(tetris_t *t, char *buff, long int size, int nbr);
char *get_full_names(char *name);
char **create_tetris_text(void);

int gest_arg_long(int ac, char **av, keys_t *key, tetris_t *t);

char *point(char *name);
int nbr_tetriminos(char *str);
void get_names(tetris_t *t);
void sort_names_alpha(tetris_t *t);

void get_address(tetris_t *t);

int display_help(char *bin_name);
int display_debug(tetris_t *t, keys_t *key);
void put_tetriminos_and_level(char *str, int nbr);
void put_name_tetriminos_val(char *name, tetris_t *t, int nbr);
void put_name_tetriminos_inv(char *name);
void put_next(char *str, int next);
void put_size(char *str, int *size);

void game(tetris_t *t, keys_t *key, map_t *m);

void my_putchar(char c);
int my_strcmp(char *str1, char const *str2);
int my_strcmp_s(char const *str1, char const *str2);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int my_strlen(char *const str);
int my_atoi(char *str);
void write_error(char *str);

#define ERROR 84
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

#define STR_ERROR_DIR "could not open directory\n"

#endif
