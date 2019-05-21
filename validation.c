/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:07:34 by emedea            #+#    #+#             */
/*   Updated: 2019/05/21 17:14:45 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int			amount_tetriminos(char *input)
{
	int		i;
	int 	length;
	int		tetriminos;

	i = 0;
	length = ft_strlen(input);
	tetriminos = 0;
	if (!input)
		return (0);
	while (input[i + 20] == '\n' && (i + 20) < length)
	{
		tetriminos++;
		i += 21;
	}
	if (input[i + 20] != '\n' && (i + 20) < length)
		return (0);
	if (input[length - 1] == '\n' && (input[length - 2] == '.' || input[length - 2] == '#'))
	{
		tetriminos++;
		return (tetriminos);
	}
	return (0);
}

static int validate_symbols(char *input)
{
	int		dot;
	int 	sharp;
	int 	new_line;
	int 	counter;

	dot = 0;
	sharp = 0;
	new_line = 0;
	counter = 0;
	while (counter < 20)
	{
		if (input[counter] == '.' && dot < 12)
			dot++;
		if (input[counter] == '#' && sharp < 4)
			sharp++;
		if (input[counter] == '\n' && new_line < 4)
			new_line++;
		counter++;
	}
	if (counter == 20 && dot == 12 && sharp == 4 && new_line == 4)
		return (1);
	return (0);
}

static int		validate_connections(char *input)
{
	int		i;
	int		connections;
	int		sharp_counter;

	i = -1;
	connections = 0;
	sharp_counter = 0;
	while (connections < 8 && sharp_counter < 4)
	{
		if ((i % 5) == 0 && input[i] != '\n')
			return (0);
		if (input[++i] == '#')
			sharp_counter++;
		if (input[i] == '#' && input[i - 1] == '#')
			connections++;
		if (input[i] == '#' && input[i + 1] == '#')
			connections++;
		if (input[i] == '#' && input[i + 5] == '#')
			connections++;
		if (input[i] == '#' && input[i - 5] == '#')
			connections++;
	}
	if (connections == 8 || connections == 6)
		return (1);
	return (0);
}

int		validation(char *input)
{
	int	tetriminos;
	int	amount;

	if (!input)
		return (0);
	amount = amount_tetriminos(input);
	if (amount > 26 || amount <= 0)
		return (0);
	tetriminos = 0;
	while (tetriminos < amount)
	{
		if (!(validate_symbols(input)))
			return (0);
		if (validate_connections(input))
			input += 21;
		else
			return (0);
		tetriminos++;
	}
	return (1);
}
