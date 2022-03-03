/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:13:20 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/03 14:03:04 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fexit(t_fdf	*fdf)
{
	if (fdf->img.handle)
		mlx_destroy_image(fdf->mlx, fdf->img.handle);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	free_map(fdf, 0);
	exit(1);
	return (0);
}

void	fdf_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < fdf->scr_size.x) && (y >= 0 && y < fdf->scr_size.y))
	{
		dst = fdf->img.addr + (y * fdf->img.line_length + x * \
		(fdf->img.bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	free_map(t_fdf *fdf, int true)
{
	int	i;

	i = 0;
	while (i < fdf->map_size.y)
		free(fdf->map[i++]);
	if (fdf->map)
		free(fdf->map);
	if (fdf)
		free(fdf);
	if (true)
		exit(1);
}
