/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_coord.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:11:42 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/29 19:00:20 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_coordinates(char **map, t_data *x)
{
	(void)x;
	if (!(map[0][0] == 'N' && map[0][1] == 'O') || map[0][2] != ' ')
		return (ft_putstr_fd("Error : Coordinates values are wrong\n", 2), 1);
	if (!(map[1][0] == 'S' && map[1][1] == 'O') || map[1][2] != ' ')
		return (ft_putstr_fd("Error : Coordinates values are wrong\n", 2), 1);
	if (!(map[2][0] == 'W' && map[2][1] == 'E') || map[2][2] != ' ')
		return (ft_putstr_fd("Error : Coordinates values are wrong\n", 2), 1);
	if (!(map[3][0] == 'E' && map[3][1] == 'A') || map[3][2] != ' ')
		return (ft_putstr_fd("Error : Coordinates values are wrong\n", 2), 1);
	if (map[4][0] != 'F' || map[4][1] != ' ')
		return (ft_putstr_fd("Error : RGB values are wrong\n", 2), 1);
	if (map[5][0] != 'C' || map[5][1] != ' ')
		return (ft_putstr_fd("Error : RGB values are wrong\n", 2), 1);
	return (0);
}

int	ft_tab_rgb(char **map, t_data *x)
{
	char	*str;

	x->o = 4;
	x->rgb[0] = -1;
	x->rgb[1] = -1;
	x->rgb[2] = -1;
	str = NULL;
	if (ft_check_virgule(map) == 1)
		return (1);
	while (map && map[x->o])
	{
		x->f = 0;
		x->countrgb = 0;
		x->index = 0;
		x->j = 0;
		while ((!(map[x->o][x->f] >= 48 && map[x->o][x->f] <= 57)))
			x->f++;
		x->countrgb = ft_sizeofnumber(map, x->o, x->f);
		x->f = 0;
		map = ft_rgb_map(map, x, str);
		x->o = ft_rgb_color(x->o, x);
		if (x->o == -1)
			return (1);
	}
	return (0);
}

int	ft_rgb_color(int o, t_data *x)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (x->rgb[i] > 255 || x->rgb[i] <= 0)
			return (ft_putstr_fd("Error : RGB values are wrong\n", 2), -1);
		i++;
	}
	if (o == 4)
	{
		x->floor_color = x->rgb[0];
		x->floor_color = (x->floor_color * 256) + x->rgb[1];
		x->floor_color = (x->floor_color * 256) + x->rgb[2];
	}
	else if (o == 5)
	{
		x->ceiling_color = x->rgb[0];
		x->ceiling_color = (x->ceiling_color * 256) + x->rgb[1];
		x->ceiling_color = (x->ceiling_color * 256) + x->rgb[2];
	}
	o++;
	return (o);
}

int	ft_organisation_coord(char **tab_coor, t_data *x)
{
	if (ft_check_coordinates(tab_coor, x) == 1)
		return (1);
	if (ft_tab_rgb(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_north(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_south(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_west(tab_coor, x) == 1)
		return (1);
	if (ft_fill_path_east(tab_coor, x) == 1)
		return (1);
	return (0);
}

int	ft_tab_coord(char **map, t_data *x)
{
	char	**tab_coor;
	int		y;
	int		o;

	(void)x;
	y = 0;
	o = 0;
	tab_coor = ft_calloc(sizeof(char *), (6 + 1));
	while (map[o] && o <= 5)
	{
		tab_coor[y] = map[o];
		y++;
		o++;
	}
	if (ft_organisation_coord(tab_coor, x) == 1)
		return (free(tab_coor), 1);
	free(tab_coor);
	return (0);
}
