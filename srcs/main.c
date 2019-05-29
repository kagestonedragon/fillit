/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:49:39 by emedea            #+#    #+#             */
/*   Updated: 2019/05/29 18:05:08 by fmelda           ###   ########.fr       */
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
	input = (char *)malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	input = ft_strdup(buffer);
	amount = amount_tetriminos(input);
	if (validation(input, amount))
	{
		objects = fill_objects(input, amount);
		map.amount = amount;
		generate_map(objects, &map, minimal_map_size(amount));
		write(1, map.solution, (map.width - 1));
	}
	else
		write(1, "error\n", 6);
	return (argc);
}
