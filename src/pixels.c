/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apresas- <apresas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 23:08:28 by jenavarr          #+#    #+#             */
/*   Updated: 2024/04/10 13:44:38 by apresas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_img(t_data *data, int width, int height)
{
	t_img	*img_p;

	img_p = (t_img *)malloc(sizeof(t_img));
	img_p->img = mlx_new_image(data->mlx.mlx, width, height);
	img_p->addr = mlx_get_data_addr(img_p->img, \
	&img_p->bpp, &img_p->line, &img_p->endian);
	if (!img_p->addr)
		c3d_exit("Failed to get image address");
	return (img_p);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= WINX || y >= WINY || x < 0 || y < 0)
		return ;
	pixel = img->addr + (y * img->line) + (x * (img->bpp / 8));
	*(unsigned int *)pixel = (unsigned int)color;
}

unsigned int get_pixel_color(t_img *image, int x, int y)
{
	unsigned char	*rgb;
	unsigned int	color;

	// provisional for debugging
	if (x >= image->size[X] || y >= image->size[Y])
		c3d_exit("WARNING: get_pixel_color got out of bounds coordinatesA");
	if (x < 0 || y < 0)
		c3d_exit("WARNING: get_pixel_color got out of bounds coordinatesB");
	//
	rgb = (unsigned char *)image->addr + ((y * image->line) + (x * (image->bpp / 8)));
	color = (*rgb) + (*(rgb + 1) << 8) + (*(rgb + 2) << 16);
	// ft_printf("x=%d, y=%d\n", x, y);
	// ft_printf("r %d\n", *rgb);
	// ft_printf("g %d\n", *(rgb + 1));
	// ft_printf("b %d\n", *(rgb + 2));
	// color = (*rgb);
	return (color);
}
