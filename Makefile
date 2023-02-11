# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 14:52:30 by jecolmou          #+#    #+#              #
#    Updated: 2022/12/28 16:41:05 by jecolmou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					=	cub3d

SRCS					=		main.c \
							utils/ft_strnstr.c \
							utils/ft_strcmp.c \
							utils/ft_bzero.c \
							utils/ft_split.c \
							utils/ft_putstr_fd.c \
							utils/ft_strlen.c \
							utils/ft_strjoin.c \
							utils/ft_atoi.c \
							utils/ft_calloc.c \
							free.c \
							create_parsing/parsing.c \
							create_parsing/parsing_coord.c \
							create_parsing/open_file.c \
							create_parsing/fill_path_map.c \
							create_parsing/get_next_line.c \
							create_parsing/get_next_line_utils.c \
							control_parsing/parsing_lines.c \
							control_parsing/parsing_cases.c \
							control_parsing/parsing_letters.c \
							img.c \
							init.c \
							texture.c \
							window.c \
							movement.c \

OBJS 		= ${SRCS:.c=.o}

CC 			= clang
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f
NAME		= cub3d
FLAGS		= -lXext -lX11 -lm ./mlx/libmlx.a ./mlx/libmlx_Linux.a

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	./mlx/libmlx.a  $(OBJS)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

./mlx/libmlx.a :
	make -s -C ./mlx

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all
