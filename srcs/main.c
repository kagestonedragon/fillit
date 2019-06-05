/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:49:39 by emedea            #+#    #+#             */
/*   Updated: 2019/06/05 15:41:57 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static char			*read_file(int argc, char *argv)
{
	int				amount;
	char			buffer[547];
	char			*output;

	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	amount = read(open(argv, O_RDONLY), buffer, 546);
	if (amount < 0)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	buffer[amount] = '\0';
	output = ft_strdup(buffer);
	return (output);
}

int					main(int argc, char **argv)
{
	char			*input;
	int				amount;
	t_tetriminos	*objects;
	t_map			map;

	input = read_file(argc, argv[1]);
	if (!input)
		return (0);
	amount = amount_tetriminos(input);
	if (validation(input, amount))
	{
		objects = fill_objects(input, amount);
		if (!objects)
			return (0);
		map.amount = amount;
		map.size = minimal_map_size(amount);
		get_solution(objects, &map);
		write(1, map.solution, (map.width - 1));
		free(objects);
	}
	else
		write(1, "error\n", 6);
	free(input);
	return (0);
}
