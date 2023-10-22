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
	char		buffer[BUFFER_SIZE];
	static char	*str;
	char		*line;
	size_t		i;

	i = 0;
	line = NULL;
	if (str == NULL)
	{
		if (!read (fd, buffer, BUFFER_SIZE))
			return (NULL);
		str = add_buffer(str, buffer);
	}
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
		{
			if (!read(fd, buffer, BUFFER_SIZE))
				return (NULL);
			str = add_buffer(str, buffer);
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

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error opening file\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("next line: %s", line);
		line = get_next_line(fd);
	}
	return (0);
}
