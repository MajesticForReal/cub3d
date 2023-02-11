/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_letters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 19:00:48 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/28 16:45:14 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse_map_letter1(char **map, t_data *x)
{
	int	i;
	int	j;

	(void)x;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == '1'
				|| map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == '0' || map[i][j] == ' '))
			{
				ft_putstr_fd("Error : Stranger element in map\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse_map_letter2(char **map, t_data *x)
{
	int	i;
	int	j;

	(void)x;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == ' ' && map[i][j + 1] == '0')
				|| (map[i][j] == ' ' && map[i][j + 1] == 'N')
				|| (map[i][j] == ' ' && map[i][j + 1] == 'S')
				|| (map[i][j] == ' ' && map[i][j + 1] == 'W')
				|| (map[i][j] == ' ' && map[i][j + 1] == 'E'))
				return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse_map_letter3(char **map, t_data *x)
{
	int	i;
	int	j;

	(void)x;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' && map[i][j + 1] == ' ')
				|| (map[i][j] == 'N' && map[i][j + 1] == ' ')
				|| (map[i][j] == 'S' && map[i][j + 1] == ' ')
				|| (map[i][j] == 'W' && map[i][j + 1] == ' ')
				|| (map[i][j] == 'E' && map[i][j + 1] == ' '))
				return (ft_putstr_fd("Error : No wall around the map\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}
