# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeannecolmou <jeannecolmou@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:52:30 by jecolmou          #+#    #+#              #
#    Updated: 2022/12/08 19:21:26 by jeannecolmo      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	cub3d

SRC					=		cub3d.c \
							utils/ft_strnstr.c \
							utils/ft_strcmp.c \
							utils/ft_bzero.c \
							utils/ft_split.c \
							utils/ft_putstr_fd.c \
							utils/ft_strlen.c \
							utils/ft_strjoin.c \
							get_next_line/get_next_line.c \
							get_next_line/get_next_line_utils.c \
							free.c \
							parsing.c \
							parsing_lines.c \
							parsing_cases.c \
							open_file.c \

NAME = cub3d

CC = clang

LINK = clang

CFLAGS = -Wall -Wextra -Werror -I. -c -g3

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX)
	$(LINK) $(OBJ) $(LFLAGS) $(OUTPUT_OPTION)

%.o: %.c
	${CC} ${CFLAGS} $< $(OUTPUT_OPTION)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
