/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoppy <hoppy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:35:48 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/14 20:02:45 by hoppy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		gnl_strlen(char *s);
int		gnl_str_eol(char *s);
char	*gnl_strncpy(char *dst, char *src, int len);
char	*gnl_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif
