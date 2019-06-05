/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:56:56 by emedea            #+#    #+#             */
/*   Updated: 2019/06/05 12:47:13 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int             minimal_map_size(int amount)
{
	int			result;
	
	result = amount * 4;
	while (!ft_sqrt(result))
		result++;
	return (ft_sqrt(result));
}

static t_map    *create_new_map(t_map *map)
{
	int			i;

	map->width = (map->size * map->size) + map->size + 1;
	ft_memset(map->solution, '.', map->width);
	i = map->size;
	while (i < map->width)
	{
		map->solution[i] = '\n';
		i += (map->size + 1);
	}
	map->solution[map->width - 1] = '\0';
	return (map);
}

t_map           *get_solution(t_tetriminos *objects, t_map *map)
{
    int         i;

    i = -1;
    create_new_map(map);
    while (++i < map->amount) 
    {
        while (objects[i].position < map->width) 
        {
            if (free_place(&objects[i], map))
                break ;
             next_position(&objects[i], map);
        }
        if (objects[i].position == map->width)
        {
            next_step(objects, map, i);
            i = -1;
            create_new_map(map);
        }
    }
    return (map);
}
