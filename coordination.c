/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:09:32 by emedea            #+#    #+#             */
/*   Updated: 2019/05/28 19:28:34 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				unoccupied_dot(t_map *map, int *i, int *x, int *y)
{
	while (*i < map->width)
	{
		*i += 1;
		if (map->solution[*i] == '.')
		{
			if (map->solution[*i] == '\n')
			{
				*x = 0;
				*y += 1;
			}
			else
				*x += 1;
			return (*i);
		}
	}
	return (map->width);
}

static void	new_coordinates(t_tetriminos *object, t_map *map, int *x, int *y)
{
	int		i;

	i = -1;
	while (++i < 4)
		object->coordination[i] = (map->size * (object->y[i] + *y)) + (object->x[i] + *x) + (object->y[i] + *y);
}

static int	write_tetriminos_to_map(t_tetriminos *object, t_map *map)
{
	int		i;

	i = -1;
	while (++i < 4)
		map->solution[object->coordination[i]] = 65 + object->number;
	return (1);
}

int			is_here_place(t_tetriminos *object, t_map *map, int *x, int *y, int *success)
{
	int		i;
	new_coordinates(object, map, x, y);
	i = -1;
	while (++i < 4)
		if ((object->coordination[i] > map->width) || (map->solution[object->coordination[i]] != '.'))
			return (0);
	*success += 1;
	return (write_tetriminos_to_map(object, map));
}
