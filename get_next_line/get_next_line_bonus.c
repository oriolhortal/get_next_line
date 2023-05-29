/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:00:47 by ohortal-          #+#    #+#             */
/*   Updated: 2023/05/26 13:29:14 by ohortal-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*read_line(int fd, char *storage)
{
	int		r;
	char	tmp[BUFFER_SIZE + 1];

	r = 1;
	tmp[0] = '\0';
	while (r > 0 && !my_strchr(storage, '\n'))
	{
		r = read(fd, tmp, BUFFER_SIZE);
		if (r == -1)
			return (true_free(&storage));
		if (r > 0)
		{
			tmp[r] = '\0';
			storage = my_strjoin (storage, tmp, r);
			if (!storage)
				return (NULL);
		}
	}
	return (storage);
}

char	*first_line(char *storage)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (storage[i] == '\n')
		tmp = my_calloc((i + 2), sizeof(char));
	else
		tmp = my_calloc((i + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	j = -1;
	while (++j <= i)
		tmp[j] = storage[j];
	return (tmp);
}

char	*delete_first_line(char *storage)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i] || !storage[i + 1])
		return (true_free(&storage));
	tmp = my_calloc((my_strlen(storage) - i), sizeof(char));
	if (tmp == NULL)
		return (true_free(&storage));
	j = 0;
	while (storage[++i])
		tmp[j++] = storage[i];
	true_free(&storage);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*storage[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (true_free(&storage[fd]));
	if (!storage[fd] || (storage[fd] && !my_strchr(storage[fd], '\n')))
		storage[fd] = read_line(fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = first_line(storage[fd]);
	if (!line)
		return (true_free(&storage[fd]));
	storage[fd] = delete_first_line(storage[fd]);
	return (line);
}

/*
int main(int args, char **argv)
{
	int fd;
	char *line;
	int i = 1;
	while (fd = open(argv[i],O_RDONLY))
	{
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			line =  get_next_line(fd);
		}
		i++;
	}
	return 0;
}
*/
