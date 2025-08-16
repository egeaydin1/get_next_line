#include "get_next_line.h"
static char *get_row(int fd,char *buffer)
{
	int redbyte = 0;
	char *result;
	char *temp;
	result = ft_strdup("");
	if (ft_strchr(buffer,'\n'))
		return(buffer);	
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
	return (result);
}
char *reload_row(const char *previus_row)
{
	char	*temp;
	char	*reload;
	int		i;

	i = 0;
	temp = ft_strchr(previus_row,'\n') + 1;
	if (!temp)
		temp = (char *)previus_row;
	reload = (char *)malloc(sizeof(char) * ft_strlen(temp));
	if (!reload)
		return(NULL);
	while (temp[i])
	{
		reload[i] = temp[i];
		i++;
	}
	reload[i] = '\0';
	return(reload);
}
char *get_next_line(int fd)
{
    static char *buffer;
	char *line;
	char *temp;
	printf("'%s'\n",buffer);
	if (!buffer)
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	temp = get_row(fd,buffer);
	line = ft_substr(temp,0,ft_strchr(temp,'\n')-temp);
	buffer = reload_row(temp);
	printf("'%s'\n",buffer);
	return (line);
}

