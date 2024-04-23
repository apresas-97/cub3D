/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:23:55 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/23 20:02:47 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_data *data)
{
	render(data);
	data->frame++;
	if (data->frame % 5 == 0)
	{
		data->sprite.i = (data->sprite.i + 1) % data->sprite.frames;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (verify_arguments(argc, argv) == FAILURE)
		return (1);
	init_data(&data);
	parser(&data, argv[1]);
	mlx_loop_hook(data.mlx.mlx, game_loop, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
