/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 10:45:05 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/31 17:49:58 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_dst;
	size_t len_src;
/*	size_t i;
	size_t ret;*/

	len_dst = ft_strlen(dst);
	len_src = ft_strlcpy((dst + len_dst), src, size);
/*	len_src = ft_strlen(src);
	i = 0;
	if (!dst)
		len_dst = size;
	ret = len_dst + len_src;
	while (*src && size--)
		dst[len_dst++] = *src++;*/
		/*dst[len_dst + i++] = *src++;*/
/*	dst[len_dst] = '\0';*/
/*	return (ret);*/
	return (len_dst + len_src);
}
