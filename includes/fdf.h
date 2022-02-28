/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:38:20 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/28 12:35:17 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# ifndef __USE_MISC
#  define __USE_MISC
# endif
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data {
	void	*handle;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fdf {
	int		height;
	int		width;
	void	*mlx;
	void	*win;
	int		**map;
	int		zoom;
	float	angle;
	t_data	img;
}	t_fdf;



void	test(void);
void	fexit(t_fdf	*fdf);
// int		fdf_key_hook(int keycode, void *fdf);
void	fdf_pixel_put(t_fdf *fdf, int x, int y, int color);


// utils_draw
void	fdf_draw_lines(t_fdf *fdf, float x, float y, float endx, float endy);
void	fdf_draw_lines_(t_fdf *fdf, int beginX, int beginY, int endX, int endY);

void	fdf_draw_circle(t_fdf *fdf, int x, int y, int r);
int		create_trgb(int t, int r, int g, int b);
void	fdf_draw_line(t_fdf *fdf, int x, int y, int lenght, int color);
void	fdf_draw_square(t_fdf *fdf, int min, int max);
void	color_map(void *img,int w,int h);

void	parse_file(char *file, t_fdf *fdf);
void	free_map(t_fdf *fdf, int);



#endif
