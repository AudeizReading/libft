/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/19 10:19:32 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strtotab(char **tab, int i, char const *s, char c)
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
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
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
	return (tab);
}
