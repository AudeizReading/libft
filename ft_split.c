/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/21 12:03:32 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	*ft_strtotab(char **tab, int i, char const *s, char c)
{
	tab[i] = ft_strshift(s, (char const *)&c);
	if (!tab[i])
	{
		while (i >= 0)
			free(tab[i--]);
		free(tab);
		return (NULL);
	}
	return (*(tab + i));
}*/

char	**ft_split(char const *s, char c)
{
	/*char	**tab;
	int		nb_wds;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_wds = ft_cntwds((char *)s, (char)c);
	tab = (char **)ft_calloc(nb_wds + 1, sizeof(*tab));
	if (!tab)
		return (NULL);
	ft_nextstr(&s, (char const *)&c, nb_wds);
	while (i < nb_wds)
	{
		tab[i] = ft_strtotab(tab, i, s, c);
		if (tab[i] == NULL)
			return (NULL);
		ft_nextcharset(&s, (char const *)&c, nb_wds);
		ft_nextstr(&s, (char const *)&c, nb_wds);
		i++;
	}
	tab[i] = NULL;
	return (tab);*/

	/* ---------------------------------------------------------------------- */
	char	**dst;
	int		h;
	int		i;
	int		j;
	int		k;
	int		m;
	int		nb;

	h = 0;
	i = 0;
	j = 0;
	k = 0;
	m = 0;
	nb = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			nb++;
		i++;
	}
	i = 0;
	dst = (char**)malloc((nb + 1) * sizeof(*dst));
	if (!dst)
		return (NULL);
	while (i < nb)
	{
		while (s[j] == c)
			j++;
		while (s[j] && s[j] != c)
		{
			if (s[j] != c && (s[j - 1] == c || j - 1 < 0))
				k = j;
			if (s[j] != c && (s[j + 1] == c || s[j + 1] == 0))
				m = j;
			j++;
		}
		dst[i] = (char *)malloc(sizeof(**dst) * (m - k + 2));
		if (!dst[i])
		{
			while (i >= 0)
				free(dst[i--]);
			free(dst);
			return (NULL);
		}
		h = 0;
		while (k <= m)
		{
			dst[i][h++] = s[k++];
		}
		dst[i++][h] = 0;
	}
	dst[i] = NULL;
	return (dst);
}
