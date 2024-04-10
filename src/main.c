/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:23:55 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/09 17:17:59 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_variables(t_data *data)
{
	data->player.pos[X] = data->map.spawn[Y] + 0.5;
	data->player.pos[Y] = data->map.spawn[X] + 0.5;
	data->player.dir[X] = data->map.player_dir[X];
	data->player.dir[Y] = data->map.player_dir[Y];
	data->player.plane[X] = fabs(data->player.dir[Y]) * 0.66;
	data->player.plane[Y] = fabs(data->player.dir[X]) * 0.66; //TENER CUIDADO LUEGO CUANDO SE UTILIZE EL PLANE PORQUE EL EJE VERTICAL VA AL REVES
}

void	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		c3d_exit("Error\nFailed to initialize mlx\n");
	data->mlx.window = mlx_new_window(data->mlx.mlx, WINX, WINY, "QUAKE 3D");
	if (!data->mlx.window)
		c3d_exit("Error\nFailed to create window\n");
	data->mlx.texture_size = 64;
	data->mlx.win_img = get_img(data, WINX, WINY);
	hook(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	verify_arguments(argc, argv);
	init_mlx(&data);
	parser(&data, argv[1]);
	initialize_variables(&data);
	render(&data);
	//print_map_grid(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}

