/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:27:54 by hoppy             #+#    #+#             */
/*   Updated: 2022/03/03 12:57:06 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	mod(double i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	mul(float *x, float *y, float value)
{
	*x *= value;
	*y *= value;
}

void	_div(float *x, float *y, float value)
{
	*x /= value;
	*y /= value;
}

unsigned int	minecraft_fade(int h)
{
	if (h > 70)
		return (0xE9EAF0);
	if (h > 62)
		return (0xC4C1BD);
	if (h > 50)
		return (0x4C591A);
	if (h > 10)
		return (0x4C591A);
	if (h > 1)
		return (0x4D5E36);
	if (h > 0)
		return (0xD8D19C);
	if (h > -5)
		return (0x444CC6);
	if (h > -10)
		return (0x2A2EAE);
	if (h > -30)
		return (0x3D497C);
	return (0x05093d);
}

unsigned int	fade(int h)
{
	if (h > 100)
		return (0xFFDF8D);
	if (h > 75)
		return (0xFFDE7A);
	if (h > 50)
		return (0xFFC568);
	if (h > 25)
		return (0xFD996B);
	if (h > 15)
		return (0xF7856C);
	if (h > 10)
		return (0xF06E6C);
	if (h > 5)
		return (0xD9576B);
	if (h > 0)
		return (0xA44369);
	if (h > -10)
		return (0x833F68);
	if (h > -20)
		return (0x833F68);
	if (h > -50)
		return (0x5E3C65);
	return (0x3F3A63);
}

float	deg_rad(float angle)
{
	return (angle * M_PI / 180);
}

void	isometric(t_vector2 *pos, t_vector2 *end, float z, float endz)
{
	pos->x = (pos->x - pos->y) * cos(1);
	pos->y = (pos->x + pos->y) * sin(1) - z;
	end->x = (end->x - end->y) * cos(1);
	end->y = (end->x + end->y) * sin(1) - endz;
}

void	fdf_draw(t_fdf *fdf, t_vector2 pos, t_vector2 end)
{
	float	z;
	float	endz;
	t_vector2 temp;
	t_vector2 endtemp;

	z = fdf->map[(int)pos.y][(int)pos.x];
	endz = fdf->map[(int)end.y][(int)end.x];
	
	temp = (t_vector2){pos.x - fdf->map_size.x / 2, pos.y - fdf->map_size.y / 2};
	endtemp = (t_vector2){end.x - fdf->map_size.x / 2, end.y - fdf->map_size.y / 2};
	pos.x = temp.x * cos(fdf->angle) - temp.y * sin(fdf->angle);
	pos.y = temp.y * cos(fdf->angle) + temp.x * sin(fdf->angle);
	end.x = endtemp.x * cos(fdf->angle) - endtemp.y * sin(fdf->angle);
	end.y = endtemp.y * cos(fdf->angle) + endtemp.x * sin(fdf->angle);
	// Zoom and depth
	mul(&pos.x, &pos.y, fdf->zoom);
	mul(&end.x, &end.y, fdf->zoom);
	mul(&z, &endz, fdf->depth);
	// Isometric
	if (fdf->projection == 1)
		isometric(&pos, &end, z, endz);
	// Moving
	pos.x += fdf->pos.x;
	pos.y += fdf->pos.y;
	end.x += fdf->pos.x;
	end.y += fdf->pos.y;
	fdf_draw_lines(fdf, pos, end, (t_vector2){z, endz});
}

void	fdf_draw_lines(t_fdf *fdf, t_vector2 pos, t_vector2 end, t_vector2 z)
{
	float	delta_x;
	float	delta_y;
	int		max;
	int		color;

	delta_x = end.x - pos.x;
	delta_y = end.y - pos.y;
	max = fmax(mod(delta_x), mod(delta_y));
	delta_x /= max;
	delta_y /= max;
	color = minecraft_fade(fmax(z.x, z.y));
	while ((int)(pos.x - end.x) || (int)(pos.y - end.y))
	{
		fdf_pixel_put(fdf, pos.x, pos.y, color);
		pos.x += delta_x;
		pos.y += delta_y;
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
	// 	fdf_isometric(fdf, 
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
