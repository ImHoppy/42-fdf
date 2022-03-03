/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:15 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/03 16:34:31 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
// https://fr.wikipedia.org/wiki/Sinus_(math%C3%A9matiques)
// https://fr.wikipedia.org/wiki/Cosinus
// Line algo
// https://classic.csunplugged.org/documents/activities/community-activities/line-drawing/line-drawing.pdf\\

// https://www.khanacademy.org/computing/computer-programming/programming-games-visualizations/programming-3d-shapes/a/rotating-3d-shapes

// 456 = BLUE

// 65307 == esc

void	draw_hud(t_fdf *fdf)
{
	int		x;
	int		y;
	int		col;
	void	*mlx;
	void	*win;

	x = fdf->scr_size.x * 0.05;
	y = fdf->scr_size.y * 0.1;
	// draw_rect();
	col = 0xFFFFFF;
	mlx = fdf->mlx;
	win = fdf->win;
	// mlx_string_put(mlx, win, x - 20, y, col, "Usage");
	// mlx_string_put(mlx, win, x, y, col, "Hide HUD:       h");
	mlx_string_put(mlx, win, x, y + 0, col, "Move            q w a d");
	mlx_string_put(mlx, win, x, y + 20, col, "Zoom            ^ v");
	mlx_string_put(mlx, win, x, y + 40, col, "Angle           < >");
	mlx_string_put(mlx, win, x, y + 60, col, "Depth up        page up");
	mlx_string_put(mlx, win, x, y + 80, col, "Depth down      page down");
	mlx_string_put(mlx, win, x, y + 100, col, "Projection      p");
	mlx_string_put(mlx, win, x, y + 120, col, "Color           c");

}

int	draw_rect(t_fdf *fdf, t_vector2 start, t_vector2 end, int color)
{
	int	i;
	int	j;

	i = start.y;
	while (i < start.y + end.y)
	{
		j = start.x;
		while (j < start.x + start.x)
			fdf_pixel_put(fdf, j++, i, color);
		++i;
	}
	return (0);
}

void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

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
}

void	fdf_init(t_fdf	*fdf)
{
	*fdf = (t_fdf){
		.mlx = fdf->mlx, .img = fdf->img, .win = fdf->win,
		.projection = 1, .color = 0,
		.map = fdf->map, .map_size = fdf->map_size,
		.zoom = 15, .angle = 0, .depth = 1,
		.scr_size.x = 1920, .scr_size.y = 1080
	};
	fdf->pos = (t_vector2){.x = (fdf->scr_size.x - fdf->zoom) / 2, \
	.y = (fdf->scr_size.y - fdf->zoom) / 2};
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
	mlx_key_hook(fdf->win, &fdf_key_hook, fdf); // reverse this commit f394d49614f54cc1fa0ba13351a64c078fe34140 and use mlx_hook(fdf->win, KEYPRESS, 0, &fdf_key_hook, fdf);
	mlx_hook(fdf->win, ON_DESTROY, 0, &fexit, fdf);
	mlx_loop(fdf->mlx);
	fexit(fdf);
}
