/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** display_help
*/

#include "tetris.h"
#include "help.h"

int display_help(char *bin_name)
{
    my_putstr(USAGE);
    my_putstr(bin_name);
    my_putstr(USAGE2);
    my_putstr(OPTIONS);
    my_putstr(OPTIONS1);
    my_putstr(OPTIONS2);
    my_putstr(OPTIONS3);
    my_putstr(OPTIONS4);
    my_putstr(OPTIONS5);
    my_putstr(OPTIONS6);
    my_putstr(OPTIONS7);
    my_putstr(OPTIONS8);
    my_putstr(OPTIONS9);
    my_putstr(OPTIONSA);
    my_putstr(OPTIONSB);
    my_putstr(OPTIONSC);
    return (1);
}
