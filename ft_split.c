/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/08 17:46:13 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_wds;
	int		i;

	i = 0;
	nb_wds = ft_cntwds((char *)s, (char)c);
	tab = (char **)ft_calloc(nb_wds, sizeof(*tab));
	if (!tab || !s)
		return (NULL);
	while (ft_ischarset(*s, (char const *)&c))
		s++;
	while (i < nb_wds)
	{
		tab[i] = ft_strshift(s, (char const *)&c);
		if (!tab[i])
		{
			while (i-- > 0)
				free(tab[i]);
			free(tab);
			return (NULL);
		}
		while (!ft_ischarset(*s, (char const *)&c))
			s++;
		while (ft_ischarset(*s, (char const *)&c))
			s++;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
