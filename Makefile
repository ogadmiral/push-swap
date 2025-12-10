# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 15:45:58 by mdamouh           #+#    #+#              #
#    Updated: 2025/12/10 16:14:07 by mdamouh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c 
PRINTF = ./ft_printf/libftprintf.a

all: $(PRINTF) $(NAME) 

$(PRINTF):
	@make -s -C ./ft_printf

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) -o $(NAME)

clean:
	@make -s clean -C ft_printf

fclean:
	@make -s fclean -C ft_printf
	rm push_swap

re: fclean all

.PHONY: all clean fclean re