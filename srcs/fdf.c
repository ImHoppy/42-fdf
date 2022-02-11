/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:15 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/11 17:54:38 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
// https://fr.wikipedia.org/wiki/Sinus_(math%C3%A9matiques)
// https://fr.wikipedia.org/wiki/Cosinus
// Line algo
// https://classic.csunplugged.org/documents/activities/community-activities/line-drawing/line-drawing.pdf

// 456 = BLUE

// 65307 == esc
int	fdf_key_hook(int keycode, void *fdf)
{
	dprintf(1, "%d\n", keycode);
	if (keycode == 65307)
	{
		fexit(fdf);
	}
	return (0);
}

void	fdf_draw_lines(t_data *img, int beginX, int beginY, int endX, int endY)
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));

	deltaX /= pixels; // 1
	deltaY /= pixels; // 0

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		fdf_pixel_put(img, pixelX, pixelY, 0x00FFFF00);
		pixelX += deltaX;
		pixelY += deltaY;
		pixels--;
	}
}

void	fdf_draw_circle(t_data *img, int x, int y, int r)
{
	double	i;
	double	angle;
	double	x1;
	double	y1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * M_PI / 180);
		y1 = r * sin(angle * M_PI / 180);
		fdf_pixel_put(img, x + x1, y + y1, 456);
		i += 0.1;
	}
	for(int a=0; a < 6; a++)
	{
		fdf_draw_lines(img, 
		x + r * cos(a * 60 * M_PI / 180), 
		y + r * sin(a * 60 * M_PI / 180),
		x + r * cos((a+1) * 60 * M_PI / 180), 
		y + r * sin((a+1) * 60 * M_PI / 180));
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	fdf_draw_line(t_data *img, int x, int y, int lenght, int color)
{
	int	pos;
	pos = 0;
	while (pos <= lenght)
	{

		fdf_pixel_put(img, x + pos, y, color);
		pos++;
	}
}

void	fdf_draw_square(t_data *img, int min, int max)
{
	int	pos;
	
	pos = min;
	while (pos <= max)
	{
		fdf_pixel_put(img, pos, min, 456);
		fdf_pixel_put(img, pos, max, 456);
		fdf_pixel_put(img, min, pos, 456);
		fdf_pixel_put(img, max, pos, 456);
		pos++;
	}
}

void	color_map(void *img,int w,int h)
{
	int	x;
	int	y;
	int	color;
	double lenght;
	lenght = 1;
	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			lenght += 0.1;
			color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
			fdf_draw_line(img, x, 1, y, color);
			
		}
	}
}

int	main(void)
{
	t_fdf	*fdf;
	t_data	img;

	fdf = malloc(sizeof(struct s_fdf));
	if (!fdf)
		return (2);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fexit(fdf);
	fdf->win = mlx_new_window(fdf->mlx, 1280, 720, "Test");
	if (!fdf->win)
		fexit(fdf);
	img.handle = mlx_new_image(fdf->mlx, 1280, 1080);
	img.addr = mlx_get_data_addr(img.handle, &img.bits_per_pixel,
			&img.line_length, &img.endian); 
	fdf_pixel_put(&img, 5, 5, 0x0000FF00);
	fdf_pixel_put(&img, 5, 5, 0xFFFF0000);
	fdf_draw_square(&img, 0, 400);
	fdf_draw_square(&img, 200, 400);
	fdf_draw_square(&img, 0, 200);
	//fdf_draw_line(&img, 1, 201, 100);
	fdf_draw_circle(&img, 400, 400, 300);
	color_map(&img, 100, 100);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.handle, 0, 0);
	mlx_key_hook(fdf->win, &fdf_key_hook, fdf);
	mlx_loop(fdf->mlx);
	fexit(fdf);
	return (0);
}
