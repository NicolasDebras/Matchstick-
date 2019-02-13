/*
** EPITECH PROJECT, 2019
** matchstick 
** File description:
** imput 
*/
#include "mathstic.h"

int check_match(char **map, int *stockage)
{
    int i = 1;
    int n = 0;

    while (map[stockage[0]][i] != '\0') {
        if (map[stockage[0]][i] == '|')
            n = n + 1;
        i = i + 1;
    }
    return (n);
}