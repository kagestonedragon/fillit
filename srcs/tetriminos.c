/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:35:54 by emedea            #+#    #+#             */
/*   Updated: 2019/06/05 12:50:19 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

static t_tetriminos	coordinates(char *input)
{
	t_tetriminos	object;
	int				temporary_x;
	int				temporary_y;
	int				counter;
	int				sharp;

	counter = -1;
	sharp = 0;
	object.y[sharp] = 0;
	object.x[sharp] = 0;
	while (++counter < 20 && sharp < 4)
	{
		if (!sharp && input[counter] == '#')
		{
			temporary_x = counter % 5;
			temporary_y = counter / 5;
			sharp++;
		}
		else if (sharp && input[counter] == '#')
		{
			object.x[sharp] = (temporary_x - (counter % 5)) * (-1);
			object.y[sharp++] = (counter / 5) - temporary_y;
		}
	}
	return (object);
}

t_tetriminos        *fill_objects(char *input, int amount)
{
    t_tetriminos    *objects;
	int				counter;
	int				i;

    objects = (t_tetriminos *)malloc(sizeof(t_tetriminos) * amount);
    if (!objects)
        return (NULL);
	counter = -1;
	i = 0;
	while (++counter < amount)
	{
		objects[counter] = coordinates(&input[i]);
		objects[counter].number = counter;
		objects[counter].position = 0;
		i += 21;
	}
    return (objects);
}

void                next_step(t_tetriminos *objects, t_map *map, int start)
{
    int             i;
 
    if (objects[0].position != map->width)
    {
        i = map->amount;
        while ((start - 1) < --i)
            objects[i].position = 0;
        objects[start - 1].position++;
    }
    else
    {
        i = -1;
        while (++i < map->amount)
            objects[i].position = 0;
        map->size++;
    }
}

int                 next_position(t_tetriminos *object, t_map *map)
{
    while (++object->position < map->width)
        if (map->solution[object->position] == '.')
            break ;
    return (object->position);
}
