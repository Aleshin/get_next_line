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

int	find_nl(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\0')
		{
			str = get_buffer(fd, str);
			if (str == 0)
				return (-1);
			else if ((int)ft_strlen(str) == i)
				break ;
			i--;
			printf("strlen = %zu, i = %d, str = %s\n", ft_strlen(str), i, str);
		}
//		printf("%d, ", i);
		i++;
	}
//	printf("+++++++++++++++++++++  i = %d, line = %s\n", i, str);
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			i;

	if (str == 0)
		str = get_buffer(fd, str);
	if (str == 0)
		return (0);
	i = find_nl(fd, str);
	if (i == -1)
		return (0);
	line = make_line(str, (size_t)i + 1);
	str = save_tale(str, (size_t)i + 1);
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
	line = NULL;
	line = get_next_line(fd);
	printf("next line: %s", line);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("next line: %s", line);
	}
	return (0);
}
