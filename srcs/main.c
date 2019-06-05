/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:49:39 by emedea            #+#    #+#             */
/*   Updated: 2019/06/05 13:31:06 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int					main(int argc, char **argv)
{
	char			buffer[547];
	char			*input;
	int				amount;
	t_tetriminos	*objects;
	t_map			map;

	buffer[read(open(argv[1], O_RDONLY), buffer, 546)] = '\0';
	input = ft_strdup(buffer);
	amount = amount_tetriminos(input);
	if (validation(input, amount) || argc != 2)
	{
		objects = fill_objects(input, amount);
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
