# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 11:42:28 by ayakoubi          #+#    #+#              #
#    Updated: 2023/02/20 14:46:53 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
SRC			=	so_long.c ft_window.c put_image.c map.c even.c \
				get_next_line.c
OBJDIR		=	obj
_OBJ		=	$(SRC:.c=.o)
OBJ			=	$(patsubst %,$(OBJDIR)/%,$(_OBJ))
M_LIBFT		=	make -C libft
M_PRINTF	=	make -C ft_printf
AR_LIBFT	=	libft/libft.a
AR_PRINTF	=	ft_printf/libftprintf.a
CFLAGS  	=	-Wall -Wextra -Werror
MLX			=	-lmlx -framework OpenGL -framework AppKit

#########################
#		font text		#
#########################

GREEN	= \033[0;32m
RED 	= \033[0;31m
C_END	= \033[0m
BOLD	= \x1b[1m
B_END	= \x1b[0m

all: $(NAME)

$(OBJDIR)/%.o:%.c
	@echo "Compiling >>>>>> $^"
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	:	$(OBJ)
	@$(M_LIBFT)
	@echo "$(GREEN)$(BOLD)Creating >>>>>> $(AR_LIBFT)$(B_END)$(C_END)"
	@$(M_PRINTF)
	@echo "$(GREEN)$(BOLD)Creating >>>>>> $(AR_PRINTF)$(B_END)$(C_END)"
	@$(CC) $(CFLAGS) $^ $(AR_LIBFT) $(AR_PRINTF) $(MLX) -o $@
	@echo "	 $(GREEN) $(BOLD) <<<<<< Done successful! >>>>>>$(B_END) $(C_END)"

clean	:
	@echo "	$(RED)$(BOLD)REMOVED OBJECTS$(B_END)$(C_END)"
	@$(M_LIBFT) clean
	@$(M_PRINTF) clean
	@rm -rf $(OBJDIR)

fclean	:	clean
	@rm -rf $(NAME)
	@$(M_LIBFT) fclean
	@$(M_PRINTF) fclean
	@echo "$(RED)$(BOLD)removed $(AR_LIBFT)\nremoved $(AR_PRINTF)\nremoved $(NAME)$(B_END)$(C_END)"

re:	fclean all

.PHONY: all clean fclean re

