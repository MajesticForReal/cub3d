/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:57:12 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/14 17:04:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	x;

	ft_bzero(&x, sizeof(x));
	x.file = 0;
	if (ft_check_argv(argc, argv) == 1)
		return (1);
	if (ft_open_map(argv, &x) == 1)
		return (1);
	// RECUPERER INFO MAP -> FAIRE FONCTION GET_INFO QUI DOIT RECUPERER LES INFO DE LA MAP DONC LES COULEURS A METTRE DANS NOTRE STRUCTURE GENRE data->floor POUR LE SOL ET data->ceiling POUR LE PLAFOND
	// PUIS RECUPERER LES COULEURS DE CES INT RGB data->RGB[0] = atoi du premier nombre en question etc
	// Il FAUT AUSSI RECUPERER LES PATHS DE NOS IMAGES DONC UN NOUVEAU TAB AVEC LES INFOS DU DEBUT DE MAP DONC 1ere LIGNE DU TABLEAU LE PATH DE NO DEUXIEME LIGNE LE PATH DE SO
	// TROISIEME LIGNE WE ET QUATRIEME EA data->mappath par exemple
	new_window(data);
	// INIT TOUTES LES VARIABLES NECESSAIRES AU JEU A 0 + DIRECTION
	data.img = mlx_new_image(data.mlx_ptr, WIDTHSCREEN, HEIGHTSCREEN);
	data.addr = (int *)mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	return (0);
}
