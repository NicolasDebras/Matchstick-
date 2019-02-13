/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** print
*/

#include "mathstic.h"

void affichage_imput()
{
    my_putchar('\n');
    my_putchar('\n');
    my_putstr("Your turn: ");
    my_putchar('\n');
    my_putstr("Line: ");
}
void display_imput(int *nbr)
{
    my_putstr("Player removed ");
    my_put_nbr(nbr[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(nbr[0]);
    my_putchar('\n');
}
void display_ia(int *nbr)
{
    my_putstr("AI removed ");
    my_put_nbr(nbr[1]);
    my_putstr(" match(es) from line ");
    my_put_nbr(nbr[0]);
    my_putchar('\n');
}
void affichage(char **str, int size)
{
    int i = 0; 

    while (str[i] != NULL) {
        my_putstr(str[i]);
        my_putchar('\n');
        i = i + 1;
    }
    my_putstr(str[0]);
}