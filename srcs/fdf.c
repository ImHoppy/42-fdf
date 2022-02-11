/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:15 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/11 13:10:24 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
// https://fr.wikipedia.org/wiki/Sinus_(math%C3%A9matiques)
// https://fr.wikipedia.org/wiki/Cosinus
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

void fdf_draw_circle(t_data *img, int x, int y, int r)
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
}

void fdf_draw_square(t_data *img, int min, int max)
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
	fdf_pixel_put(&img, 5, 5, 0x00FF0000);
	fdf_draw_circle(&img, 400, 400, 300);
	fdf_draw_square(&img, 200, 400);	
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.handle, 0, 0);
	mlx_key_hook(fdf->win, &fdf_key_hook, fdf);
	mlx_loop(fdf->mlx);
	fexit(fdf);
	return (0);
}
