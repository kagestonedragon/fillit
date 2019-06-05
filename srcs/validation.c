/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmelda <fmelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:22:03 by fmelda            #+#    #+#             */
/*   Updated: 2019/05/29 18:12:01 by fmelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "../libft/libft.h"

int amount_tetriminos(char *str)
{
	int len;
	int i;
	int tetri;

	i = 0;
	tetri = 0;
	len = ft_strlen(str);
	if (str)
	{
		if (len == 20)
			return (1);
		else if (str[i + 20] != '\n')
			return (0);
		while (str[i + 20] == '\n' && ((i + 20) < len))
		{
			if ((str[i + 41] != '\n') && ((i + 41) < len))
				return (0);
			tetri++;
			i += 21;
		}
		if (str[len - 1] == '\n' && (str[len - 2] == '.' || str[len - 2] == '#'))
			tetri++;
		else
			return (0);
		return (tetri);
	}
	return (0);
}

int check_amount(char *str)
{
	int dot;
	int symb;
	int counter;
	int newline;

	dot = 0;
	symb = 0;
	counter = 0;
	newline = 0;
	if (str)
	{
		while (counter < 20)
		{
			if (str[counter] == '.' && dot < 12)
				dot++;
			if (str[counter] == '#' && symb < 4)
				symb++;
			if (str[counter] == '\n' && ((counter + 1) % 5 == 0) && newline < 4)
				newline++;
			counter++;
		}	
	}
	if (counter == 20 && dot == 12 && symb == 4 && newline == 4)
		return (1);
	else
		return (0);
}

int check_connection(char *str)
{
	int connect;
	int i;
	int symb;

	connect = 0;
	i = 0;
	symb = 0;
	if (str)
	{
		while (connect < 8 && symb < 4)
		{
			if (str[i] == '#')
				symb++;
			if (str[i] == '#' && str[i + 1] == '#')
				connect++;
			if (str[i] == '#' && str[i - 1] == '#')
				connect++;
			if (str[i] == '#' && str[i + 5] == '#' && i < 16)
				connect++;
			if (str[i] == '#' && str[i - 5] == '#' && i > 3)
				connect++;
			i++;
		}
	}
	if (connect == 8 || connect == 6)
		return (1);
	else
		return (-1);
}

int validation(char *input, int amount)
{
	int	tetri;

	if (input)
	{
		if (amount > 26 || amount == 0)
			return (0);
		tetri = 0;
		while (tetri < amount)
		{
			if (check_amount(input) != 1)
				return (0);
			if (check_connection(input) == 1)
				input += 21;
			else
				return (0);
			tetri++;
		}
	}
	return (1);
}
