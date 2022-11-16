/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:21:43 by pbureera          #+#    #+#             */
/*   Updated: 2022/11/16 15:13:09 by pbureera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*f_strchr(char *s, int c);
char	*f_strjoin(char *s1, char *s2);
char	*f_strdup(char *s1);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);

#endif
