/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** display_help
*/

#include "tetris.h"

#define USAGE "Usage:  ./tetris [options]\nOptions:\n"
#define OPTIONS " --help\t\t\tDisplay this help\n -L --level={num}\t"
#define OPTIONS1 "Start Tetris at level num (def: 1)\n -l --key-left={K}\t"
#define OPTIONS2 "Move the tetrimino LEFT using the K key (def: left arrow)\n "
#define OPTIONS3 "-r --key_right={K}\tMove the tetrimino RIGHT using the K key"
#define OPTIONS4 " (def: right arrow)\n -t --key-turn={K}\t TURN the tetrimino"
#define OPTIONS5 " clockwise 90d using the K key (def: top arrow)\n -d --key-"
#define OPTIONS6 "drop={K}\t DROP the tetrimino using the K key (def: down "
#define OPTIONS7 "arrow)\n -q--key-quit={K}\tQUIT the game using the K key "
#define OPTIONS8 "(def: 'q' key)\n -p --key-pause={K}\tPAUSE/RESTART the "
#define OPTIONS9 "game using the K key (def: space bar)\n --map-size="
#define OPTIONSA "{row,col}\tSet the numbers of rows and columns of the map "
#define OPTIONSB "(def: 20,10)\n -w --without-next\tHide next tetrimino "
#define OPTIONSC "(def: false)\n -D --debug\tDebug mode (def: false)\n"

void display_help(void)
{
    my_putstr(USAGE);
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
}
