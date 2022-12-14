
#include "cub3d.h"

int	ft_parse_map_fl_lines(char **map, t_data *x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)x;
	while (map[0][j])
	{
		if (!(map[0][j] == 'A' || map[0][j] == 'B' || map[0][j] == '1'))
			return (ft_putstr_fd("Error : No wall around the map first l\n", 2), 1);
		j++;
	}
	j = 0;
	while (map[x->max - 1][j])
	{
		if (!(map[x->max - 1][j] == 'A' || map[x->max - 1][j] == 'B' || map[x->max - 1][j] == '1'))
			return (ft_putstr_fd("Error : No wall around the map last l\n", 2), 1);
		j++;
	}
	return (0);
}

int	ft_parse_map_line1(char **map, t_data *x)
{
	int i;
	int j;
	int count1;
	int count2;
	(void)x;

	i = 0;
	count2 = 0;
	while (map[i])
	{
		j = 0;
		count1 = 0;
		while (map[i][j] == 'A')
		{
			count1++;
			j++;
		}
		count2 = count1;
		i++;
		j = 0;
		while (count2 - 1 >= 0 && map[i][j])
		{
			if (!((map[i][j] == '1') || (map[i][j] == 'A')))
			{
				dprintf(2, "(SENS 1) Error : no wall in beginning line\n");
				return (1);
			}
			j++;
			count2--;
		}
	}
	return (0);
}

int	ft_parse_map_line2(char **map, t_data *x)
{
	int i;
	int j;
	(void)x;
	int count;
	int len;
	int diff;
	
	len = 0;
	diff = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		count = 0;
		len = ft_strlen(map[i]);
		//dprintf(2, "map : %s\n", map[i]);
		while(map[i][j])
		{
			if (map[i][j] == 'B')
				count++;
			j++;
		}
		diff = len - count;
		i++;
		while (map[i] && i && map[i][diff])
		{
			if (!(map[i][diff] == 'B' || map[i][diff] == '1'))
			{
				dprintf(2, "probleme ?\n");
				return (1);
			}
			diff++;
		}
	}
	return (0);
}