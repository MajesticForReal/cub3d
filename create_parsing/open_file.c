/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:55:29 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/29 19:22:00 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_open_file(char **argv, t_data *x)
{
	char	*str;

	x->file = open(argv[1], O_DIRECTORY);
	if (x->file > 2)
		return (close(x->file), ft_putstr_fd("Error : Is a folder\n", 2), 1);
	str = argv[1];
	if (!(ft_strnstr(&str[ft_strlen(argv[1]) - 4], ".cub", 4)))
		return (ft_putstr_fd("Error : Invalid extension map\n", 2), 1);
	if (ft_strcmp(str, ".cub") == 0)
		return (ft_putstr_fd("Error : Invalid infile\n", 2), 1);
	x->file = open(argv[1], O_RDONLY);
	if (x->file == -1)
		return (ft_putstr_fd("Error : Invalid file\n", 2), 1);
	return (0);
}

int	ft_map_split(char *join, t_data *x)
{
	char	**map;
	int		i;

	map = ft_split(join, '\n', x);
	i = 0;
	if (ft_check_all(map, x) == 1)
	{
		ft_free_args(map);
		free(join);
		exit(0);
	}
	if (ft_tab_coord(map, x) == 1)
	{
		ft_free_args(map);
		free(join);
		exit(0);
	}
	if (ft_fill_new_map(map, x) == 1)
		return (ft_free_pars(x, join), 1);
	ft_free_args(map);
	if (ft_map_split_bis(x, join) == 1)
		return (1);
	return (0);
}

int	ft_map_split_bis(t_data *x, char *join)
{
	if (ft_parse_map_letter1(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_parse_map_letter2(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_parse_map_letter3(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_parse_start_position(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_map_split_ter(x, join) == 1)
		return (1);
	return (0);
}

int	ft_map_split_ter(t_data *x, char *join)
{
	if (ft_parse_map_first_lines(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_parse_map_last_lines(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_parse_map_line(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_parse_map_first_case(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	if (ft_parse_map_last_case(x->map, x) == 1)
		return (ft_free_pars(x, join), 1);
	return (0);
}

int	ft_open_map(char **argv, t_data *x)
{
	char	*str;
	char	*join;

	x->max = 0;
	if (ft_open_file(argv, x) == 1)
		return (1);
	str = get_next_line(x->file, 0);
	if (!str)
		return (ft_empty_map(x));
	x->len = ft_strlen(str);
	join = NULL;
	join = ft_open_map2(x, str, join);
	get_next_line(x->file, 1);
	if (ft_map_split(join, x) == 1)
		return (1);
	free(join);
	return (0);
}
