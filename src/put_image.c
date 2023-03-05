/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:54:55 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/03/01 12:09:06 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_images	ft_putimage(char *name, char *src, int width, int height)
// {
// 	t_images img;
// 	img.img = name;
// 	img.src = src;
// 	img.img_width = width;
// 	img.img_height = height;
// 	// img.img = mlx_xpm_file_to_image(mlx, src, &img.img_width, &img.img_height);
// 	// mlx_put_image_to_window(mlx, mlx_win, img.img, j * 50, i * 50);
// 	return (img);
// }

void	ft_putimage(void *mlx, void *mlx_win, char *src, int i, int j)
{
	i = 1 + i;
	j = 1 + j;
	printf("build success\n");
	t_data img;
	img.img = mlx_xpm_file_to_image(mlx, src, &img.img_width, &img.img_height);
	printf("seg foalt\n");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 1 * 50, 1 * 50);
	printf("done\n");
}


void	check_images(void *mlx, void *mlx_win, char *line , int i, int j)
{
	// t_data wall;
	if (line[j] == '1')
	{
		// wall.img = mlx_xpm_file_to_image(mlx, "./textures/wall.xpm", 50, 50);
		// mlx_put_image_to_window(mlx, mlx_win, wall.img, i, j);
		printf("done\n");
		ft_putimage(mlx, mlx_win, "../../textures/wall.xpm", i, j);
	}
	else if (line[j] == '0')
		ft_putimage(mlx, mlx_win, "./../textures/grasss.xpm", i, j);
	else if (line[j] == 'C')
	{
		ft_putimage(mlx, mlx_win, "./../textures/grasss.xpm", i, j);
		ft_putimage(mlx, mlx_win, "./../textures/newCoin.xpm", i, j);
	}
	else if (line[j] == 'E')
	{	
		ft_putimage(mlx, mlx_win, "./../textures/grasss.xpm", i, j);
		ft_putimage(mlx, mlx_win, "./../textures/box.xpm", i, j);
	}
	else if (line[j] == 'P')
	{
		ft_putimage(mlx, mlx_win, "./../textures/grasss.xpm", i, j);
		ft_putimage(mlx, mlx_win, "./../textures/man.xpm", i, j);
	}
	else
		ft_putimage(mlx, mlx_win, "./../textures/wall.xpm", i, j);
}

void	putimage_on_window(void *mlx, void *mlx_win, char *file)
{
	int	fd;
	char	*line;
	int	i;
	t_data img;
	//int	j;
	
	i = -1;
	fd = open(file, O_RDONLY);
	while (1 && i > 3)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if (!line)
		{
			free(line);
			break;
		}
		i++;
		//j = -1; 
	img.img = mlx_xpm_file_to_image(mlx, "./textures/man.xpm", &img.img_width, &img.img_height);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 100 , 100);
		//while(line[++j])
		//	check_images(mlx, mlx_win, line, i, j);
		printf("build success\n");
		free(line);
	}
}
