/*
** EPITECH PROJECT, 2019
** matchstick
** File description:
** fct principal
*/
#include "mathstic.h"

char **map_cpy(char **map)
{
    int	i = -1;
    int	j = -1 ;
    char **new_map;

    if (map == NULL)
        return (NULL);
    while (map[++i]);
        new_map = malloc((sizeof(char *) * (i + 1)));
    while (++j < i)
        new_map[j] = my_strdup(map[j]);
    new_map[j] = NULL;
    return (new_map);
}

char **rmv_matches(char **map, int *stockage, int size)
{
    int	pos;
    int	rmn;
    char **new_map;
    if ((new_map = map_cpy(map)) == NULL)
        return (NULL);
    pos = (size * 2);
    rmn = stockage[1];
    while (rmn > 0) {
        if (new_map[stockage[0]][pos] != '|')
	        pos = pos - 1;
        else {
	        new_map[stockage[0]][pos] = ' ';
	        rmn = rmn - 1;
	    }
    }
    affichage(new_map, size);
    return (new_map);  
}

int line(char **map, int size)
{
    char *buffer;
    size_t bufsize = 32;    
    size_t characters;
    int stockage;

    buffer = (char *)malloc(bufsize * sizeof(char));
    my_putstr("Line: ");
    characters = getline(&buffer,&bufsize,stdin);
    stockage = my_getnbr(buffer);
    if (stockage == 0 || stockage > size ) {
        my_putstr("Error: this line is out of range\n");
        stockage = line(map, size);
    }
    return(stockage);
}

int match(char **map, int line, int size, int match_max)
{
    char *buffer;
    size_t bufsize = 32;    
    size_t characters;
    int stockage;

    buffer = (char *)malloc(bufsize * sizeof(char));
    my_putstr("Match: ");   
    getline(&buffer,&bufsize,stdin);
    stockage = my_getnbr(buffer);
    if (stockage == 0 )
        return (0); 
    else if ((stockage > count_matches(map[line]))) {
        my_putstr("Error: this line is out of range\n");
        stockage = write_ter(map, size, match_max);
        return (0);
    }
    return (stockage);
}

int write_ter(char **map, int  size, int match_max) 
{
    int *stockage;
    int i = 0;  
    stockage = malloc(sizeof(int)* 2);
    stockage[0] = line(map, size);
    if ((stockage[1] = match(map, stockage[0], size, match_max)) == 0) 
        return (0);  
    display_imput(stockage);
    map = rmv_matches(map, stockage, size);
    if (win_check(map) == 0 ) {
        my_putstr("\nYou lost, too bad...\n");
        return(2);
    } else { 
        if ((ia_turn(map, size, match_max)) == 1)
            return (1);
    }  
}

int start_all(int ac, char **av)
{
    start_t *variable = malloc(sizeof(int));
    char **map;

    variable->i = my_getnbr(av[1]);
    variable->n = my_getnbr(av[2]);
    if ( variable->i == 0 || variable->n == 0 ){
        my_putstr("Invalid argv, please retry\n");
        return (84);
    }
    map = fill_map(variable->i);
    my_putstr("\n\nYour turn:\n");
    variable->rt = write_ter(map, variable->i, variable->n);
    return (variable->rt);
}

int main(int ac, char **av)
{
    int ret;

    if (ac >= 4 || ac < 3) {
        return (84);
    }
    else {  
        ret = start_all(ac, av);
        return (ret);
    }
} 