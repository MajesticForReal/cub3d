
#include "cub3d.h"

int	ft_parse_map_first_case(char **map, t_data *x)
{
	int	i;

	i = 0;
	(void)x;
	while (map[i])
	{
		if (!(map[i][0] == 'A' || map[i][0] == 'B' || map[i][0] == '1'))
			return (ft_putstr_fd("Error : No wall beg map first case\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_parse_map_last_case(char **map, t_data *x)
{
	int	i;

	i = 0;
	(void)x;
	while (map[i])
	{
		if (!(map[i][x->len - 2] == 'A' || map[i][x->len - 2] == 'B' || map[i][x->len - 2] == '1'))
			return (ft_putstr_fd("Error : No wall beg map last case\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_parse_map_letter1(char **map, t_data *x)
{
	int i;
	int j;
	(void)x;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == 'A' || map[i][j] == '1'
				|| map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'
				|| map[i][j] == '0' || map[i][j] == 'B'))
			{
				dprintf(2, "i => %s\n", map[i]);
				dprintf(2, "j ---> %c\n", map[i][j]);
				ft_putstr_fd("Error : Stranger element in map\n", 2);
				return (1);
			}
			if ((map[i][j] == 'A' && map[i][j + 1] == '0')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'N')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'S')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'W')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'E')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'B'))
			{
				dprintf(2, "i => %s\n", map[i]);
				dprintf(2, "j ---> %c\n", map[i][j]);
				ft_putstr_fd("Error : No wall in begginning map\n", 2);
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
	int i;
	int j;
	(void)x;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'N' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'S' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'W' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'E' && map[i][j + 1] == 'B')
				|| (map[i][j] == 'A' && map[i][j + 1] == 'B'))
			{
				dprintf(2, "i => %s\n", map[i]);
				dprintf(2, "j ---> %c\n", map[i][j]);
				ft_putstr_fd("Error : No wall in ending map\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}