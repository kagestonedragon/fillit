/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 15:20:34 by emedea            #+#    #+#             */
/*   Updated: 2019/05/03 15:21:29 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int nb)
{
	if (nb > 1)
		return (ft_fibonacci(nb - 1) + ft_fibonacci(nb - 2));
	else if (nb == 1)
		return (1);
	else if (nb == 0)
		return (0);
	else
		return (-1);
}
