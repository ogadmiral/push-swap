# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 15:45:58 by mdamouh           #+#    #+#              #
#    Updated: 2025/12/10 16:58:38 by mdamouh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c 
PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a

all: $(NAME)

$(PRINTF):
	@make -s -C ./ft_printf
$(LIBFT):
	@make -s -C ./libft
$(NAME): $(SRCS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) $(LIBFT) -o $(NAME)

clean:
	@make -s clean -C ft_printf
	@make -s clean -C libft

fclean:
	@make -s fclean -C ft_printf
	@make -s fclean -C libft
	rm push_swap

re: fclean all

.PHONY: all clean fclean re