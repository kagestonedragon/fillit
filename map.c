/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:56:56 by emedea            #+#    #+#             */
/*   Updated: 2019/05/26 19:22:25 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static int		minimal_map_size(int amount)
{
	int			result;

	result = amount * 4;
	if (result == 4)
		return (2);
	while (!ft_sqrt(result))
		result++;
	printf("%d\n", ft_sqrt(result));
	return(ft_sqrt(result));
}

static t_map	init_new_map(int amount)
{
	t_map		result;
	int			solution_size;
	int			i;

	result.size = 4;
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


static void			new_coordinates(t_tetriminos *new, t_tetriminos *old, int x, int y)
{
	int				i;

	i = -1;
	while (++i < 4)
	{
		new->x[i] = old->x[i] + x;
		new->y[i] = old->y[i] + y;
	}
}

/*static int			is_here_place(t_tetriminos *new, t_map *map)
{
	int				i;
	int				new_coordinates;

	i = -1;
	while (++i < 4)
	{
		new_coordinates = ((map->size) * new->y[i]) + new->x[i] + new->y[i];
		if (!(map->solution[new_coordinates] == '.'))
			return (0);
	}
	return (1);
}*/

static	void		current_map_position(t_map *map, int *k, int *x, int *y)
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

static void			write_tetriminos_to_map(t_tetriminos *new, t_map *map, int number)
{
	int				i;
	int				new_coordinates;

	i = -1;
	while (++i < 4)
	{
		new_coordinates = ((map->size) * new->y[i]) + new->x[i] + new->y[i];
		map->solution[new_coordinates] = 65 + number;
	}
}

t_map				generate_map(t_tetriminos *objects, int amount)
{
	t_map			our_map;
	t_tetriminos	*temp;
	int				i;
	int				temp_k;
	int				k;
	int				x;
	int				y:
	int				smogli_li_postavit;
	int				perestanovki;
	int				len;

	perestanovki = 0;
	temp = (t_tetriminos *)malloc(sizeof(t_tetriminos) * amount);
	our_map = init_map(amount);
	i = 0;
	x = 0;
	y = 0;
	k = 0;
}
