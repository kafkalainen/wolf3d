/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typewriter.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 09:46:39 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 10:30:39 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEWRITER_H
# define TYPEWRITER_H
# define TEXT_SIZE 3

typedef struct	s_pxl_c
{
	int			c[36];
}				t_pxl_c;


t_pxl_c			pxl_alphabet(int l, int b, int c);
t_pxl_c			pxl_numbers(int l, int b, int c);
void			str_pxl(t_frame *frame, t_xy coord, char *str);
#endif
