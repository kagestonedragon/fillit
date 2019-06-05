/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:39:21 by emedea            #+#    #+#             */
/*   Updated: 2019/05/28 22:24:55 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_tetriminos{
	int				number;
	int				x[4];
	int				y[4];
    int             current_position;
	int				coordination[4];
}					t_tetriminos;

typedef struct		s_map{
	int				size;
	int				width;
	int				amount;
	char			solution[241];
}					t_map;
 
int					amount_tetriminos(char *input);
int					validation(char *input, int amount);

t_tetriminos		*fill_objects(char *input, int amount);

void                next_step(t_tetriminos *objects, t_map *map, int position);
int                 next_position(t_tetriminos *object, t_map *map);

int                 minimal_map_size(int amount);

int					free_place(t_tetriminos *object, t_map *map);

t_map               *get_solution(t_tetriminos *objects, t_map *map);

#endif
