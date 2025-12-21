# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 15:45:58 by mdamouh           #+#    #+#              #
#    Updated: 2025/12/21 16:00:25 by mdamouh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c push_swap_utils.c push_swap_utils_b.c
PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

all: $(NAME)

$(PRINTF):
	make -C ./ft_printf
$(LIBFT):
	make bonus -C ./libft
$(NAME): $(SRCS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) $(LIBFT) -o $(NAME)

clean:
	make clean -C ft_printf
	make clean -C libft

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm push_swap

re: fclean all

.PHONY: all clean fclean re