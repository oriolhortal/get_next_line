/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:00:19 by ohortal-          #+#    #+#             */
/*   Updated: 2023/05/26 13:29:33 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
//# define BUFFER_SIZE 42

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
