/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_path_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:45:41 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/28 19:12:08 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_calculate_length(char **map, int f, int count, int nb)
{
	while (map[nb][f] != ' ')
	{
		f++;
		count++;
	}
	return (count);
}

int	ft_fill_path_north(char **map, t_data *x)
{
	int	o;
	int	f;
	int	count;

	o = 0;
	f = 0;
	count = 0;
	while (map[0][f] != '.')
		f++;
	count = ft_calculate_length(map, f, count, 0);
	x->north = malloc(sizeof(char) * (count + 1));
	if (!x->north)
		return (0);
	count = 0;
	f = 0;
	while (map[0][f] != '.')
		f++;
	while (map[0][f] != ' ')
	{
		x->north[count] = map[0][f];
		count++;
		f++;
	}
	x->north[count] = '\0';
	return (0);
}

int	ft_fill_path_south(char **map, t_data *x)
{
	int	o;
	int	f;
	int	count;

	o = 0;
	f = 0;
	count = 0;
	while (map[1][f] != '.')
		f++;
	count = ft_calculate_length(map, f, count, 1);
	x->south = malloc(sizeof(char) * (count + 1));
	if (!x->south)
		return (0);
	count = 0;
	f = 0;
	while (map[1][f] != '.')
		f++;
	while (map[1][f] != ' ')
	{
		x->south[count] = map[1][f];
		count++;
		f++;
	}
	x->south[count] = '\0';
	return (0);
}

int	ft_fill_path_west(char **map, t_data *x)
{
	int	o;
	int	f;
	int	count;

	o = 0;
	f = 0;
	count = 0;
	while (map[2][f] != '.')
		f++;
	count = ft_calculate_length(map, f, count, 2);
	x->west = malloc(sizeof(char) * (count + 1));
	if (!x->west)
		return (0);
	count = 0;
	f = 0;
	while (map[2][f] != '.')
		f++;
	while (map[2][f] != ' ')
	{
		x->west[count] = map[2][f];
		count++;
		f++;
	}
	x->west[count] = '\0';
	return (0);
}

int	ft_fill_path_east(char **map, t_data *x)
{
	int	o;
	int	f;
	int	count;

	o = 0;
	f = 0;
	count = 0;
	while (map[3][f] != '.')
		f++;
	count = ft_calculate_length(map, f, count, 3);
	x->east = malloc(sizeof(char) * (count + 1));
	if (!x->east)
		return (0);
	count = 0;
	f = 0;
	while (map[3][f] != '.')
		f++;
	while (map[3][f] != ' ')
	{
		x->east[count] = map[3][f];
		count++;
		f++;
	}
	x->east[count] = '\0';
	return (0);
}
