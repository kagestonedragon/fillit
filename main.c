/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:49:39 by emedea            #+#    #+#             */
/*   Updated: 2019/05/27 16:48:12 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int			main(void)
{
	// читаем файл
	int		fd;
	int		amount;
	char	*str;
	char	buff[10000];

	fd = open("test", O_RDONLY);
	amount = read(fd, buff, 9999);
	buff[amount] = '\0';
	str = (char *)malloc(sizeof(char) * (amount + 1));
	str = ft_strdup(buff);

	// создаем объекты
	t_tetriminos	*objects;
	int				amount1;

	amount1 = amount_tetriminos(str);
	objects = fill_objects(str, amount1);
	//генерируем карту
	t_map			map;

	map = generate_map(objects, amount1, minimal_map_size(amount1), 0, 0, 0);
	printf("%s", map.solution);
	return (0);
}
