/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:56:47 by ayakoubi          #+#    #+#             */
/*   Updated: 2023/02/20 14:46:07 by ayakoubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"


typedef struct	s_mlx {
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
}				t_mlx;

typedef struct	s_data {
	char 	*file;
	void	*img;
	char	*src;
	int		img_width;
	int		img_height;	
}				t_data;


/* ========= main functions ========= */


void	putimage_on_window(void *mlx, void *mlx_win, char *file);
void	check_images(void *mlx, void *mlx_win, char *line, int i, int j);


/* ========= handling map functions ========= */



/* ========= windows functions ========= */

int	count_hieght(char *file);


/* ========= utils functions ========= */


/* ========= event functions ========= */



/* ========= images functions ========= */



#endif
