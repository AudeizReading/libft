/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:27:54 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/22 15:04:25 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wdscnt(char const *s, char c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_wdlen(int *offset_i, int *offset_s, char const *s, char c)
{
	static int	i = 0;

	if ((size_t)i > (ft_strlen(s) - 2))
		i = 0;
	while (s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		if (s[i] != c && (s[i - 1] == c || i - 1 < 0))
			*offset_i = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			*offset_s = i;
		i++;
	}
	while (s[i] == c)
		i++;
	return (*offset_s - *offset_i + 1);
}

static int	ft_isfree(char **tab, int index)
{
	if (!tab[index])
	{
		while (index >= 0)
			free(tab[index--]);
		free(tab);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char **dst;
	int i;
	int offset_i;
	int offset_s;
	int nb;

	if (!s)
		return (NULL);
	i = 0;
	offset_i = 0;
	offset_s = 0;
	nb = ft_wdscnt(s, c);
	dst = (char **)malloc(sizeof(*dst) * (nb + 1));
	if (!dst)
		return (NULL);
	while (i < nb)
	{
		dst[i] = (char *)ft_calloc(sizeof(**dst), (ft_wdlen(&offset_i, &offset_s, s, c) + 1));
		if (ft_isfree(dst, i))
			return (NULL);
		ft_memcpy(dst[i++], s + offset_i, offset_s - offset_i + 1);
	}
	dst[i] = NULL;
	return (dst);
}
