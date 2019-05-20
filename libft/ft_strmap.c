/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:18:51 by emedea            #+#    #+#             */
/*   Updated: 2019/05/17 10:46:30 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;

	if (!s || !f)
		return (NULL);
	i = -1;
	new = ft_strnew(ft_strlen(s));
	if (!new)
		return (NULL);
	while (s[++i])
		new[i] = f(s[i]);
	return (new);
}
