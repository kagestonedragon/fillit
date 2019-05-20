/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:15:54 by emedea            #+#    #+#             */
/*   Updated: 2019/05/17 10:18:45 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_atoi(const char *str)
{
	int			negative;
	long long	result;
	long long	temp;

	negative = 1;
	result = 0;
	while (*str != '\0' && (*str == ' ' || *str == '\t' ||
	*str == '\r' || *str == '\n' || *str == '\f' || *str == '\v'))
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str != '\0' && (*str >= '0' && *str <= '9'))
	{
		temp = (result * 10) + (*str++ - '0');
		if (result > temp)
		{
			if (negative == 1)
				return (-1);
			return (0);
		}
		result = temp;
	}
	return ((int)(result * negative));
}
