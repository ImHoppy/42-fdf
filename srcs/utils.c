/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:13:20 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/01 12:41:03 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fexit(t_fdf	*fdf)
{
	if (fdf->img.handle)
		mlx_destroy_image(fdf->mlx, fdf->img.handle);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
		mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	free_map(fdf, 0);
	free(fdf);
	exit(1);
}

void	fdf_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;
	
	dst = fdf->img.addr + (y * fdf->img.line_length + x * (fdf->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
