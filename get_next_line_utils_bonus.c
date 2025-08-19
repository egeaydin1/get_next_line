/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 17:56:16 by egeaydin          #+#    #+#             */
/*   Updated: 2025/08/19 19:37:38 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	bytes;
	size_t	i;

	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (bytes > 0)
	{
		ptr[i] = '\0';
		i++;
		bytes--;
	}
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*strptr;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	strptr = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (!strptr)
		return (NULL);
	while (s[i])
	{
		strptr[i] = s[i];
		i++;
	}
	strptr[i] = '\0';
	return (strptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	int		i;
	char	x;

	a = (char *)s;
	i = 0;
	x = (char)c;
	while (a[i])
	{
		if (a[i] == x)
			return ((&a[i]));
		i++;
	}
	if (x == 0)
	{
		return (&a[i]);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	s1size;

	ptr = NULL;
	if (!s1)
		return ((char *)s1);
	if (!s2)
		return ((char *)s2);
	i = -1;
	j = -1;
	s1size = ft_strlen(s1);
	ptr = ft_calloc(sizeof(char), (s1size + (ft_strlen(s2) + 1)));
	if (!ptr)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[++j])
	{
		ptr[i] = s2[j];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
