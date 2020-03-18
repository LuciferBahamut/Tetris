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

typedef struct tetris_st
{
    char **names;
    char **temp;
    int nbr_t;
} tetris_t;

char *point(char *name);
int nbr_tetriminos(char *str);
void get_names(tetris_t *t);

void display_help(void);
int display_debug(tetris_t *t);

void my_putchar(char c);
int my_strcmp(char const *str1, char const *str2);
void my_putstr(char const *str);
void my_put_nbr(int nb);
int my_strlen(char *const str);
void write_error(char *str);
void display_help(void);

#define ERROR 84
#define SUCCESS 0

#define STR_ERROR_DIR "could not open directory\n"

#endif
