/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emedea <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:39:21 by emedea            #+#    #+#             */
/*   Updated: 2019/05/27 14:33:26 by emedea           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_tetriminos{
	int				number;
	int				x[4];
	int				y[4];
}					t_tetriminos;

typedef struct		s_map{
	int				size;
	char			*solution;
}					t_map;
 
int					amount_tetriminos(char *input);
int					validation(char *input);

t_tetriminos		*fill_objects(char *input, int amount);
t_tetriminos        *next_combination(t_tetriminos *input, int amount);
int                 last_combination(t_tetriminos *input, int amount);

int                 minimal_map_size(int amount);
void                new_coordinates(t_tetriminos *new, t_tetriminos *old, int x, int y);
int                 is_here_place(t_tetriminos *new, t_map *map);
void                current_map_position(t_map *map, int *k, int *x, int *y);
void                write_tetriminos_to_map(t_tetriminos *new, t_map *map, int number);

t_map				generate_map(t_tetriminos *objects, int amount, int map_size, int x, int y, int test);

#endif
