/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:35:54 by emedea            #+#    #+#             */
/*   Updated: 2019/05/22 20:37:00 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

t_tetriminos		coordinates(char *input)
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

t_tetriminos		*fill_objects(char *input, int amount)
{
	t_tetriminos	*objects;
	int				counter;
	int				i;

	counter = 0;
	i = 0;
	objects = (t_tetriminos *)malloc(sizeof(t_tetriminos) * amount);
	while (counter < amount)
	{
		objects[counter] = coordinates(&input[i]);
		objects[counter].number = counter;
		counter++;
		i += 21;
	}
	return (objects);
}
