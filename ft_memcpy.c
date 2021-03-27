/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:52:25 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/27 17:13:04 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p_dst;
	unsigned const char	*p_src;
	
	p_dst = (unsigned char *)dst;
	p_src = (const unsigned char *)src;
	while (n)
	{
		*p_dst++ = *p_src++;
		n--;
	}
	return (dst);
}
