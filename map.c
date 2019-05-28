/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:56:56 by emedea            #+#    #+#             */
/*   Updated: 2019/05/28 20:01:59 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>

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

void				print(t_tetriminos *objects, t_map *map)
{
	int				i;
	while (i < map->amount)
	{
		printf("%d - %d, ", i, objects[i].number);
	}
	printf("\n");
}

t_map				*generate_map(t_tetriminos *objects, t_map *map, int map_size, int test)
{
	int				i;
	int				j;
	int				x;
	int				y;
	int				success;

	create_new_map(map, map_size);
	i = -1;
	x = 0;
	y = 0;
	success = 0;
	while (++i < map->amount)
	{
		j = 0;
		while ((j < map-> width) && !(is_here_place(&objects[i], map, &x, &y, &success)))
			unoccupied_dot(map, &j, &x, &y);
	}
	printf("TEST - %d\n", test);
	if (success == map->amount || map_size > 15)
		return (map);
	else if (!(last_combination(objects, map->amount)))
		return(generate_map(next_combination(objects, map->amount), map, map_size, test + 1));
	print(objects, map);
	return (generate_map(next_combination(objects, map->amount), map, (map_size + 1), test + 1));
}
