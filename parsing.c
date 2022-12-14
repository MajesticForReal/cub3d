
#include "cub3d.h"

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

void	ft_map_space_change(char **map, t_data *x)
{
	int len;
	int f;
	int o;

	len = 0;
	o = 0;
	while (map[o])
	{
		f = 0;
		len = ft_strlen(map[o]);
		while (map[o][f])
		{
			if (map[o][f] == ' ')
				map[o][f] = 'A';
			// if (map[o][f] == 'A')
			// 	dprintf(2, "+++ : ESPACE\n");
			// else
			// 	dprintf(2, "+++ : %c\n", map[o][f]);
			if ((f + 1 == len) && len < x->len)
			{
				f++;
				while (len < x->len - 1)
				{
					map[o][f] = 'B';
					f++;
					// if (map[o][f] == 'A')
					// 	dprintf(2, "+++ : ESPACE FIN\n");
					len++;
				}
			}
			f++;
		}
		//dprintf(2, "join ==> %s\n", map[o]);
		o++;
	}
}


