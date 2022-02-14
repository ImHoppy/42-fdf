/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoppy <hoppy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:38:20 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/14 20:57:58 by hoppy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# ifndef __USE_MISC
#  define __USE_MISC
# endif

typedef struct s_fdf {
	void	*mlx;
	void	*win;
	int		**map;
}	t_fdf;

typedef struct s_data {
	void	*handle;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	test(void);
void	fexit(t_fdf	*fdf);
int		fdf_key_hook(int keycode, void *fdf);
void	fdf_pixel_put(t_data *data, int x, int y, int color);


// utils_draw
void	fdf_draw_lines(t_data *img, int beginX, int beginY, int endX, int endY);
void	fdf_draw_circle(t_data *img, int x, int y, int r);
int		create_trgb(int t, int r, int g, int b);
void	fdf_draw_line(t_data *img, int x, int y, int lenght, int color);
void	fdf_draw_square(t_data *img, int min, int max);
void	color_map(void *img,int w,int h);


#endif
