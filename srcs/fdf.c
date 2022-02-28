/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:15 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/28 15:39:45 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

// https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html
// https://fr.wikipedia.org/wiki/Sinus_(math%C3%A9matiques)
// https://fr.wikipedia.org/wiki/Cosinus
// Line algo
// https://classic.csunplugged.org/documents/activities/community-activities/line-drawing/line-drawing.pdf

// 456 = BLUE

// 65307 == esc


void	draw(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_memset(fdf->img.addr, 0x00181720, fdf->img.line_length * 1000);
	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				fdf_draw_lines(fdf, x, y, x + 1, y);
			if (y < fdf->height - 1)
				fdf_draw_lines(fdf, x, y, x, y + 1);
			x++;
		}
		y++;
	}
}

int	fdf_key_hook(int keycode, void *data)
{
	t_fdf	*fdf = data;
	dprintf(1, "%d\n", keycode);
	if (keycode == KEY_ESCAPE)
	{
		free_map(fdf, 0);
		fexit(fdf);
	}
	if (keycode == KEY_UP)
		fdf->zoom += 2;
	if (keycode == KEY_DOWN)
		fdf->zoom -= 2;
	if (keycode == KEY_LEFT)
		fdf->angle -= 0.1;
	if (keycode == KEY_RIGHT)
		fdf->angle += 0.1;
	if (keycode == KEY_W)
		fdf->pos_y -= 20;
	if (keycode == KEY_S)
		fdf->pos_y += 20;
	if (keycode == KEY_A)
		fdf->pos_x -= 20;
	if (keycode == KEY_D)
		fdf->pos_x += 20;

	// mlx_clear_window(fdf->mlx, fdf->win);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.handle, 0, 0);
	return (0);
}
/*

int **ft_parse(int fd)
{
	int	**ret = NULL;
	t_list	**map = NULL;
	char	*line;
	int		i;
	int		n;
	int		y;
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != 0)
		{
			if (!ft_isdigit((int)line[i]) && line[i] != '-')
				i++;
			else
			{
				n = ft_atoi(line + i);
				printf("%2d ", n);
				ft_lstadd_back(&map[y], ft_lstnew(&n));
				while (ft_isdigit((int)line[i]) || line[i] == '-')
					i++;
			}
		}
		printf("\n");
		free(line);
		line = get_next_line(fd);
		y++;
	}
	printf("++++++++\n");
	for (int i = 0; i < y; i++)
	// map = ft_lstadd_back(map, ft_lstnew());
	{
		for (t_list *head = map[i]; head != NULL; head = head->next)
		{
			printf("%d ", (int*)head->content);
		}
		ft_lstclear(&map[i], free);
	}
	return (ret);
}
int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	t_data	img;
	int		**map;
	int		fd;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		return (2);
	map = ft_parse(fd);
	if (map == NULL)
		return (2);
	close(fd);
	fdf = malloc(sizeof(struct s_fdf));
	if (!fdf)
		return (2);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fexit(fdf);
	fdf->win = mlx_new_window(fdf->mlx, 1280, 720, "Test");
	if (!fdf->win)
		fexit(fdf);
	fdf->img.handle = mlx_new_image(fdf->mlx, 1280, 720);
	fdf->img.addr = mlx_get_data_addr(fdf->img.handle, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	// fdf_pixel_put(&img, 5, 5, 0x0000FF00);
	// fdf_pixel_put(&img, 5, 5, 0xFFFF0000);
	// fdf_draw_square(&img, 0, 400);
	// fdf_draw_square(&img, 200, 400);
	// fdf_draw_square(&img, 0, 200);
	//fdf_draw_line(&img, 1, 201, 100);
	// fdf_draw_circle(&img, 400, 400, 300);
	// color_map(&img, 100, 100);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.handle, 0, 0);
	mlx_key_hook(fdf->win, &fdf_key_hook, fdf);
	mlx_loop(fdf->mlx);
	fexit(fdf);
	return (0);
}
// int main(void)
// {
// 	char *test = " 43 222  3r4	3";
// 	printf("%d\n", ft_atoi(test));
// }
*/

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (2);
	fdf = malloc(sizeof(struct s_fdf));
	parse_file(argv[1], fdf);
	for (int i = 0; i < fdf->height; i++)
	{
		for (int j = 0; j < fdf->width; j++)
		{
			printf("%3d", fdf->map[i][j]);
		}
		printf("\n");
	}
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		fexit(fdf);
	fdf->zoom = 1;
	fdf->pos_x = 500;
	fdf->pos_y = 500;
	fdf->angle = 0.8;
	fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "Fdf : mbraets"); // CHECK ERR
	fdf->img.handle = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->img.addr = mlx_get_data_addr(fdf->img.handle, &fdf->img.bits_per_pixel,
			&fdf->img.line_length, &fdf->img.endian);
	draw(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.handle, 0, 0);
	mlx_key_hook(fdf->win, &fdf_key_hook, fdf);
	mlx_loop(fdf->mlx);
	free_map(fdf, 0);
	fexit(fdf);
}
