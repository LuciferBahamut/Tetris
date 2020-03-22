/*
** EPITECH PROJECT, 2019
** CPool_Day06_2019
** File description:
** task01 my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i = i + 1) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
