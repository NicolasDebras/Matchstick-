/*
** EPITECH PROJECT, 2019
** mathstick
** File description:
** map 
*/
#include "mathstic.h"

char *my_mem(char *tab, char c, int size)
{
    int i = 0;

    while (size && c && tab && i < size)
    {
        tab[i] = c;
        i = i + 1;
    }
    tab[i] = '\0';
    return (tab);
}
char **create_map(int size)
{
    char **map;
    int	i = 0;

    if ((map = malloc(sizeof(char *) * (size + 3))) == NULL)
        return (NULL);
    while (i < (size + 2))
    {
        if ((map[i] = malloc(sizeof(char) * (size * 2) + 3)) == NULL)
	    return (NULL);
        i = i + 1;
    }
    map[i] = (NULL);
    return (map);
}
char **fill_map(int sz)
{
    char **map;
    int	i = 0;

    if ((map = create_map(sz)) == NULL)
        return (NULL);
    else if ((map[0] = my_mem(map[0], '*', (sz * 2) + 1)) == NULL)
        return (NULL);
    else if ((map[sz + 1] = my_mem(map[sz + 1], '*', (sz * 2) + 1)) == NULL)
        return (NULL);
    i = 1;
    while (i < (sz + 1))
    {
        map[i] = my_mem(map[i], ' ', (sz * 2) + 2);
        map[i][0] = '*';
        map[i][(sz * 2)] = '*';
        i = i + 1;
    }
    add_alums(map, sz);
    return (map);
}
char **add_alums(char **map, int size)
{
    int	x = 1;
    int	y = size;
    int	i = 0;
    if (map[x] != NULL)
    {
        while (x < (size + 1))
        {
	        y = (size - i);
	        while (y <= (size + i))
	            {
	                map[x][y] = '|';
	                y = y + 1;
	            }
	        i = i + 1;
	        x = x + 1;
	}
    map[i + 1] = '\0';
    }
    affichage(map, size);
    return (map);
}