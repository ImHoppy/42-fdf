/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:38:20 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/11 12:33:47 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_fdf {
	void	*mlx;
	void	*win;
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

#endif
