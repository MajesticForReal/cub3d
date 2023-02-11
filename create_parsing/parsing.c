/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:55:38 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/29 16:56:47 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_argv(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error : Invalid argument\n", 2);
		return (1);
	}
	if (ft_strlen(argv[1]) == 0)
		return (ft_putstr_fd("Error : Invalid argument\n", 2), 1);
	return (0);
}

int	ft_sizeofnumber(char **map, int o, int f)
{
	int	count;

	count = 0;
	while (map[o][f] >= 48 && map[o][f] <= 57)
	{
		count++;
		f++;
	}
	return (count);
}

int	ft_position_psx_psy(char **map, t_data *x)
{
	int	o;
	int	f;

	o = 0;
	while (map && map[o])
	{
		f = 0;
		while (map && map[o] && map[o][f])
		{
			if (map[o][f] == 'N' || map[o][f] == 'S'
				|| map[o][f] == 'W' || map[o][f] == 'E')
			{
				x->pos = x->map[o][f];
				x->pos_x = o + 0.5;
				x->pos_y = f + 0.5;
				x->psx = o;
				x->psy = f;
				return (0);
			}
			f++;
		}
		o++;
	}
	return (1);
}

int	ft_fill_new_map(char **map, t_data *x)
{
	int	i;
	int	j;
	int	k;

	i = 6;
	j = 0;
	while (map[i])
		i++;
	x->map = malloc(sizeof(char *) * (i + 1));
	if (!x->map)
		return (1);
	i = 5;
	k = -1;
	while (map[++i])
	{
		j = -1;
		x->map[++k] = malloc(sizeof(char) * (x->len + 1));
		if (!x->map[k])
			return (free_split(x->map, k), 1);
		while (map[i][++j])
			x->map[k][j] = map[i][j];
		x->map[k][j] = '\0';
	}
	x->map[++k] = NULL;
	return (0);
}

char	*ft_open_map2(t_data *x, char *str, char *join)
{
	char	*tmp;

	tmp = NULL;
	while (str)
	{
		x->tmp_len = ft_strlen(str);
		if (x->tmp_len > x->len)
			x->len = x->tmp_len;
		x->max++;
		join = ft_strjoin(join, str);
		if (join == NULL)
		{
			free(str);
			get_next_line(x->file, 1);
		}
		free(str);
		str = get_next_line(x->file, 0);
	}
	free(str);
	tmp = join;
	return (tmp);
}
