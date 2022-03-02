/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:15 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/02 18:53:44 by mbraets          ###   ########.fr       */
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


void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_memset(fdf->img.addr, 0x00181720, fdf->img.line_length * fdf->scr_size.y);
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
		.map = fdf->map, .map_size = fdf->map_size,
		.zoom = 15, .angle = 0, .depth = 1,
		.scr_size.x = 1280, .scr_size.y = 720
	};
	fdf->pos = (t_vector2){.x = (fdf->scr_size.x - fdf->zoom) / 2, .y = (fdf->scr_size.y - fdf->zoom) / 2};
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (2);
	fdf = malloc(sizeof(struct s_fdf));
	parse_file(argv[1], fdf);
	for (int i = 0; i < fdf->map_size.y; i++)
	{
		for (int j = 0; j < fdf->map_size.x; j++)
		{
			printf("%3d", fdf->map[i][j]);
		}
		printf("\n");
	}
	fdf_init(fdf);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fexit(fdf);
	fdf->win = mlx_new_window(fdf->mlx, fdf->scr_size.x, fdf->scr_size.y, "Fdf : mbraets");
	fdf->img.handle = mlx_new_image(fdf->mlx, fdf->scr_size.x, fdf->scr_size.y);
	fdf->img.addr = mlx_get_data_addr(fdf->img.handle, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.handle, 0, 0);
	mlx_key_hook(fdf->win, &fdf_key_hook, fdf); // reverse this commit f394d49614f54cc1fa0ba13351a64c078fe34140 and use mlx_hook(fdf->win, KEYPRESS, 0, &fdf_key_hook, fdf);
	mlx_hook(fdf->win, ON_DESTROY, 0, &fexit, fdf);
	mlx_loop(fdf->mlx);
	fexit(fdf);
}
