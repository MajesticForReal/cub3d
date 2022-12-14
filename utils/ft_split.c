/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecolmou <jecolmou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:32:50 by jecolmou          #+#    #+#             */
/*   Updated: 2022/12/10 15:09:05 by jecolmou         ###   ########.fr       */
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

char	**ft_split(char const *s, char c, t_data *x)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	tab = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!tab || !s)
		return (NULL);
	while (++i < ft_count_word(s, c))
	{
		j = 0;
		tab[i] = malloc((x->len + 1) * sizeof(char));
		if (tab[i] == NULL)
			free_split(tab, i);
		while (s[k] == c && s[k])
			k++;
		while (s[k] != c && s[k])
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
