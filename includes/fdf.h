/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:38:20 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/04 12:21:53 by mbraets          ###   ########.fr       */
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

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_data {
	void	*handle;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_fdf {
	void		*mlx;
	void		*win;
	float		angle;
	int			zoom;
	int			projection;
	int			color;
	int			**map;
	float		depth;
	t_vector2	scr_size;
	t_vector2	map_size;
	t_vector2	pos;
	t_data		img;
}	t_fdf;

# define KEY_ESCAPE 0xff1b

# define KEY_UP 0xff52
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53
# define KEY_DOWN 0xff54
# define KEY_W 0x0077
# define KEY_R 0x0072
# define KEY_P 0x0070
# define KEY_A 0x0061
# define KEY_S 0x0073
# define KEY_D 0x0064
# define KEY_C 0x0063
# define KEY_P_UP 0xff55
# define KEY_P_DOWN 0xff56
# define ON_DESTROY 17

int				fexit(t_fdf	*fdf);
int				fdf_key_hook(int keycode, void *fdf);
void			fdf_pixel_put(t_fdf *fdf, int x, int y, int color);

void			fdf_init(t_fdf	*fdf);

// utils_draw
void			fdf_draw(t_fdf *fdf, t_vector2 pos, t_vector2 end);
void			fdf_draw_lines(t_fdf *fdf, \
t_vector2 pos, t_vector2 end, t_vector2 z);

void			parse_file(char *file, t_fdf *fdf);
void			free_map(t_fdf *fdf, int error);
void			check_file(char *file, t_fdf *fdf);

void			draw(t_fdf *fdf);
void			draw_hud(t_fdf *fdf);

// Math
float			mod(double i);
void			mul(float *x, float *y, float value);
unsigned int	minecraft_fade(int h);
unsigned int	default_fade(int h);
unsigned int	orange_fade(int h);

#endif
