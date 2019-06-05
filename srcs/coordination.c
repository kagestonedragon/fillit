/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordination.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:09:32 by emedea            #+#    #+#             */
/*   Updated: 2019/05/29 16:48:10 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void     coordinates(t_tetriminos *object, t_map *map)
{
	int		i;
    int     x;
    int     y;

    x = object->current_position % (map->size + 1);
    y = (object->current_position + 1) / (map->size + 1);
	i = -1;
	while (++i < 4)
		object->coordination[i] = (map->size * (object->y[i] + y)) + (object->x[i] + x) + (object->y[i] + y);
}

static int         write(t_tetriminos *object, t_map *map)
{
	int		i;

    i = -1;
	while (++i < 4)
		map->solution[object->coordination[i]] = 65 + object->number;
	return (1);
}

int			free_place(t_tetriminos *object, t_map *map)
{
	int		i;

	i = -1;
    coordinates(object, map);
	while (++i < 4)
		if ((object->coordination[i] > map->width) || (map->solution[object->coordination[i]] != '.'))
            return (0);
	return (write(object, map));
}
