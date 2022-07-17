/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 14:02:01 by mbraets           #+#    #+#             */
/*   Updated: 2022/07/17 18:40:00 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_key_move(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->pos.y -= 20;
	if (keycode == KEY_W)
		fdf->pos.y += 20;
	if (keycode == KEY_D)
		fdf->pos.x -= 20;
	if (keycode == KEY_A)
		fdf->pos.x += 20;
	if (keycode == KEY_LEFT)
		fdf->angle -= 0.1;
	if (keycode == KEY_RIGHT)
		fdf->angle += 0.1;
}

int	fdf_key_hook(int keycode, void *data)
{
	t_fdf	*fdf;

	fdf = data;
	if (keycode == KEY_ESCAPE)
		fexit(fdf);
	if (keycode == KEY_P)
		fdf->projection = -fdf->projection;
	if (keycode == KEY_C)
		fdf->color++;
	if (keycode == KEY_R)
		fdf_init(fdf);
	if (keycode == KEY_UP)
		fdf->zoom += 1;
	if (keycode == KEY_DOWN)
		if (fdf->zoom > 2)
			fdf->zoom -= 1;
	if (keycode == KEY_P_UP || keycode == 61)
		fdf->depth += 0.1;
	if (keycode == KEY_P_DOWN  || keycode == 45)
		fdf->depth -= 0.1;
	fdf_key_move(keycode, fdf);
	draw(fdf);
	if (keycode == KEY_R)
		draw_hud(fdf);
	return (0);
}
