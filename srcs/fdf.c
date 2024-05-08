/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:15 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/04 11:39:17 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw_hud(t_fdf *fdf)
{
	int		x;
	int		y;
	int		col;
	void	*mlx;
	void	*win;

	x = fdf->scr_size.x * 0.05;
	y = fdf->scr_size.y * 0.1;
	col = 0xD3D3D3;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_set_font(mlx, win, "8x13");
	mlx_string_put(mlx, win, x, y, col, "Move            q w a d");
	mlx_string_put(mlx, win, x, y + 20, col, "Zoom            ^ v");
	mlx_string_put(mlx, win, x, y + 40, col, "Angle           < >");
	mlx_string_put(mlx, win, x, y + 60, col, "Depth up        page up");
	mlx_string_put(mlx, win, x, y + 80, col, "Depth down      page down");
	mlx_string_put(mlx, win, x, y + 100, col, "Color           c");
	mlx_string_put(mlx, win, x, y + 120, col, "Projection      p");
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_memset(fdf->img.addr, 0x181720, fdf->img.line_length * fdf->scr_size.y);
	y = 0;
	while (y < fdf->map_size.y)
	{
		x = 0;
		while (x < fdf->map_size.x)
		{
			if (x < fdf->map_size.x - 1)
				fdf_draw(fdf, (t_vector2){x, y}, (t_vector2){x + 1, y});
			if (y < fdf->map_size.y - 1)
				fdf_draw(fdf, (t_vector2){x, y}, (t_vector2){x, y + 1});
			x++;
		}
		y++;
	}
	x = fdf->scr_size.x * 0.05;
	y = fdf->scr_size.y * 0.1;
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.handle, 0, 0);
}

void	fdf_init(t_fdf	*fdf)
{
	*fdf = (t_fdf){
		.mlx = fdf->mlx,
		.img = fdf->img,
		.win = fdf->win,
		.projection = 1,
		.color = 0,
		.map = fdf->map,
		.map_size = fdf->map_size,
		.zoom = 15,
		.angle = 0,
		.depth = 1,
		.scr_size.x = 1920,
		.scr_size.y = 1080
	};
	fdf->pos = (t_vector2){
		.x = (fdf->scr_size.x - fdf->zoom) / 2,
		.y = (fdf->scr_size.y - fdf->zoom) / 2
	};
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (2);
	fdf = malloc(sizeof(struct s_fdf));
	parse_file(argv[1], fdf);
	fdf_init(fdf);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fexit(fdf);
	fdf->win = mlx_new_window(fdf->mlx, fdf->scr_size.x, \
	fdf->scr_size.y, "Fdf : mbraets");
	fdf->img.handle = mlx_new_image(fdf->mlx, fdf->scr_size.x, fdf->scr_size.y);
	fdf->img.addr = mlx_get_data_addr(fdf->img.handle, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	draw(fdf);
	draw_hud(fdf);
	mlx_key_hook(fdf->win, &fdf_key_hook, fdf);
	mlx_hook(fdf->win, ON_DESTROY, 0, &fexit, fdf);
	mlx_loop(fdf->mlx);
	fexit(fdf);
}
