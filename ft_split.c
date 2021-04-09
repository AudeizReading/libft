/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/09 13:11:16 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_wds;
	int		i;

	ft_putendl_fd("\n=======================================", 1);
	/*ft_putstr_fd("Chaine a split: ", 1);
	ft_putendl_fd((char *)s, 1);*/
	i = 0;
	if (!c)
	{
		ft_putendl_fd("Pas de separateur", 1);
		nb_wds = 1;
	}
	if (!s)
	{
		ft_putendl_fd("Pas de chaine", 1);
		nb_wds = 0;
	}
	else
		nb_wds = ft_cntwds((char *)s, (char)c);
/*	ft_putendl_fd("Nb de mots trouves:", 1);
	ft_putnbr_fd(nb_wds, 1);
	ft_putchar_fd('\n', 1);*/
	tab = (char **)ft_calloc(nb_wds + 1, sizeof(*tab));
	if (!tab)
		return (NULL);
	if (nb_wds > 1)
 &&	{
	while (ft_ischarset(*s, (char const *)&c))
		s++;
	}
	/*ft_putendl_fd("Check valeur de s, avant assignation de tab:", 1);
	ft_putendl_fd((char *)s, 1);*/
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
	/*	ft_putnbr_fd(i, 1);
		ft_putstr_fd(" : ", 1);
		ft_putendl_fd(tab[i], 1);
		ft_putchar_fd('\n', 1);*/
		if (nb_wds > 1)
		{
		while (!ft_ischarset(*s, (char const *)&c))
			s++;
	/*	ft_putendl_fd("Check valeur de s, apres assignation:", 1);
		ft_putendl_fd((char *)s, 1);*/
		while (ft_ischarset(*s, (char const *)&c))
			s++;
	/*	ft_putendl_fd("Check valeur de s, apres assignation:", 1);
		ft_putendl_fd((char *)s, 1);*/
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
