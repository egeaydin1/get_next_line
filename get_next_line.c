/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:18:08 by egeaydin          #+#    #+#             */
/*   Updated: 2025/08/18 23:52:54 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
static char *get_row(int fd,char *buffer)
{
	int redbyte = 0;
	char *result;
	char *temp;
	
	result = ft_strdup(buffer);
	redbyte = read(fd,buffer,BUFFER_SIZE);
	while (redbyte > 0)
	{
		temp = result;
		buffer[redbyte] = '\0';
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

	if (!*row || !row)
		return(NULL);	
	i = 0;
	while (row[i] && row[i] != '\n')
		i++;
	if (i == 0)
		return(ft_strdup("\n"));
	sep_row = ft_substr(row,0,i + 1);
    return (sep_row);
}

char *reload_row(char *previus_row)
{
	int		i;
	char	*result;

	if (!*previus_row || !previus_row)
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
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
			return(NULL);
	}
	temp = get_row(fd,buffer);
	if (!temp)
		return(NULL);
	//printf("temp	:'%s'\n",temp);
	line = seperate_row(temp);
	//printf("line	:'%s'\n",line);
	free(buffer);
	buffer = reload_row(temp);
	if (buffer == NULL)
	{
		free(temp);
		temp = NULL;
		temp = line;
	}
	return (line);
}

