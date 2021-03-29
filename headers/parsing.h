/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:10:02 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 11:33:02 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

t_point		*new_point(t_xy x0, int idx);
void		add_point(t_point **point, t_point *new);
void		add_points(t_sector *sector, unsigned char *buf,
	unsigned int  **pos);
void		free_points(t_point **head, unsigned int nbr_of_walls);
void		free_sectors(t_home *home);
t_sector	*get_sector_data(unsigned char *buf, unsigned int *pos);
void		calc_norm_vectors(t_home *home);

#endif
