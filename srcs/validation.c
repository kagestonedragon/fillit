/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:46:51 by fmelda            #+#    #+#             */
/*   Updated: 2019/06/05 13:48:55 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int			amount_tetriminos(char *input)
{
	int		i;
	int		length;
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
	if (input[length - 1] == '\n' &&
	(input[length - 2] == '.' || input[length - 2] == '#'))
	{
		tetriminos++;
		return (tetriminos);
	}
	return (0);
}

static int	validate_symbols(char *input)
{
	int		dot;
	int		sharp;
	int		new_line;
	int		counter;

	dot = 0;
	sharp = 0;
	new_line = 0;
	counter = -1;
	while (++counter < 20)
	{
		if (input[counter] == '.' && dot < 12)
			dot++;
		if (input[counter] == '#' && sharp < 4)
			sharp++;
		if (input[counter] == '\n' && new_line < 4 && !((counter + 1) % 5))
			new_line++;
	}
	if (dot == 12 && sharp == 4 && new_line == 4)
		return (1);
	return (0);
}

static int	validate_connections(char *input)
{
	int		i;
	int		connections;

	i = -1;
	connections = 0;
	while (++i < 20)
	{
		if (input[i] == '#')
		{
			if (input[i - 1] == '#')
				connections++;
			if (input[i + 1] == '#')
				connections++;
			if (input[i + 5] == '#' && i < 16)
				connections++;
			if (input[i - 5] == '#' && i > 3)
				connections++;
		}
	}
	if (connections == 8 || connections == 6)
		return (1);
	return (0);
}

int			validation(char *input, int amount)
{
	int		tetriminos;

	if (amount > 26 || amount <= 0)
		return (0);
	tetriminos = 0;
	while (tetriminos++ < amount)
	{
		if (!(validate_symbols(input)) || !(validate_connections(input)))
			return (0);
		input += 21;
	}
	return (1);
}
