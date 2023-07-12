/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:17:19 by ohortal-          #+#    #+#             */
/*   Updated: 2023/06/29 13:04:35 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>

char	*read_line(int fd, char *storage);
char	*first_line(char *storage);
char	*delete_first_line(char *storage);
char	*get_next_line(int fd);
int		my_strlen(char *str);
char	*my_strchr(const char *str, int c);
char	*my_strjoin(char *buffer, char *tail, ssize_t size);
void	*true_free(char **buffer);
void	*my_calloc(size_t count, size_t size);

#endif
