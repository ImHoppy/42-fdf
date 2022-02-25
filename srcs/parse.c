/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:48:03 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/25 15:48:30 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	ft_countword(char const *s, char c)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			len++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		len++;
	return (len);
}

static void	set_height_width(char *file, t_fdf *fdf)
{
	int		fd;
	char	*line;

	fdf->height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit(1); // FREE
	line = get_next_line(fd);
	fdf->width = ft_countword(line, ' ');
	while (line)
	{
		fdf->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	fill_map_line(int *map_line, char *line)
{
	char	**split_line;
	int		i;

	split_line = ft_split(line, ' ');
	i = 0;
	while (split_line[i])
	{
		map_line[i] = ft_atoi(split_line[i]);
		free(split_line[i]);
		i++;
	}
	free(split_line);
}

void	free_map(t_fdf *fdf, int true)
{
	int	i;

	i = 0;
	while (i < fdf->height)
		free(fdf->map[i++]);
	if (fdf->map)
		free(fdf->map);
	if (true)
		exit(1);
}
void *xmalloc(size_t size)
{
	void *ptr;
	ptr = malloc(size);
	dprintf(1, "%p\n", ptr);
	return (ptr);
}

static void	alloc_map( t_fdf *fdf)
{
	int		i;

	fdf->map = xmalloc(sizeof(int *) * (fdf->height + 1));
	if (!fdf->map)
		exit(1);
	i = 0;
	while (i < fdf->height)
	{
		fdf->map[i] = xmalloc(sizeof(int) * (fdf->width + 1));
		if (!fdf->map[i])
			free_map(fdf, 1);
		i++;
	}
}

#include <stdio.h>
void	parse_file(char *file, t_fdf *fdf)
{
	int		fd;
	int		i;
	char	*line;

	set_height_width(file, fdf);
	alloc_map(fdf);
	fd = open(file, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_map_line(fdf->map[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	fdf->map[i] = NULL;
	close(fd);
}
