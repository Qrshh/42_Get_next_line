/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesneux <abesneux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:46:33 by abesneux          #+#    #+#             */
/*   Updated: 2023/11/24 19:44:38 by abesneux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[1025][BUFFER_SIZE + 1];
	char		*dest;
	int			i;

	i = 1;
	dest = NULL;
	if (BUFFER_SIZE == 0 || fd < 0)
		return (0);
	if (ft_check(buff[fd]) == 1)
	{
		ft_buf_cut(buff[fd]);
		dest = ft_join(dest, buff[fd]);
	}
	while (i > 0 && ft_check(buff[fd]) == 0)
	{
		i = read(fd, buff[fd], BUFFER_SIZE);
		if (i < 0)
		{
			free(dest);
			return (NULL);
		}
		buff[fd][i] = '\0';
		dest = ft_join(dest, buff[fd]);
	}
	return (dest);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	i;

	i = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	// if(test)
	// {
	// 	printf("%s", test);
	// 	free(test);
	// }
	return (0);
}
*/