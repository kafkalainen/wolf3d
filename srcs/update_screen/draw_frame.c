/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:47:19 by jnivala           #+#    #+#             */
/*   Updated: 2021/04/07 13:36:43 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

t_xy			center_to_screen(t_xy loc)
{
	loc.x += 0.5 * SCREEN_WIDTH;
	loc.y += 0.5 * SCREEN_HEIGHT;
	return (loc);
}

static char		*compass_direction(t_xy *dir)
{
	if (dir->x <= N && dir->x > NW)
		return (ft_strdup("N"));
	else if (dir->x <= NW && dir->x > W)
		return (ft_strdup("NW"));
	else if (dir->x <= W && dir->x > SW)
		return (ft_strdup("W"));
	else if (dir->x <= SW && dir->x > S)
		return (ft_strdup("SW"));
	else if (dir->x <= S && dir->x > SE)
		return (ft_strdup("S"));
	else if (dir->x <= SE && dir->x > E)
		return (ft_strdup("SE"));
	else if (dir->x <= E && dir->x > NE)
		return (ft_strdup("E"));
	else if (dir->x <= NE && dir->x > N)
		return (ft_strdup("NE"));
	else
		return (ft_strdup("NO DIR"));
}

void			draw_minimap(t_home *home, t_frame *frame)
{
	unsigned int	i;
	unsigned int	j;
	t_point			*temp;
	t_xy			fov_left;
	t_xy			fov_right;

	i = 0;
	fov_right = vec2(0.0f, 1.0f);
	fov_left = vec2(1.0f, 0.0f);
	while (i < home->nbr_of_sectors)
	{
		j = 0;
		temp = home->sectors[i]->points;
		while (j < home->sectors[i]->nbr_of_walls)
		{
			draw_line(center_to_screen(temp->x0),
				center_to_screen(temp->next->x0), greenyellow, frame->draw_surf);
			temp = temp->next;
			j++;
		}
		i++;
	}
	draw_rect(center_to_screen((t_xy){0.0f, 0.0f}),
				(t_xy){3.0f, 3.0f}, frame, yellow);
	draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
		center_to_screen(vec2_add((t_xy){0.0f, 0.0f},
	 	vec2_mul(fov_left, 400))), lightgreen, frame->draw_surf);
	draw_line(center_to_screen((t_xy){0.0f, 0.0f}),
		center_to_screen(vec2_add((t_xy){0.0f, 0.0f},
	 	vec2_mul(fov_right, 400))), lightgreen, frame->draw_surf);

}

void			draw_2d_fov(t_frame *frame, t_player *plr)
{
	char	*sector;
	char	*compass;

	compass = compass_direction(&plr->dir);
	sector = ft_itoa(plr->current_sector);
	str_pxl(frame, (t_xy){0, 50}, "dir: ");
	str_pxl(frame, (t_xy){50, 50}, compass);
	str_pxl(frame, (t_xy){0, 70}, "sector:");
	str_pxl(frame, (t_xy){0, 90}, sector);
	free(sector);
	free(compass);
}

void			draw_frame(t_home *home, t_frame *frame, t_player *plr)
{
	frame->idx = plr->current_sector;
	frame->old_idx = -1;
	frame->max_fov = 0;
	frame->offset = 640;
	frame->left.l_pt = vec2(-1,-1);
	frame->right.r_pt = vec2(-1,-1);
	frame->plr_offset = vec2(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f);
	frame->pxl_offset = 0.0f;
	scan_fov(home, frame, plr, 0);
	draw_2d_fov(frame, plr);
	draw_minimap(home, frame);
}
