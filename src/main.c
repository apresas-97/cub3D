/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:23:55 by apresas-          #+#    #+#             */
/*   Updated: 2024/04/04 12:50:13 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	init_data_struct(&data);
	parser(&data, argc, argv);
	return (0);
}

// provisional:
void	init_data_struct(t_data *data)
{
	data->textures.north = NULL;
	data->textures.south = NULL;
	data->textures.west = NULL;
	data->textures.east = NULL;
	data->textures.floor = -1;
	data->textures.ceiling = -1;
	data->textures.stored_values = 0;
}
