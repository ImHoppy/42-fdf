/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:38:20 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/28 15:16:53 by mbraets          ###   ########.fr       */
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
	int		pos_x;
	int		pos_y;
	float	angle;
	t_data	img;
}	t_fdf;


# define KEY_ESCAPE 0xff1b

# define KEY_UP 0xff52
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_DOWN 0xff54
# define KEY_Q 0x0071
# define KEY_W 0x0077
# define KEY_E 0x0065
# define KEY_R 0x0072
# define KEY_T 0x0074
# define KEY_Y 0x0079
# define KEY_U 0x0075
# define KEY_I 0x0069
# define KEY_O 0x006f
# define KEY_P 0x0070
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_F 0x0066
# define KEY_G 0x0067
# define KEY_H 0x0068
# define KEY_J 0x006a
# define KEY_K 0x006b
# define KEY_L 0x006c
# define KEY_Z 0x007a
# define KEY_X 0x0078
# define KEY_C 0x0063
# define KEY_V 0x0076
# define KEY_B 0x0062
# define KEY_N 0x006e
# define KEY_M 0x006d

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
