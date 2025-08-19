/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:18:08 by egeaydin          #+#    #+#             */
/*   Updated: 2025/08/19 19:38:26 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*control(char *read_buffer, char *buffer)
{
	char	*result;

	if (!read_buffer)
		return (NULL);
	if (!buffer)
		result = ft_strdup("");
	else
		result = ft_strdup(buffer);
	return (result);
}

static char	*get_row(int fd, char *buffer)
{
	int		redbyte;
	char	*result;
	char	*temp;
	char	*read_buffer;

	read_buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	result = control(read_buffer, buffer);
	if (result == NULL)
		return (NULL);
	redbyte = read(fd, read_buffer, BUFFER_SIZE);
	while (redbyte > 0)
	{
		temp = result;
		read_buffer[redbyte] = '\0';
		result = ft_strjoin(result, read_buffer);
		free(temp);
		if (ft_strchr(read_buffer, '\n'))
			break ;
		redbyte = read(fd, read_buffer, BUFFER_SIZE);
	}
	free(read_buffer);
	if (redbyte == -1)
		return (free(result), NULL);
	return (result);
}

static char	*seperate_row(char *row)
{
	size_t	i;
	size_t	j;
	char	*sep_row;

	if (!row || !*row)
		return (NULL);
	i = 0;
	j = 0;
	while (row[i] && row[i] != '\n')
		i++;
	if (row[i] == '\n')
		i++;
	sep_row = ft_calloc(sizeof(char), i + 1);
	if (!sep_row)
		return (NULL);
	while (j < i)
	{
		sep_row[j] = row[j];
		j++;
	}
	return (sep_row);
}

static char	*reload_row(char *previus_row)
{
	size_t	i;
	char	*result;

	if (!previus_row || !*previus_row)
		return (NULL);
	i = 0;
	while (previus_row[i] != '\n' && previus_row[i])
		i++;
	if (!previus_row[i])
		return (NULL);
	i++;
	result = ft_strdup(&previus_row[i]);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*temp[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp[fd] = get_row(fd, buffer[fd]);
	if (!temp[fd])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	line = seperate_row(temp[fd]);
	free(buffer[fd]);
	buffer[fd] = reload_row(temp[fd]);
	free(temp[fd]);
	return (line);
}
