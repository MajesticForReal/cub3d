/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:32:50 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/20 22:18:51 by jecolmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

char	**free_split(char **str, int count)
{
	while (0 <= count)
	{
		free(str[count]);
		count--;
	}
	free(str);
	return (NULL);
}

void	ft_split_n_error(t_data *x, char **tab, int i, char *s)
{
	if (s[x->v] == '\n' && s[x->v + 1] == '\n')
	{
		x->count_n++;
		if (x->count_n > 2)
		{
			ft_putstr_fd("Error : Map is not good\n", 2);
			free_split(tab, i);
			free(s);
			exit (0);
		}
	}
}

void	ft_loop_split(char **tab, char *s, char c, t_data *x)
{
	while (++x->y < ft_count_word(s, c))
	{
		x->z = 0;
		tab[x->y] = malloc((x->len) * sizeof(char));
		if (tab[x->y] == NULL)
			free_split(tab, x->y);
		while (s[x->v] == c && s[x->v])
		{
			ft_split_n_error(x, tab, x->y, s);
			x->v++;
		}
		while (s[x->v] != c && s[x->v])
			tab[x->y][x->z++] = s[x->v++];
		while (x->z < x->len - 1)
		{
			tab[x->y][x->z] = ' ';
			x->z++;
		}
		tab[x->y][x->z] = '\0';
	}
}

char	**ft_split(char *s, char c, t_data *x)
{
	char	**tab;

	x->y = -1;
	x->v = 0;
	tab = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!tab || !s)
		return (NULL);
	ft_loop_split(tab, s, c, x);
	tab[x->y] = NULL;
	return (tab);
}
