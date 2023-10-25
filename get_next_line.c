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

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	size_t		i;

	i = 0;
	i = get_buffer(fd, str);
	printf("i = %lu, str: %s\n", i, str);
	if (get_buffer(fd, str) == 0)
		return (0);
//	printf("str: %s\n", str);
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
		{
			if (get_buffer(fd, str) == 0)
				return (0);
		}
		i++;
	}
	line = make_line(str, i + 1);
	str = save_tale(str, i + 1);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
//	char	buffer[BUFFER_SIZE];
	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file\n");
		return (1);
	}
	line = NULL;
//	read(fd, line, BUFFER_SIZE);
	line = get_next_line(fd);
	printf("next line: %s", line);
	/*
	while (line != NULL)
	{
		printf("next line: %s", line);
		line = get_next_line(fd);
	}
	*/
	return (0);
}
