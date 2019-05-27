#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

int         minimal_map_size(int amount)
{
    int     result;

    result = amount * 4;
    if (result == 4)
        return (2);
    while (!ft_sqrt(result))
        result++;
    return (ft_sqrt(result));
}

void        new_coordinates(t_tetriminos *new, t_tetriminos *old, int x, int y)
{
    int     i;

    i = -1;
    while (++i < 4)
    {
        new->x[i] = old->x[i] + x;
        new->y[i] = old->y[i] + y;
    }
}

int         is_here_place(t_tetriminos *new, t_map *map)
{
    int     i;
    int     new_coordination;

    i = -1;
    while (++i < 4)
    {
        new_coordination = ((map->size) * new->y[i]) + new->x[i] + new->y[i];
        if (!(map->solution[new_coordination] == '.'))
            return (0);
    }
    return (1);
}

void        current_map_position(t_map *map, int *k, int *x, int *y)
{
    if (map->solution[*k] == '\n')
    {
        *k += 1;
        *y += 1;
        *x = 0;
    }
    else
        *x += 1;
}

void        write_tetriminos_to_map(t_tetriminos *new, t_map *map, int number)
{
    int     i;
    int     new_coordination;

    i = -1;
    while (++i < 4)
    {
        new_coordination = ((map->size) * new->y[i]) + new->x[i] + new->y[i];
        map->solution[new_coordination] = 65 + number;
    }
}
