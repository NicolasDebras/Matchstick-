#include "mathstic.h"

int coding_style(int macth, int max_match) 
{
    if (macth <= max_match && macth != 1)
        macth = macth - 1;
    if (macth > max_match)
        macth = max_match;
    return (macth);   
}

int ia_turn(char **map, int size, int max_match)
{
    int i = 1;
    int macth = 1;
    int *stockage;
    my_putstr("\n\nAI's turn...\n");
    while(((macth = count_matches(map[i]))) == 0)
        i = i + 1; 
    macth = coding_style(macth, max_match);
    stockage = malloc(sizeof(int)); 
    stockage[0]= i; 
    stockage[1] = macth;
    display_ia(stockage);
    map = rmv_matches(map, stockage, size); 
    if (win_check(map) == 0 ) {
        my_putstr("\nI lost... snif... but I'll get you next time!!\n");
        return(1);
    } else {
        my_putstr("\n\nYour turn:\n");
        write_ter(map, size, max_match);
    }
}