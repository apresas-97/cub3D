/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:42:47 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/30 18:32:21 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hook(t_data *data)
{
	mlx_hook(data->mlx.window, DESTROY_NOTIFY, 0, c3d_close_window_exit, data);
	mlx_hook(data->mlx.window, KEY_PRESS, 1L << 0, keypressed, data);
}

int	keypressed(int keycode, t_data *data)
{
	if (keycode == KEY_RIGHT)
		rotate_player(data, data->player.rot_speed);
	else if (keycode == KEY_LEFT)
		rotate_player(data, -data->player.rot_speed);
	else if (keycode == KEY_W)
		move_forward(data);
	else if (keycode == KEY_S)
		move_back(data);
	else if (keycode == KEY_A)
		move_left(data);
	else if (keycode == KEY_D)
		move_right(data);
	else if (keycode == KEY_ESC)
		c3d_exit(NULL, data);
	else
		return (0);
	return (0);
}
