/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anrechai <anrechai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:24:55 by anrechai          #+#    #+#             */
/*   Updated: 2022/12/19 17:24:55 by anrechai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	which_texture(t_data *data, int *side)
{
	if (data->side == 0)
	{
		if (data->raydirx > 0)
			*side = 0;
		else
			*side = 1;
	}
	else
	{
		if (data->raydiry > 0)
			*side = 2;
		else
			*side = 3;
	}
}

void	calculate_texture(t_data *data)
{
	if (data->side == 0)
		data->wallx = data->posy + data->perpwalldist * data->raydiry;
	else
		data->wallx = data->posx + data->perpwalldist * data->raydirx;
	data->wallx -= floor((data->wallx));
	data->texx = (int)(data->wallx * (double)data->texture_width);
	if ((data->side == 0 && data->raydirx > 0)
		|| (data->side == 1 && data->raydiry < 0))
		data->texx = data->texture_width - data->texx - 1;
	data->step = 1.0 * data->texture_height / data->lineheight;
	data->texpos = (data->drawstart - 1440 / 2
			+ data->lineheight / 2) * data->step;
}

void	display_texture(t_data *data, int y, int x, int i)
{
	data->addr[y * data->size_line / 4 + x]
		= data->imgdata[i].addr[data->texy
		* data->imgdata[i].size_line / 4 + data->texx];
}

void	draw_texture(t_data *data)
{
	int	i;
	int	i_tex;

	i = data->drawstart - 1;
	data->drawend = 1440 - data->drawstart;
	calculate_texture(data);
	i_tex = 0;
	which_texture(data, &i_tex);
	while (++i <= data->drawend)
	{
		data->texy = (int)data->texpos & (data->texture_height - 1);
		data->texpos += data->step;
		display_texture(data, i, data->x, i_tex);
	}
}
