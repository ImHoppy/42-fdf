/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:27:54 by hoppy             #+#    #+#             */
/*   Updated: 2022/03/03 15:45:45 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_vector2 *pos, t_vector2 *end, float z, float endz)
{
	pos->x = (pos->x - pos->y) * cos(1);
	pos->y = (pos->x + pos->y) * sin(1) - z;
	end->x = (end->x - end->y) * cos(1);
	end->y = (end->x + end->y) * sin(1) - endz;
}

void	add_rotation(t_fdf	*fdf, t_vector2 *pos, t_vector2 *p2)
{
	t_vector2	t;
	t_vector2	t2;

	t = (t_vector2){pos->x - fdf->map_size.x / 2, pos->y - fdf->map_size.y / 2};
	t2 = (t_vector2){p2->x - fdf->map_size.x / 2, p2->y - fdf->map_size.y / 2};
	pos->x = t.x * cos(fdf->angle) - t.y * sin(fdf->angle);
	pos->y = t.y * cos(fdf->angle) + t.x * sin(fdf->angle);
	p2->x = t2.x * cos(fdf->angle) - t2.y * sin(fdf->angle);
	p2->y = t2.y * cos(fdf->angle) + t2.x * sin(fdf->angle);
}

void	fdf_draw(t_fdf *fdf, t_vector2 pos, t_vector2 end)
{
	float		z;
	float		endz;

	z = fdf->map[(int)pos.y][(int)pos.x];
	endz = fdf->map[(int)end.y][(int)end.x];
	add_rotation(fdf, &pos, &end);
	mul(&pos.x, &pos.y, fdf->zoom);
	mul(&end.x, &end.y, fdf->zoom);
	mul(&z, &endz, fdf->depth);
	if (fdf->projection == 1)
		isometric(&pos, &end, z, endz);
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
	if (fdf->color % 3 == 0)
		color = default_fade(fmax(z.x, z.y));
	if (fdf->color % 3 == 1)
		color = orange_fade(fmax(z.x, z.y));
	if (fdf->color % 3 == 2)
		color = minecraft_fade(fmax(z.x, z.y));
	while ((int)(pos.x - end.x) || (int)(pos.y - end.y))
	{
		fdf_pixel_put(fdf, pos.x, pos.y, color);
		pos.x += delta_x;
		pos.y += delta_y;
	}
}
