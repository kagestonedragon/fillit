/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:56:56 by emedea            #+#    #+#             */
/*   Updated: 2019/05/29 16:44:11 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int					minimal_map_size(int amount)
{
	int				result;
	
	result = amount * 4;
	if (result == 4)
		
		return (2);
	while (!ft_sqrt(result))
		result++;
	return (ft_sqrt(result));
}

static t_map		*create_new_map(t_map *map, int map_size)
{
	int				i;

	map->size = map_size;
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

t_map				*generate_map(t_tetriminos *objects, t_map *map, int map_size)
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				success;

	success = 0;
	while (success != map->amount)
	{
		create_new_map(map, map_size);
		i = -1;
		x = 0;
		y = 0;
		success = 0;
		while (++i < map->amount)
		{
			j = 0;
			while ((j < map->width) && !(is_here_place(&objects[i], map, &x, &y, &success)))
				unoccupied_dot(map, &j, &x, &y);
		}
		if (!(last_combination(objects, map->amount)))
			next_combination(objects, map->amount);
		else
			map_size++;
	}
	return (map);
}
