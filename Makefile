# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 15:45:58 by mdamouh           #+#    #+#              #
#    Updated: 2026/01/01 10:00:40 by mdamouh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = push_swap.c push_swap_utils_a.c push_swap_utils_b.c parsing.c indexing.c chunking.c push_swap_utils.c small_sort.c
PRINTF = ./ft_printf/libftprintf.a
LIBFT = ./libft/libft.a
BONUSSRC = checker.c bonus_operations.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
			push_swap_utils_a.c push_swap_utils_b.c parsing.c indexing.c chunking.c push_swap_utils.c small_sort.c
BONUS = checker

all: $(NAME)

$(PRINTF):
	make -C ./ft_printf
$(LIBFT):
	make bonus -C ./libft
$(NAME): $(SRCS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(PRINTF) $(LIBFT) -o $(NAME)

bonus:	$(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUSSRC) $(PRINTF) $(LIBFT) -o $(BONUS)

clean:
	make clean -C ft_printf
	make clean -C libft

fclean:
	make fclean -C ft_printf
	make fclean -C libft
	rm -f push_swap
	rm -f checker

re: fclean all

.PHONY: all clean fclean re
