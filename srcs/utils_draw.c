/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:27:54 by hoppy             #+#    #+#             */
/*   Updated: 2022/02/28 12:47:44 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(double i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	fdf_draw_lines(t_fdf *fdf, float x, float y, float endx, float endy)
{
	float	delta_x;
	float	delta_y;
	int		max;
	int		z;
	int		endz;
	int		color;

	z = fdf->map[(int)y][(int)x];
	endz = fdf->map[(int)endy][(int)endx];
	x *= fdf->zoom;
	y *= fdf->zoom;
	endx *= fdf->zoom;
	endy *= fdf->zoom;
	if (z)
		color = 0x00118DFF;
	else
		color = 0x000000FF;
	x = (x - y) * cos(fdf->angle);
	y = (x + y) * sin(fdf->angle) - z;
	endx = (endx - endy) * cos(fdf->angle);
	endy = (endx + endy) * sin(fdf->angle) - endz;
	x += 150;
	y += 150;
	endx += 150;
	endy += 150;
	delta_x = endx - x;
	delta_y = endy - y;
	max = fmax(mod(delta_x), mod(delta_y));
	delta_x /= max;
	delta_y /= max;

	while ((int)(x - endx) || (int)(y - endy))
	{
		fdf_pixel_put(fdf, x, y, color);
		x += delta_x;
		y += delta_y;
	}
}

void	fdf_draw_lines_(t_fdf *fdf, int beginX, int beginY, int endX, int endY)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	beginX *= fdf->zoom;
	beginY *= fdf->zoom;

	endX *= fdf->zoom;
	endY *= fdf->zoom;

	delta_x = endX - beginX; // 10
	delta_y = endY - beginY; // 0
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));

	delta_x /= pixels; // 1
	delta_y /= pixels; // 0

	pixel_x = beginX;
	pixel_y = beginY;
	while (pixels)
	{
		fdf_pixel_put(fdf, pixel_x, pixel_y, 0x00FFFF00);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}

void	fdf_draw_circle(t_fdf *fdf, int x, int y, int r)
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
		fdf_pixel_put(fdf, x + x1, y + y1, 456);
		i += 0.1;
	}
	// for(int a=0; a < 6; a++)
	// {
	// 	fdf_draw_lines(fdf, 
	// 	x + r * cos(a * 60 * M_PI / 180), 
	// 	y + r * sin(a * 60 * M_PI / 180),
	// 	x + r * cos((a+1) * 60 * M_PI / 180), 
	// 	y + r * sin((a+1) * 60 * M_PI / 180));
	// }
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	fdf_draw_line(t_fdf *fdf, int x, int y, int lenght, int color)
{
	int	pos;
	pos = 0;
	while (pos <= lenght)
	{

		fdf_pixel_put(fdf, x + pos, y, color);
		pos++;
	}
}

void	fdf_draw_square(t_fdf *fdf, int min, int max)
{
	int	pos;
	
	pos = min;
	while (pos <= max)
	{
		fdf_pixel_put(fdf, pos, min, 456);
		fdf_pixel_put(fdf, pos, max, 456);
		fdf_pixel_put(fdf, min, pos, 456);
		fdf_pixel_put(fdf, max, pos, 456);
		pos++;
	}
}

void	color_map(void *fdf,int w,int h)
{
	int	x;
	int	y;
	int	color;
	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
			fdf_draw_line(fdf, x, 1, y, color);
			
		}
	}
}
