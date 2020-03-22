/*
** EPITECH PROJECT, 2020
** tetris
** File description:
** fill key struct
*/

#include "tetris.h"

void fill_keys(keys_t *key)
{
}

int compare_str(char *str, char *str2)
{
    int i = 0;

    while (str2[i] != '\0') {
        if (str2[i] == str[i])
            i++;
        else
            return (FALSE);
    }
    return (TRUE);
}

void get_term(keys_t *key, char **env)
{
    char *temp;
    int i = 0;
    int j = 0;

    while (env[i]) {
        if (compare_str(env[i], "TERM")) {
            temp = env[i];
            break;
        }
        i++;
    }
    key->term = malloc(sizeof(char) * my_strlen(temp));
    for(i = 0; temp[i] != '='; i++);
    i++;
    for(j = 0; temp[i] != '\0'; i++, j++)
        key->term[j] = temp[i];
    key->term[j] = '\0';
    fill_keys(key);
}
