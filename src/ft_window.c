/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:05:18 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/01 12:15:47 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_hieght(char *file)
{
	int i;
	int	count;
	char	*buff;
	int		fd;
	
	i = 0;
	count = 0;
	fd = open(file, O_RDONLY);
	while (1) 
	{
		buff = get_next_line(fd);
		if (!buff)
		{
			free(buff);
			break;
		}
		while (buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
			count++;
		free(buff);
	}
	//free(buff);
	return (count);	
}
