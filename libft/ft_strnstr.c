/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:52:07 by emedea            #+#    #+#             */
/*   Updated: 2019/05/17 10:37:57 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	size_t	temp_len;

	i = 0;
	j = 0;
	temp_len = len;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		while ((haystack[i + j] == needle[j]) && needle[j] && temp_len--)
			j++;
		if (!needle[j])
			return ((char *)&haystack[i]);
		i++;
		if ((int)(len - i) < 0)
			return (NULL);
		temp_len = len - i;
		j = 0;
	}
	return (NULL);
}
