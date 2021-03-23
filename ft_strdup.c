/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:33:15 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/23 15:50:34 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len_s1;
	char	*dest;
	int		i;

	len_s1 = ft_strlen(s1);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len_s1 + 1));
	if (dest == 0)
	{
		errno = ENOMEM;
		return ((char *)0);
	}
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
