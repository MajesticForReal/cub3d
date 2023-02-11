/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:12 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/28 16:39:48 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	close_all(t_data *data)
{
	int	i;

	ft_free_image(data, 4);
	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
	free(data->imgdata);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == 100)
		data->right = 1;
	else if (keycode == 97)
		data->left = 1;
	else if (keycode == 119)
		data->front = 1;
	else if (keycode == 115)
		data->back = 1;
	else if (keycode == 65361)
		data->rotate_left = 1;
	else if (keycode == 65363)
		data->rotate_right = 1;
	else if (keycode == 65307)
		ft_free(data, 4);
	return (1);
}

int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == 100)
		data->right = 0;
	else if (keycode == 97)
		data->left = 0;
	else if (keycode == 119)
		data->front = 0;
	else if (keycode == 115)
		data->back = 0;
	else if (keycode == 65361)
		data->rotate_left = 0;
	else if (keycode == 65363)
		data->rotate_right = 0;
	else if (keycode == 65307)
		ft_free(data, 4);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	x;

	ft_bzero(&x, sizeof(x));
	x.file = 0;
	if (ft_check_argv(argc, argv) == 1)
		return (1);
	if (ft_open_map(argv, &x) == 1)
		return (1);
	if (ft_position_psx_psy(x.map, &x) == 1)
		return (1);
	x.map[x.psx][x.psy] = '0';
	new_window(&x);
	init_game(&x);
	mlx_hook(x.mlx_win, 2, 1L << 0, ft_key_press, &x);
	mlx_loop_hook(x.mlx_ptr, draw, &x);
	mlx_hook(x.mlx_win, 3, 1L << 1, ft_key_release, &x);
	mlx_hook(x.mlx_win, 17, 0, close_all, &x);
	mlx_loop(x.mlx_ptr);
	return (0);
}
