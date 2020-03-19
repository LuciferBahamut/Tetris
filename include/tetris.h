/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** .h
*/

#ifndef __TETRIS_H__
#define __TETRIS_H__

#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct tetris_st
{
    char **names;
    char **address;
    int *valid;
    int **size_t;
    int nbr_t;
} tetris_t;

void fill_struct(tetris_t *t);
void get_stats(tetris_t *t);
char **split_str(char *str, char **tab);

char *point(char *name);
int nbr_tetriminos(char *str);
void get_names(tetris_t *t);
void get_address(tetris_t *t);

void display_help(void);
int display_debug(tetris_t *t);

void my_putchar(char c);
int my_strcmp(char const *str1, char const *str2);
char *my_strcat(char *dest, char const *src);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int my_strlen(char *const str);
void write_error(char *str);

#define ERROR 84
#define SUCCESS 0

#define STR_ERROR_DIR "could not open directory\n"

#endif
