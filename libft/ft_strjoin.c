/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 08:29:28 by emedea            #+#    #+#             */
/*   Updated: 2019/05/18 12:24:28 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_result;
	char	*join_result_begin;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	if (!(size = ft_strlen(s1) + ft_strlen(s2) + 1))
		return (NULL);
	join_result = (char *)malloc(sizeof(char) * size);
	if (!join_result)
		return (NULL);
	join_result_begin = join_result;
	while (*s1)
		*join_result++ = *s1++;
	while (*s2 != '\0')
		*join_result++ = *s2++;
	*join_result = '\0';
	return (join_result_begin);
}
