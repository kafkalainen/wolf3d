/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnivala <jnivala@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:59:09 by jnivala           #+#    #+#             */
/*   Updated: 2021/03/29 11:40:29 by jnivala          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

/*
** Event handlers
*/

void			keys_up(t_player *plr, SDL_KeyCode sym);
void			keys_down(t_player *plr, SDL_KeyCode sym, SDL_Event *e);
void			key_input(t_player *plr, SDL_Event *e);
void			mouse_handle(t_player *plr, t_home *home, SDL_Event *e);

#endif
