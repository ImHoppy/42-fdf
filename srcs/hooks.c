/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:02:01 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/01 15:04:55 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	fdf_key_hook(int keycode, void *data)
{
	t_fdf	*fdf;

	fdf = data;
	dprintf(1, "%d\n", keycode);
	if (keycode == KEY_ESCAPE)
		fexit(fdf);
	if (keycode == KEY_UP)
		fdf->zoom += 2;
	if (keycode == KEY_DOWN)
		if (fdf->zoom > 0)
			fdf->zoom -= 2;
	if (keycode == KEY_LEFT)
		fdf->angle -= 0.1;
	if (keycode == KEY_RIGHT)
		fdf->angle += 0.1;
	if (keycode == KEY_W)
		fdf->pos.y -= 20;
	if (keycode == KEY_S)
		fdf->pos.y += 20;
	if (keycode == KEY_A)
		fdf->pos.x -= 20;
	if (keycode == KEY_D)
		fdf->pos.x += 20;
	if (keycode == KEY_P_UP)
		fdf->depth += 1;
	if (keycode == KEY_P_DOWN)
		fdf->depth -= 1;
	// mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.handle, 0, 0);
	return (0);
}
