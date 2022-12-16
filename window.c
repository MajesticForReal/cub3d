#include "cub3d.h"

void	ft_free_image(t_data *data, int j)
{
	int	i;

	i = -1;
	while (++i < j)
		mlx_destroy_image(data->mlx_ptr, data->print[i].image);
	mlx_destroy_image(data->mlx_ptr, data->img);
}

int	ft_free(t_data *data, int j)
{
	if (j == 4)
		ft_free_image(data, j);
	//FREE ALL MAP, MAP PATH, TMP SI IL Y A, DATA, PATH, IMGDATA strcut img data dans data
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

char	*img_path(t_data *data, int i)
{
	if (i == 0)
		return (data->north_path);
	else if (i == 1)
		return (data->south_path);
	else if (i == 2)
		return (data->east_path);
	else if (i == 3)
		return (data->west_path);
	return ("");
}

void	get_img(t_data *data)
{
	t_imgdata	*img;
	int	i;

	i = 0;
	img = malloc(sizeof(t_imgdata) * 4);
	while (i < 4)
	{
		img[i].image = mlx_xpm_file_to_image(data->mlx_ptr,
				img_path(data, i), &img[i].img_width, &img[i].img_height);
		if (img[i].image == NULL)
		{
			data->imgdata = img;
			write(2, "error\n", 6);
			while (--i >= 0)
				mlx_destroy_image(data->mlx_ptr, data->print[i].image);
			ft_free(data, i);
			exit(0);
		}
		img[i].addr = (int *)mlx_get_data_addr(img[i].image, &img[i].bpp,
				&img[i].size_line, &img[i].endian);
		i++;
	}
	data->imgdata = img;
	data->texture_width = img[0].img_width;
	data->texture_height = img[0].img_height;
}

void	new_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		//FREE MAP ET MAP PATH EN CAS D'ECHEC
		//EXIT
	}
	data->mlx_win = mlx_new_window(data->mlx_ptr,
			WIDTHSCREEN, HEIGHTSCREEN, "cub3D");
	if (data->mlx_win == NULL)
	{
		//FREE MAP ET MAP PATH EN CAS D'ECHEC
		//EXIT
	}
	get_img(data);
}