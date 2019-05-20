/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <emedea@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:54:12 by emedea            #+#    #+#             */
/*   Updated: 2019/05/18 12:23:19 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*result;

	if (!size)
		return (NULL);
	result = malloc(size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, size);
	return (result);
}
