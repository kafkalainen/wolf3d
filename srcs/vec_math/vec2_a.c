/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:39:11 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/09 11:26:07 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy	vec2(float x, float y)
{
	return ((t_xy){x, y});
}

t_xy	vec2_sum(t_xy a, t_xy b)
{
	return ((t_xy)
	{
		a.x + b.x,
		a.y + b.y
	});
}

t_xy	vec2_sub(t_xy a, t_xy b)
{
	return ((t_xy)
	{
		a.x - b.x,
		a.y - b.y
	});
}

float	vec2_perp_dist(t_xy a)
{
	return (fabsf(a.x + a.y) * SQR2);
}

t_xy	vec2_mult(t_xy v, float scalar)
{
	return ((t_xy){
		v.x * scalar,
		v.y * scalar
	});
}
