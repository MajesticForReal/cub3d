/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:52:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/29 19:21:16 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_virgule(char **map)
{
	int	i;
	int	f;
	int	count;

	i = 3;
	while (++i < 6 && map[i])
	{
		f = 0;
		count = 0;
		while (i < 6 && map[i][f])
		{
			while (i < 6 && map[i][f] && !(map[i][f] >= 48 && map[i][f] <= 57))
				f++;
			while (i < 6 && map[i][f] && (map[i][f] >= 48 && map[i][f] <= 57))
				f++;
			count++;
			if (f < 14 && count > 2 && (map[i][f] > 33 || map[i][f] < 30))
				return (ft_putstr_fd("Error : RGB values are wrong\n", 2), 1);
			if (count < 3 && (map[i][f + 1] <= 48 || map[i][f + 1] >= 57))
				return (ft_putstr_fd("Error : RGB values are wrong\n", 2), 1);
			if (count < 3 && map[i][f] != ',')
				return (ft_putstr_fd("Error : RGB values are wrong\n", 2), 1);
		}
	}
	return (0);
}

int	ft_parse_map_last_lines(char **map, t_data *x)
{
	int	i;
	int	j;

	(void)map;
	i = 0;
	j = 0;
	while (map[i])
		i++;
	while (x->map[i - 1][j])
	{
		if (!(x->map[i - 1][j] == ' ' || x->map[i - 1][j] == '1'))
			return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
		j++;
	}
	return (0);
}

int	ft_parse_map_first_lines(char **map, t_data *x)
{
	int	i;
	int	j;

	(void)map;
	i = 0;
	j = 0;
	while (x->map[0][j])
	{
		if (!(x->map[0][j] == ' ' || x->map[0][j] == '1'))
			return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
		j++;
	}
	return (0);
}

int	ft_parse_map_line(char **map, t_data *x)
{
	int	i;
	int	j;

	i = 0;
	(void)x;
	while (map && map[i])
	{
		j = 0;
		while (map && map[i] && map[i][j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E' )
				&& (map[i - 1][j] == ' ' || map[i + 1][j] == ' '))
				return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_all(char **map, t_data *x)
{
	int	i;

	(void)x;
	i = 0;
	while (map[i])
		i++;
	if (i < 9)
		return (ft_putstr_fd("Error : Map is too short\n", 2), 1);
	return (0);
}
