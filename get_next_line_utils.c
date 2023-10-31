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

int	ft_strlen(const char *str)
{
	int	res;

	res = 0;
	if (str == NULL)
		return (0);
	while (str[res] != '\0')
	{
		res++;
	}
	return (res);
}

char	*add_buffer(char *str, char *buffer, int n)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((ft_strlen(str) + n + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (str != NULL && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	j = 0;
	while (j < n)
		res[i++] = buffer[j++];
	res[i] = '\0';
	if (i == 0)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*get_buffer(int fd, char *str)
{
	int		n;
	char	buffer[BUFFER_SIZE];
	char	*res;

	res = NULL;
	n = read(fd, buffer, BUFFER_SIZE);
	if (n >= 0)
	{
		res = add_buffer(str, buffer, n);
		free(str);
	}
	if ((n < 0) || (res == NULL) || (*res == '\0' && n == 0))
	{
		if (n == -1)
			free(str);
		return (0);
	}
	return (res);
}

char	*save_tale(char *str, int n)
{
	char	*res;
	int		i;
	int		j;

	i = n;
	j = 0;
	res = malloc((ft_strlen(str) - n + 1) * sizeof(char));
	if (res == NULL)
	{
		free(str);
		return (0);
	}
	while (i < ft_strlen(str))
		res[j++] = str[i++];
	res[j] = '\0';
	free(str);
	if (j == 0)
	{
		free(res);
		res = NULL;
	}
	return (res);
}

char	*make_line(char *str, int n)
{
	char	*res;
	int		i;

	res = malloc((n + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	if (i == 0)
	{
		free (res);
		res = NULL;
	}
	return (res);
}
