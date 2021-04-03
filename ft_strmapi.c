/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 22:47:50 by alellouc          #+#    #+#             */
/*   Updated: 2021/04/03 22:53:35 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len_s;
	char	*dst;

	len_s = ft_strlen(s);
	dst = (char *)malloc((len_s + 1) * sizeof(*dst));
	if (dst == NULL)
		return (NULL);
	dst[len_s] = 0;
	while (len_s--)
		dst[len_s] = (*f)(len_s, s[len_s]);
	return (dst);
}
