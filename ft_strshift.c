/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:39:21 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/08 10:39:44 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strshift(char const *s1, char const *set)
{
	char	*dst;
	size_t	start;
	size_t	len_dst;

	start = 0;
	len_dst = 0;
	if (!*set || !*s1)
		len_dst = ft_strlen(s1);
	else
	{
		while (ft_ischarset(s1[start], set))
			start++;
		while (s1[start + len_dst] && !ft_ischarset(s1[start + len_dst], set))
			len_dst++;
	}
	dst = ft_substr(s1, start, len_dst);
	if (!dst)
		return (NULL);
	return (dst);
}
