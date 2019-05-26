/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:23:28 by emedea            #+#    #+#             */
/*   Updated: 2019/05/26 20:14:30 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void		swap(int *a, int i, int j)
{
	int		s;

	s = a[i];
	a[i] = a[j];
	a[j] = s;
}

int			NextSet(int *a, int n)
{
	int		j;
	int		k;
	int		l;
	int		r;

	j = n - 2;
	while (j != -1 && a[j] >= a[j + 1])
		j--;
	if (j == -1)
		return (0);
	k = n - 1;
	while (a[j] >= a[k])
		k--;
	swap(a, j, k);
	l = j + 1;
	r = n - 1;
	while (l < r)
		swap(a, l++, r--);
	return (1);
}

void		Print(int *a, int n)
{
	int			i;

	i = 0;
	while (i < n)
	{
		printf("%d ", a[i]);
		i++;
	}
	printf("\n");	
}

int			current_position(t_tetriminos *objects, int *a, int j)
{
	int		result;
	int		i;
	int		k;

	i = 0;
	result = objects[a[i]].position[k];
	while (i < j)
	{
		k = 0;
		while (k < 4)
		{
			if (objects[a[i]].position[k] < result)
				result = objects[a[i]].position[k];
			k++;
		}
		i++;
	}
	return (result);
}

static void	coordination_to_index(t_tetriminos *object, int map_size, int current_position)
{
	int		i;

	i = -1;
	while (++i < 4)
		object.position[i] = current_position + (object.y[i] * (map_size + 1)) + object.x[i];
}

static int	is_here_place(t_tetriminos compare, t_tetriminos *objects, int map_size, int *a, int j)
{
	int		i;
	int		k;

	i = 0;
	while (i < j)
	{
		k = 0;
		while (k < 4)
		{
			if (compare.position[k] == objects[a[i]] || compare.position[k] % (map_size + 1) || compare.position[k] > (map_size * map_size) + map_size + 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int			check(t_tetriminos *objects, int amount, int map_size)
{
	int *a;
	int pos;
	int	i;
	int j;

	i = -1;
	j = 0;
	pos = 0;
	a = (int *)malloc(sizeof(int) * n);
	while (++i < n)
		a[i] = i;
	while (NextSet(a, n) == 1)
	{
		coordination_to_index(objects[j], 4, current_position(objects, a, j));
		if (is_here_place
	}
	return (0);
}
