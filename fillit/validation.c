/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:07:34 by emedea            #+#    #+#             */
/*   Updated: 2019/05/28 22:26:58 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			amount_tetriminos(char *input)
{
	int		i;

	if (!input)
		return (0);
	i = 20;
	while (input[i] == '\n')
		i += 21;
	return ((i + 1) / 21);
}

static int validate_symbols(char *input)
{
	int		i;
	int		dot;
	int 	sharp;
	int 	new_line;

	i = -1;
	dot = 0;
	sharp = 0;
	new_line = 0;
	while (++i < 20)
	{
		if (input[i] == '.')
			dot++;
		if (input[i] == '#')
			sharp++;
		if (input[i] == '\n' && !((i + 1) % 5))
			new_line++;
	}
	if (i == 20 && dot == 12 && sharp == 4 && new_line == 4 )
		return (1);
	return (0);
}

static int		validate_connections(char *input)
{
	int		i;
	int		sharp;
	int		connections;

	i = -1;
	sharp = 0;
	connections = 0;
	while (sharp < 4)
	{
		if (input[++i] == '#')
		{
			if (input[i - 1] == '#')
				connections++;
			if (input[i + 1] == '#')
				connections++;
			if (input[i + 5] == '#')
				connections++;
			if (input[i - 5] == '#')
				connections++;
			sharp++;
		}
	}
	if (connections == 8 || connections == 6)
		return (1);
	return (0);
}

int		validation(char *input, int amount)
{
	int	i;

	if (amount > 26 || amount == 0)
		return (0);
	i = -1;
	while (++i < amount)
	{
		if (!(validate_symbols(input)))
			return (0);
		if (validate_connections(input))
			input += 21;
		else
		    return (0);
	}
	return (1);
}
