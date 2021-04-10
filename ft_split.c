/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/10 19:53:55 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_wds;
	int		i;

	i = 0;
	/*if (s == NULL)
		return (NULL);*/
	if (!c)
		nb_wds = 1;
	if (!s)
		return (NULL);
		/*nb_wds = 0;*/
	else
		nb_wds = ft_cntwds((char *)s, (char)c);
	tab = (char **)ft_calloc(nb_wds + 1, sizeof(*tab));
	if (!tab)
		return (NULL);
	if (nb_wds > 1)
		while (ft_ischarset(*s, (char const *)&c))
			s++;
	while (i < nb_wds)
	{
		tab[i] = ft_strshift(s, (char const *)&c);
		if (!tab[i])
		{
			while (i >= 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		if (nb_wds > 1)
		{
			while (!ft_ischarset(*s, (char const *)&c))
				s++;
			while (ft_ischarset(*s, (char const *)&c))
				s++;
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
