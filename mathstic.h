/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** .h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#ifndef MATHSTIC_H_
#define MATHSTIC_H_

int my_getnbr(char *str);
int main(int ac, char **av);
char **fill_map(int sz);
char **create_map(int size);
char *my_mem(char *tab, char c, int size);
int my_getnbr(char *str);
int my_putstr(char *str);
void my_putchar(char c);
void affichage(char **str, int size);
char **add_alums(char **map, int size);
int	my_put_nbr(int nb);
void affichage_imput();
int start_all(int ac, char **av);
void display_imput(int *str);
int write_ter(char **map, int size, int match_max);
int my_strlen(char* str);
void check_line(char **map, int *stockage);
int	count_matches(char *line);
int	win_check(char **map);
int ia_turn(char **map, int size, int max_match);
char **rmv_matches(char **map, int *stockage, int size);
void display_ia(int *nbr);
char *my_strdup(char *str);

typedef struct start
{
    int i;
    int n;
    int rt; 
} start_t;



#endif /* !MATHSTIC_H_ */