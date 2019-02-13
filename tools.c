/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_put_nbr
*/
#include "mathstic.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int n = 0;

    while (str[n] != 0)
    {
        my_putchar(str[n]);
        n = n + 1;
    }
    return (0);
}
int my_getnbr(char *str)
{
    int i = 0;
    int neg = 1;
    int n = 0;

    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-')) {
        if (str[i] == '-') {
            neg = neg * -1;
        }
        i = i + 1;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        n = (n * 10) + str[i] - 48;
        i = i + 1;
    }
    return (n * neg);
}

int	my_put_nbr(int nb)
{
    int	mod;

    if (nb < 0)
    {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0)
        {
            if (nb >= 10)
        {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar(48 + mod);
        }
      else
        my_putchar(48 + nb % 10);
    }
}

int my_strlen(char* str)
{
    int len;

    len = 0;
    while(str[len] != '\0')
    {
        len = len + 1;
    }
    return (len);
}