/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:18:08 by egeaydin          #+#    #+#             */
/*   Updated: 2025/08/18 20:56:18 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char *get_row(int fd,char *buffer)
{
	int redbyte = 0;
	char *result;
	char *temp;
	
	result = ft_strdup(buffer);
/* 	if (ft_strchr(buffer,'\n'))
		return(result); */
	redbyte = read(fd,buffer,BUFFER_SIZE);
	while (redbyte > 0)
	{
		temp = result;
		result = ft_strjoin(result,buffer);
		free(temp);
		if (ft_strchr(buffer,'\n'))
			break;
		redbyte = read(fd,buffer,BUFFER_SIZE);
	}
    if (redbyte == -1)
        return(NULL);
    else
        return(result);
}

char *seperate_row(char*row)
{	
	int i;
	char *sep_row;

	if (!row)
		return(NULL);	
	i = 0;
	while (row[i] && row[i] != '\n')
		i++;
	sep_row = ft_substr(row,0,i);
    return (sep_row);
}

char *reload_row(char *previus_row)
{
	int		i;
	char	*result;

	if (!previus_row)
		return(NULL);	
	i = 0;
	while (previus_row[i] != '\n' && previus_row[i])
		i++;	
	if (!previus_row[i])
		return (NULL);
	i++;
	result = ft_strdup(&previus_row[i]);
	free(previus_row);
	return(result);
}
char *get_next_line(int fd)
{
    static char *buffer;
	char *line;
	char *temp;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return(NULL);
	if (!buffer)
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	temp = get_row(fd,buffer);
	line = seperate_row(temp);
	free(temp);
	temp = NULL;
	free(buffer);
	buffer = reload_row(temp);
	return (line);
}

