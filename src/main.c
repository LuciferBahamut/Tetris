/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** main
*/

#include "tetris.h"

struct option op[] =
{
    {"help", 0, 0, 1},
    {0, 0, 0, 0}
};

int main(int ac, char **av)
{
    switch (getopt_long(ac, av, "", op, NULL)) {
    case 1 : display_help();
        return (0);
    }
    return (0);
}
