/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:39:21 by emedea            #+#    #+#             */
/*   Updated: 2019/05/26 17:48:18 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_tetriminos{
	int				number;
	int				x[4];
	int				y[4];
	int				position[4];
}					t_tetriminos;

typedef struct		s_map{
	int				size;
	char			*solution;
}					t_map;
 
int					amount_tetriminos(char *input);
int					validation(char *input);
t_tetriminos		*fill_objects(char *input, int amount);
t_map				generate_map(t_tetriminos *objects, int amount);

#endif
