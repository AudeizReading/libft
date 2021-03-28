/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:52:23 by alellouc          #+#    #+#             */
/*   Updated: 2021/03/28 20:25:35 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*buffer;

	buffer = malloc(size * count);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, size * count);
	return ((void *)buffer);
}
