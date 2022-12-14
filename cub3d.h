/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:49:46 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/14 16:53:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
//# include "mlx/mlx.h"
//# include <X11/keysym.h>
//# include <X11/X.h>

typedef struct s_data		t_data;

typedef struct s_imgdata
{
	void	*image;
	int		*addr;
	int		img_width;
	int		img_height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_imgdata;

struct	s_data
{
	int	file;
	int len;
	int tmp_len;
	int	count;
	int max;
	int		texture_width;
	int		texture_height;
	struct s_imgdata	*imgdata;
}	t_data;

typedef struct s_map		t_map;

struct	s_map
{
	char	*x;
	t_map	*next;
};

///////////////GET_NEXT_LINE/////
int		ft_strlen_gnl(char *str);
int		ft_read_buffer(int fd, char *buf);
int		ft_is_a_line(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*get_next_line(int fd, int reset);
char	*ft_read_text(int fd, char *final);
char	*ft_extract_line(char *s1);
char	*ft_save_line(char *str);

///////////////UTILS/////////////
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(char *s1, char *s2);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c, t_data *x);
void	ft_putstr_fd(char *str, int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);

//////////FREE///////////////////
void	ft_free_args(char **args);

////////////////PARSING///////////
//parsing
int		ft_check_argv(int argc, char **argv);
void	ft_map_space_change(char **map, t_data *x);
int		ft_count_line(char **argv, t_data *x);
//parsing_lines
int		ft_parse_map_fl_lines(char **map, t_data *x);
int		ft_parse_map_line2(char **map, t_data *x);
int		ft_parse_map_line1(char **map, t_data *x);
//parsing_cases.c
int		ft_parse_map_first_case(char **map, t_data *x);
int		ft_parse_map_last_case(char **map, t_data *x);
int		ft_parse_map_letter1(char **map, t_data *x);
int		ft_parse_map_letter2(char **map, t_data *x);
//open file
int		ft_open_file(char **argv, t_data *x);
int		ft_empty_map(t_data *x);
int		ft_open_map(char **argv, t_data *x);

#endif
