/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchane <souchane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:30:05 by souchane          #+#    #+#             */
/*   Updated: 2024/02/26 18:39:52 by souchane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_words(char *s, char c)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	y = 0;
	z = 0;
	while (s[x])
	{
		y = 0;
		while (s[x] && s[x] == c)
			x++;
		while (s[x] && s[x] != c)
		{
			x++;
			y++;
		}
		if (y > 0)
			z++;
	}
	return (z);
}

static int	get_lenght(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free(char **tab, int y)
{
	y--;
	while (y >= 0)
	{
		free(tab[y]);
		y--;
	}
	free(tab);
	return (NULL);
}

static char	**ft_fun(char *s, char c, char **tab)
{
	int		x;
	int		y;
	int		z;

	x = 0;
	y = 0;
	while (s[x] != '\0')
	{
		z = 0;
		while (s[x] && s[x] == c)
			x++;
		if (s[x])
		{
			tab[y] = malloc(sizeof(char) * (get_lenght((char *)s + x, c) + 1));
			if (!tab[y])
				return (ft_free(tab, y));
			while (s[x] && s[x] != c)
				tab[y][z++] = s[x++];
			tab[y][z] = '\0';
			y++;
		}
	}
	tab[y] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	char	**tab;

	if (!s)
		return (0);
	t = malloc(sizeof(char *) * (get_words((char *)s, c) + 1));
	if (!t)
		return (0);
	tab = ft_fun((char *)s, c, t);
	return (tab);
}
