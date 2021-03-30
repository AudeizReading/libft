/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 11:19:33 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/30 17:24:14 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	if (!len || !*s1)
		return ((char *)0);
	while (--len && s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j) <= len)
		{
			if (!s2[j + 1])
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return ((char *)0);
}
