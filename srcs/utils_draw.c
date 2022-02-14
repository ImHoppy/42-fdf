/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoppy <hoppy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:27:54 by hoppy             #+#    #+#             */
/*   Updated: 2022/02/14 19:34:20 by hoppy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	x = w;
	while (x--)
	{
		y = h;
		while (y--)
		{
			color = (x*255)/w+((((w-x)*255)/w)<<16)+(((y*255)/h)<<8);
			fdf_draw_line(img, x, 1, y, color);
			
		}
	}
}
