# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 15:45:58 by mdamouh           #+#    #+#              #
#    Updated: 2026/01/08 11:54:30 by mdamouh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CHECKER     = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror

PRINTF      = ./ft_printf/libftprintf.a
LIBFT       = ./libft/libft.a

SRCS        = push_swap.c push_swap_utils_a.c push_swap_utils_b.c get_next_line/get_next_line_utils.c\
              parsing.c indexing.c chunking.c push_swap_utils.c small_sort.c parsing_utils.c
OBJS        = $(SRCS:.c=.o)

BONUSSRC    = checker_bonus.c bonus_part/operations_bonus.c \
              bonus_part/operationsa_bonus.c bonus_part/operationsb_bonus.c \
              get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
              parsing.c indexing.c push_swap_utils.c push_swap_utils_b.c parsing_utils.c
BOBJS       = $(BONUSSRC:.c=.o)

all: $(NAME)

$(PRINTF):
	make -C ft_printf

$(LIBFT):
	make bonus -C libft

$(NAME): $(OBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) $(LIBFT) -o $(NAME)

bonus: $(CHECKER)

$(CHECKER): $(BOBJS) $(PRINTF) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJS) $(PRINTF) $(LIBFT) -o $(CHECKER)

clean:
	rm -f $(OBJS) $(BOBJS)
	make clean -C ft_printf
	make clean -C libft

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make fclean -C libft
	make fclean -C ft_printf

re: fclean all

.PHONY: all bonus clean fclean re
