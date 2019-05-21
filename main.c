/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:49:39 by emedea            #+#    #+#             */
/*   Updated: 2019/05/21 13:18:38 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include <fcntnl.h>
#include <unistd.h>

int			main(void)
{
	int		amount;
	char	*str;
	int		fd;
	char	tmp[1000];
	
	fd = open("test", O_RDONLY);
	amount = read(fd, tmp, 9999);
	tmp[amount] = '\0';
	str = (char *)malloc(sizeof(char) * (amount + 1));
	str = ft_strdup(tmp);
	if (validation(str))
	{
coordinates:w

	}	
}
