# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdamouh <mdamouh@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 20:51:08 by mdamouh           #+#    #+#              #
#    Updated: 2025/12/23 10:00:51 by mdamouh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_memchr.c ft_memmove.c ft_strchr.c ft_strjoin.c ft_strlen.c ft_strrchr.c \
	  ft_calloc.c ft_memcmp.c ft_memset.c ft_strdup.c ft_strlcat.c ft_strncmp.c ft_strtrim.c \
	  ft_memcpy.c ft_split.c ft_striteri.c ft_strlcpy.c ft_strnstr.c ft_substr.c \

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(BOBJ)
	ar rcs $(NAME) $(OBJ) $(BOBJ)

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all bonus re
