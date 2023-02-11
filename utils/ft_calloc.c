/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:21:21 by jecolmou          #+#    #+#             */
/*   Updated: 2022/11/30 18:22:12 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;
	int		i;

	i = 0;
	s = malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size * count);
	return (s);
}
