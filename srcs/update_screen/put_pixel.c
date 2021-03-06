/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:38:46 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/13 17:16:15 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy			scale(t_xy a)
{
	return (vec2(a.x * MINIMAP_SIZE, a.y * MINIMAP_SIZE));
}

void			clear_surface(SDL_Surface *surface)
{
	int		i;
	int		pixel_amount;

	i = 0;
	pixel_amount = SCREEN_HEIGHT * SCREEN_WIDTH;
	while (i < pixel_amount)
	{
		put_pixel(surface, i % SCREEN_WIDTH, i / SCREEN_WIDTH, 0);
		i++;
	}
}

Uint32			get_pixel(SDL_Surface *surface, int x, int y)
{
	int		bpp;
	Uint32	*p;

	bpp = surface->format->BytesPerPixel;
	p = (Uint32 *)((Uint8 *)surface->pixels +
		y * surface->pitch + x * bpp);
	return (*p);
}

Uint32			get_texel(t_texture *tex, int x, int y)
{
	Uint32	*p;
	Uint32	color;

	x = x % tex->w;
	y = y % tex->h;
	p = tex->pixels + (x + tex->w * y);
	color = *p;
	return (color);
}

void			put_pixel(SDL_Surface *surf, int x, int y, int color)
{
	int		*pixel;

	if (x > SCREEN_WIDTH - 1 || y > SCREEN_HEIGHT - 1 || x < 0 || y < 0)
		return ;
	pixel = surf->pixels + y * surf->pitch +
		x * surf->format->BytesPerPixel;
	*pixel = color;
}
