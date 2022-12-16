#include "cub3d.h"

void	ft_init_raycast(t_data **data)
{
	if ((*data)->raydiry == 0)
		(*data)->deltadistx = 0;
	else if ((*data)->raydirx == 0)
		(*data)->deltadistx = 1;
	else
		(*data)->deltadistx = sqrt(1 + ((*data)->raydiry
					* (*data)->raydiry) / ((*data)->raydirx
					* (*data)->raydirx));
	if ((*data)->raydirx == 0)
		(*data)->deltadisty = 0;
	else if ((*data)->raydiry == 0)
		(*data)->deltadisty = 1;
	else
		(*data)->deltadisty = sqrt(1 + ((*data)->raydirx
					* (*data)->raydirx) / ((*data)->raydiry
					* (*data)->raydiry));
}

void	init_step_and_sidedist(t_data **data)
{
	if ((*data)->raydirx < 0)
	{
		(*data)->stepx = -1;
		(*data)->sidedistx = ((*data)->rayposx
				- (*data)->mapx) * (*data)->deltadistx;
	}
	else
	{
		(*data)->stepx = 1;
		(*data)->sidedistx = ((*data)->mapx + 1.0
				- (*data)->rayposx) * (*data)->deltadistx;
	}
	if ((*data)->raydiry < 0)
	{
		(*data)->stepy = -1;
		(*data)->sidedisty = ((*data)->rayposy
				- (*data)->mapy) * (*data)->deltadisty;
	}
	else
	{
		(*data)->stepy = 1;
		(*data)->sidedisty = ((*data)->mapy + 1.0
				- (*data)->rayposy) * (*data)->deltadisty;
	}
}

void	find_wall(t_data **data)
{
	touch_wall(data);
	if ((*data)->side == 0)
		(*data)->perpwalldist = ((*data)->mapx - (*data)->rayposx
				+ (1 - (*data)->stepx) / 2) / (*data)->raydirx;
	else
		(*data)->perpwalldist = ((*data)->mapy - (*data)->rayposy
				+ (1 - (*data)->stepy) / 2) / (*data)->raydiry;
	(*data)->lineheight = (int)(HEIGHTSCREEN / (*data)->perpwalldist);
	(*data)->drawstart = -((*data)->lineheight) / 2 + HEIGHTSCREEN / 2;
	if ((*data)->drawstart < 0)
		(*data)->drawstart = 0;
	(*data)->drawend = (*data)->lineheight / 2 + HEIGHTSCREEN / 2;
	if ((*data)->drawend >= HEIGHTSCREEN)
		(*data)->drawend = HEIGHTSCREEN - 1;
}

void	touch_wall(t_data **data)
{
	while ((*data)->hit == 0)
	{
		if ((*data)->sidedistx < (*data)->sidedisty)
		{
			(*data)->sidedistx += (*data)->deltadistx;
			(*data)->mapx += (*data)->stepx;
			(*data)->side = 0;
		}
		else
		{
			(*data)->sidedisty += (*data)->deltadisty;
			(*data)->mapy += (*data)->stepy;
			(*data)->side = 1;
		}
		if ((*data)->map[(*data)->mapx][(*data)->mapy] == '1')
			(*data)->hit = 1;
	}
}

void	pass_to_3d(t_data *ray)
{
	int	j;
	int	i;

	j = -1;
	ray->drawend = HEIGHTSCREEN - ray->drawstart;
	i = ray->drawend;
	while (++j < ray->drawstart)
		ray->addr[j * ray->line_length / 4 + ray->x] = ray->ceiling_color;
	if (j <= ray->drawend)
		draw_texture(ray);
	j = i;
	while (++j < HEIGHTSCREEN)
		ray->addr[j * ray->line_length / 4 + ray->x] = ray->floor_color;
}

void	camera_rotation(t_data *data)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = (data)->planex;
	olddirx = (data)->dirx;
	if ((data)->rotate_right == 1)
	{
		(data)->dirx = (data)->dirx * cos(-(data)->rotspeed / 2)
			- (data)->diry * sin(-(data)->rotspeed / 2);
		(data)->diry = olddirx * sin(-(data)->rotspeed / 2)
			+ (data)->diry * cos(-(data)->rotspeed / 2);
		(data)->planex = (data)->planex * cos(-(data)->rotspeed / 2)
			- (data)->planey * sin(-(data)->rotspeed / 2);
		(data)->planey = oldplanx * sin(-(data)->rotspeed / 2)
			+ (data)->planey * cos(-(data)->rotspeed / 2);
	}
	view_left(data, olddirx);
}

void	back_and_forth(t_data *data)
{
	if (data->front == 1)
	{
		if (data->map[(int)(data->posx
				+ (data->dirx * data->movespeed * 2))][(int)data->posy] == '0')
			data->posx += data->dirx * data->movespeed;
		if (data->map[(int)(data->posx)][(int)(data->posy +
				(data->diry * data->movespeed * 2))] == '0')
			data->posy += data->diry * data->movespeed;
	}
	if (data->back == 1)
	{
		if (data->map[(int)(data->posx
				- (data->dirx * data->movespeed * 2))]
				[(int)(data->posy)] == '0')
			data->posx -= data->dirx * data->movespeed;
		if (data->map[(int)(data->posx)][(int)(data->posy -
					(data->diry * data->movespeed * 2))] == '0')
			data->posy -= data->diry * data->movespeed;
	}
}

void	move_left_right(t_data *data)
{
	if (data->right == 1)
	{
		if (data->map[(int)(data->posx + data->diry
				* (data->movespeed * 2))][(int)data->posy] == '0')
			data->posx += data->diry * data->movespeed;
		if (data->map[(int)data->posx][(int)(data->posy
			- data->dirx * (data->movespeed * 2))] == '0')
			data->posy -= data->dirx * data->movespeed;
	}
	if (data->left == 1)
	{
		if (data->map[(int)(data->posx - data->diry
				* (data->movespeed * 2))][(int)data->posy] == '0')
			data->posx -= data->diry * data->movespeed;
		if (data->map[(int)data->posx][(int)(data->posy
			+ data->dirx * (data->movespeed * 2))] == '0')
			data->posy += data->dirx * data->movespeed;
	}
}

int	draw(t_data *data)
{
	data->x = -1;
	while (++data->x < WIDTHSCREEN)
	{
		init_data(data);
		data->camerax = 2 * data->x / (double)WIDTHSCREEN - 1;
		data->raydirx = data->dirx + data->planex * data->camerax;
		data->raydiry = data->diry + data->planey * data->camerax;
		ft_init_raycast(&data);
		init_step_and_sidedist(&data);
		data->rayposx = data->posx;
		data->rayposy = data->posy;
		data->side = 0;
		find_wall(&data);
		data->hit = 0;
		pass_to_3d(data);
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
	camera_rotation(data);
	back_and_forth(data);
	move_left_right(data);
	return (0);
}