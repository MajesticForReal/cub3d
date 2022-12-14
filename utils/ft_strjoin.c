
#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	final = malloc(sizeof(char) * ((ft_strlen(s1) + (ft_strlen(s2))) + 1));
	if (final == NULL)
		return (NULL);
	while (s1[++i])
		final[i] = s1[i];
	while (s2[j])
	{
		final[i] = s2[j];
		j++;
		i++;
	}
	final[i] = '\0';
	return (final);
}