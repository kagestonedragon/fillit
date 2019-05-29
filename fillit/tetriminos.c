/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:35:54 by emedea            #+#    #+#             */
/*   Updated: 2019/05/29 16:27:15 by emedea           ###   ########.fr       */
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
		objects[counter] = coordinates(input + i);
		objects[counter].number = counter;
		counter++;
		i += 21;
	}
	return (objects);
}

static void         swap(t_tetriminos *a, int i, int j)
{
    t_tetriminos    s;

    s = a[i];
    a[i] = a[j];
    a[j] = s;
}

int                 last_combination(t_tetriminos *input, int amount)
{
    int             i;
    int             j;
    t_tetriminos    temporary;

    i = amount - 2;
    while (i != -1 && input[i].number >= input[i + 1].number)
        i--;
    if (i == -1)
    {
        while (++i < amount)
        {
            j = i;
            while (++j < amount)
            {
                if (input[j].number < input[i].number)
                {
                    temporary = input[j];
                    input[j] = input[i];
                    input[i] = temporary;
                }
            }
        }
        return (1);
    }
	return (0);
}
        
t_tetriminos        *next_combination(t_tetriminos *input, int amount)
{
    int             i;
    int             j;

    i = amount - 2;
    while (i != -1 && input[i].number >= input[i + 1].number)
        i--;
    j = amount - 1;
    while (input[i].number >= input[j].number)
        j--;
    swap(input, i, j);
    j = i + 1;
    i = amount - 1;
    while (j < i)
        swap(input, j++, i--);
    return (input);
}
