/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoppy <hoppy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 14:04:15 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/14 21:49:22 by hoppy            ###   ########.fr       */
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
int	fdf_key_hook(int keycode, void *fdf)
{
	dprintf(1, "%d\n", keycode);
	if (keycode == 65307)
	{
		fexit(fdf);
	}
	return (0);
}

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
	img.handle = mlx_new_image(fdf->mlx, 1280, 720);
	img.addr = mlx_get_data_addr(img.handle, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	// fdf_pixel_put(&img, 5, 5, 0x0000FF00);
	// fdf_pixel_put(&img, 5, 5, 0xFFFF0000);
	// fdf_draw_square(&img, 0, 400);
	// fdf_draw_square(&img, 200, 400);
	// fdf_draw_square(&img, 0, 200);
	//fdf_draw_line(&img, 1, 201, 100);
	// fdf_draw_circle(&img, 400, 400, 300);
	// color_map(&img, 100, 100);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img.handle, 0, 0);
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