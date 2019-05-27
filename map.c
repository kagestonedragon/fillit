/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:56:56 by emedea            #+#    #+#             */
/*   Updated: 2019/05/27 17:09:48 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


static t_map	init_new_map(int map_size)
{
	t_map		result;
	int			solution_size;
	int			i;

	result.size = map_size;
	solution_size = (result.size * result.size) + result.size + 1;
	result.solution = (char *)malloc(sizeof(char) * solution_size);
	ft_memset(result.solution, '.', solution_size);
	i = result.size;
	while (i < solution_size)
	{
		result.solution[i] = '\n';
		i += result.size  + 1;
	}
	result.solution[solution_size - 1] = '\0';
	return (result);
}

static int          solution(t_tetriminos *object, t_tetriminos *new_object, t_map *map, int *x, int *y)
{
	int				i;
	int				solution_size;

	i = 0;
	solution_size = ft_strlen(map->solution);
    while(i < solution_size)
    {
        new_coordinates(new_object, object, *x, *y);
        current_map_position(map, &i, x, y);
        if (is_here_place(new_object, map))
        {
            write_tetriminos_to_map(new_object, map, object->number);
            return (1);
        }
        i++;
    }
    return (0);
}

t_map				generate_map(t_tetriminos *objects, int amount, int map_size, int x, int y, int test)
{
	t_map			map;
	t_tetriminos	*new_objects;
	int				i;
	int				success;

	new_objects = (t_tetriminos *)malloc(sizeof(t_tetriminos) * amount);
	map = init_new_map(map_size);
	i = -1;
    success = 0;
    while (++i < amount)
        if (solution(&objects[i], &new_objects[i], &map, &x, &y))
            success++;
	printf("TEST - %d, SUCCESS - %d, MAP - %d\n", test, success, map_size);
    if (success == amount)
	{
		printf("WIN MAP_SIZE: %d AND TEST: %d\n\n", map_size, test);
        return (map); 
	}
    else if (last_combination(objects, amount) == 0)
        return (generate_map(next_combination(objects, amount), amount, map_size, 0, 0, test + 1));
     return (generate_map(next_combination(objects, amount), amount, (map_size + 1), 0, 0, test + 1));
}
