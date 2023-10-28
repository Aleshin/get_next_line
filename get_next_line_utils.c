/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saleshin <saleshin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:00:28 by saleshin          #+#    #+#             */
/*   Updated: 2023/08/14 18:34:19 by saleshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	res;

	res = 0;
	if (str == NULL)
		return (0);
	while (str[res] != '\0')
	{
		res++;
	}
	return (res);
}

char	*add_buffer(char *str, char *buffer, size_t n)
{
	char	*res;
	size_t	i;
	size_t	j;	

	res = malloc((ft_strlen(str) + n) * sizeof(char));
	if (res == NULL)
		return (0);
	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			res[i] = str[i];
			i++;
		}
	}
	j = 0;
	while (j < n)
		res[i++] = buffer[j++];
	res[i] = '\0';
	free(str);
	return (res);
}

char	*get_buffer(int fd, char *str)
{
	int		n;
	char	buffer[BUFFER_SIZE];
	char	*res;

	n = read(fd, buffer, BUFFER_SIZE);
	if (n >= 0)
	{
		res = add_buffer(str, buffer, n);
		if ((*res == '\0' && n == 0) || res == 0)
			return (0);
		return (res);
	}
	return (0);
}

char	*save_tale(char *str, size_t n)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = n;
	j = 0;
	res = malloc((ft_strlen(str) - n) * sizeof(char));
	if (res == NULL)
		return (0);
	while (i < ft_strlen(str))
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	return (res);
}

char	*make_line(char *str, size_t n)
{
	char	*res;
	size_t	i;

	res = malloc((n) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
